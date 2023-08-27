#ifndef VIEWPLANE_H
#define VIEWPLANE_H

#include <iostream>

class Viewplane {
private:
    double hres;
    double vres;
    double pixelSize;
    double hres2 = 0.5 - hres/2;
    double vres2 = 0.5 - vres/2;
public:
    // Constructors
    Viewplane(double hres, double vres, double pixelsize);

    // Getter functions
    double getHres() const;
    double getVres() const;
    double getPixelSize() const;

    // Setter functions
    void setHres(double hResVal);
    void setVres(double vResVal);
    void setPixelSize(double vResVal);

    // operations
    // columns and rows are counted from the bottom left
    // x and y coordinates are counted from the middle of the viewplane
    //get the x-coordinate of the given index of the column
    double getX(int column) const;
    //get the y-coordinate of the given index of the row
    double getY(int row) const;
    
    friend std::ostream& operator<<(std::ostream& os, const Viewplane& vp);
};

#endif