#ifndef TRACER_H
#define TRACER_H

#include "../screen/colour.hpp"
#include "ray.hpp"
#include "../objects/objecthandler.hpp"

class Tracer {
private:
    Objecthandler o;
    Colour* base = new Colour(0, 0, 0);
public:
    // Constructors
    Tracer();

    Colour* trace(Ray& ray) const;
};

#endif
