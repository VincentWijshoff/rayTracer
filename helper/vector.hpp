#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <iostream>
#include <cmath>

class Vector3D {
private:
    double x;
    double y;
    double z;

public:
    // Constructors
    Vector3D();
    Vector3D(double xVal, double yVal, double zVal);

    // Getter functions
    double getX() const;
    double getY() const;
    double getZ() const;

    // Setter functions
    void setX(double xVal);
    void setY(double yVal);
    void setZ(double zVal);

    // operations

    // ||v||
    double magnitude() const;

    // dot product
    double dotProduct(Vector3D vec) const;

    // length squared
    double lengthSquared() const;

    // division
    Vector3D operator/(double scalar) const;

    // v1 x v2
    Vector3D operator*(const Vector3D& other) const;

    // v1 x d
    Vector3D operator*(const double& other) const;

    // v1 + v1
    Vector3D operator+(const Vector3D& other) const;

    // v1 - v2
    Vector3D operator-(const Vector3D& other) const;
    
    friend std::ostream& operator<<(std::ostream& os, const Vector3D& vec);
};

#endif