#include "tracer.hpp"
#include "../objects/object.hpp"
#include <tuple>

Tracer::Tracer() : o() {}

Colour* Tracer::trace(Ray& ray) const {
    std::vector<std::tuple<Point3D, Colour*>> hitObjects = {};
    for (Object* obj : o.getObjects())
    {
        std::optional<Point3D> result = obj->intersect(ray);
        if (result.has_value()){
            std::tuple<Point3D, Colour*> tmp(result.value(), obj->getColour());
            hitObjects.push_back(tmp);
        }
    }
    double smallestDist = 999999999999999;
    Colour* bestColour = base;
    for (std::tuple<Point3D, Colour*> tpl : hitObjects)
    {
        double dist = (std::get<0>(tpl)-ray.getStart()).magnitude();
        if (dist < smallestDist) {
            smallestDist = dist;
            bestColour = std::get<1>(tpl);
        }
    }

    return bestColour;
}