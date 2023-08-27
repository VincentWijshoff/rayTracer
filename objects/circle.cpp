#include "circle.hpp"

Circle::Circle(Point3D o, double r, Colour* c) : origin(o), radius(r), Object(c) {}

Point3D Circle::getOrigin() const {
    return origin;
}

double Circle::getRadius() const{
    return radius;
}