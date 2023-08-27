#ifndef POINT3D_H
#define POINT3D_H

#include "vector.hpp"
#include <iostream>

class Point3D {
private:
    double x;
    double y;
    double z;

public:
    // Constructors
    Point3D();
    Point3D(double xVal, double yVal, double zVal);

    // Getter functions
    double getX() const;
    double getY() const;
    double getZ() const;

    // Setter functions
    void setX(double xVal);
    void setY(double yVal);
    void setZ(double zVal);

    // operations

    // p1 - p2
    Vector3D operator-(const Point3D& other) const;

    // p + v
    Point3D operator+(const Vector3D& other) const;
    
    friend std::ostream& operator<<(std::ostream& os, const Point3D& point);
};

#endif