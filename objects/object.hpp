#ifndef OBJECT_H
#define OBJECT_H

#include <optional>
#include "../engine/ray.hpp"
#include "../helper/point.hpp"
#include "../screen/colour.hpp"

class Object {
private:
    Colour* colour;
public:
    Object(Colour* c);
    virtual std::optional<Point3D> intersect(Ray& ray) const = 0;
    Colour* getColour() const;

};

#endif