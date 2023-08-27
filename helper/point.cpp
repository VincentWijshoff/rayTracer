#include "point.hpp"

Point3D::Point3D() : x(0.0), y(0.0), z(0.0) {}

Point3D::Point3D(double xVal, double yVal, double zVal) : x(xVal), y(yVal), z(zVal) {}

double Point3D::getX() const { return x; }
double Point3D::getY() const { return y; }
double Point3D::getZ() const { return z; }

void Point3D::setX(double xVal) { x = xVal; }
void Point3D::setY(double yVal) { y = yVal; }
void Point3D::setZ(double zVal) { z = zVal; }

Vector3D Point3D::operator-(const Point3D& other) const {
    double newX = x - other.x;
    double newY = y - other.y;
    double newZ = z - other.z;
    return Vector3D(newX, newY, newZ);
}

Point3D Point3D::operator+(const Vector3D& other) const {
    return Point3D(x + other.getX(), y + other.getY(), z + other.getZ());
}

std::ostream& operator<<(std::ostream& os, const Point3D& point) {
    os << "(" << point.x << ", " << point.y << ", " << point.z << ")";
    return os;
}
