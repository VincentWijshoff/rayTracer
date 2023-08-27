#include "visualengine.hpp"
#include <SFML/Graphics.hpp>
#include "../helper/point.hpp"
#include "camera.hpp"
#include "viewplane.hpp"
#include "colour.hpp"
#include "../engine/ray.hpp"
#include "../engine/tracer.hpp"
#include <thread>
#include <vector>
#include <mutex>


void VisualEngine::threadedFunction
    (const int i, 
    Vector3D tmp,
    std::mutex& mtx) {
        for (int j = 0; j < VIRRES; j++) {
            Vector3D dir = 
                tmp + (camera.getv() * viewplane.getY(j));
            Ray r(eyepoint, dir/dir.magnitude());
            Colour* colour = tracer.trace(r);
            mtx.lock();
            this->setColour(i, j, colour); 
            mtx.unlock();
        }
}

VisualEngine::VisualEngine() :
    RES(600),
    eyepoint(200, 0.0, 0.0), 
    lookat(0.0, 0.0, 0.0), 
    distance(50),
    camera(eyepoint, lookat, distance), 
    VIRRES(600),
    viewplane(VIRRES, VIRRES, pixelsize),
    tracer(),
    arr()
{
    sf::RenderWindow window = sf::RenderWindow{ { RES, RES }, "Raytracer" };
    window.setFramerateLimit(144);
    window.clear(sf::Color::Black);

    Vector3D tmpfin = camera.getw() * camera.getd();

    const int numThreads = VIRRES*VIRRES;
    std::vector<std::thread> threads;

    std::mutex mtx;

    initiateArray();
    
    for (int i = 0; i < VIRRES; i++) {
        Vector3D tmp = (camera.getu() * viewplane.getX(i)) - tmpfin;
        threads.emplace_back([this, i, tmp, &mtx]() {
            this->threadedFunction(i, tmp, std::ref(mtx));
        });
    }
    // wait for threads
    for (auto& thread : threads) {
        thread.join();
    }
    
    // draw all results
    drawResults(window);
    
    // display results
    window.display();

    deleteArray();

    // wait for program to end
    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
    }
}

std::ostream& operator<<(std::ostream& os, const VisualEngine& ve) {
    os << "res: " << ve.RES << std::endl;
    return os;
}