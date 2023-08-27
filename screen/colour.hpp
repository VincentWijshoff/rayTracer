#ifndef COLOUR_H
#define COLOUR_H

#include <iostream>

class Colour {
private:
    uint8_t R;
    uint8_t G;
    uint8_t B;
public:
    // Constructors
    Colour(uint8_t R, uint8_t G, uint8_t B);

    // Getter functions
    uint8_t getR() const;
    uint8_t getG() const;
    uint8_t getB() const;
    
    friend std::ostream& operator<<(std::ostream& os, const Colour& vp);
};

#endif