#include "colour.hpp"

Colour::Colour(uint8_t R, uint8_t G, uint8_t B) : R(R), G(G), B(B) {}

uint8_t Colour::getR() const {return R;}
uint8_t Colour::getG() const {return G;}
uint8_t Colour::getB() const {return B;}

std::ostream& operator<<(std::ostream& os, const Colour& c) {
    os << "(" << unsigned(c.R) << ", " << unsigned(c.G) << ", " << unsigned(c.B) << ")";
    return os;
}
