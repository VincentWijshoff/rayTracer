#include "objecthandler.hpp"
#include "circle.hpp"
#include "../helper/point.hpp"

Objecthandler::Objecthandler() {
    Point3D* p = new Point3D(0.0, 0.0, 0.0);
    Colour* col = new Colour(255, 0, 0);
    Circle* c = new Circle(*p, 100, col);
    objects.push_back(c);
    Point3D* p1 = new Point3D(0.0, 300.0, 300.0);
    lightSources.push_back(p1);
    // Colour* col1 = new Colour(255, 255, 0);
    // Circle* c1 = new Circle(*p1, 100, col1);
    // objects.push_back(c1);
}

std::vector<Object*> Objecthandler::getObjects() const {
    return objects;
}