#ifndef VISUALENGINE_H
#define VISUALENGINE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "camera.hpp"
#include "viewplane.hpp"
#include "../helper/point.hpp"
#include "colour.hpp"
#include "../engine/tracer.hpp"
#include <mutex>

class VisualEngine {
private:
    // physical window propperties
    const unsigned int RES;

    // Virtual elements
    const Point3D eyepoint;
    const Point3D lookat;
    const double distance;
    const Camera camera;

    const int VIRRES;
    const double pixelsize = RES/VIRRES;
    const Viewplane viewplane;

    const Tracer tracer;

    Colour*** arr;

public:
    // Constructors
    VisualEngine();

    const void colourArea(sf::RenderWindow& window, const int i, const int j, Colour* c) const {
        sf::RectangleShape rect(sf::Vector2f(static_cast<float>(pixelsize), static_cast<float>(pixelsize)));
        rect.setPosition(static_cast<float>(i*pixelsize), static_cast<float>(j*pixelsize));
        sf::Color color(c->getR(), c->getG(), c->getB());
        rect.setFillColor(color);
        window.draw(rect);
    }

    const void initiateArray() {
        arr = new Colour**[VIRRES];
        for (int i = 0; i < VIRRES; ++i)
        {
            arr[i] = new Colour*[VIRRES];
            for (int j = 0; j < VIRRES; ++j)
            {
                arr[i][j] = nullptr; // Initialize each element to null pointer
            }
        }
    }

    const void deleteArray() {
        for (int i = 0; i < VIRRES; ++i)
        {
            for (int j = 0; j < VIRRES; ++j)
            {
                arr[i][j] = nullptr;
            }
            delete[] arr[i];
        }
        delete[] arr;
    }

    const void setColour(const int i, const int j, Colour* c) {
        arr[i][j] = c;
    }

    const void drawResults(sf::RenderWindow& window) {
        for (int i = 0; i < VIRRES; i++) {
            for (int j = 0; j < VIRRES; j++) {
                colourArea(window, i, j, arr[i][j]);
            }
        }
    }

    void threadedFunction(const int i, Vector3D tmp, std::mutex& mtx);
    
    friend std::ostream& operator<<(std::ostream& os, const VisualEngine& vp);
};

#endif