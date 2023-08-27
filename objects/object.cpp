#include "object.hpp"

Object::Object(Colour* c) : colour(c) {}

Colour* Object::getColour() const {
    return colour;
}