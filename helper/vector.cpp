#include "vector.hpp"

Vector3D::Vector3D() : x(0.0), y(0.0), z(0.0) {}
Vector3D::Vector3D(double xVal, double yVal, double zVal) : x(xVal), y(yVal), z(zVal) {}

double Vector3D::getX() const { return x; }
double Vector3D::getY() const { return y; }
double Vector3D::getZ() const { return z; }

void Vector3D::setX(double xVal) { x = xVal; }
void Vector3D::setY(double yVal) { y = yVal; }
void Vector3D::setZ(double zVal) { z = zVal; }

double Vector3D::magnitude() const {
    return std::sqrt(x * x + y * y + z * z);
}

double Vector3D::dotProduct(Vector3D vec) const {
    return x*vec.x + y*vec.y + z*vec.z;
}

double Vector3D::lengthSquared() const {
    return x*x + y*y + z*z;
}

Vector3D Vector3D::operator/(double scalar) const {
    return Vector3D(x / scalar, y / scalar, z / scalar);
}

Vector3D Vector3D::operator*(const Vector3D& other) const {
    double newX = y * other.z - z * other.y;
    double newY = z * other.x - x * other.z;
    double newZ = x * other.y - y * other.x;
    return Vector3D(newX, newY, newZ);
}

Vector3D Vector3D::operator*(const double& other) const {
    return Vector3D(x * other, y * other, z * other);
}

Vector3D Vector3D::operator+(const Vector3D& other) const {
    return Vector3D(x + other.x, y + other.y, z + other.z);
}

Vector3D Vector3D::operator-(const Vector3D& other) const {
    return Vector3D(x - other.x, y - other.y, z - other.z);
}

std::ostream& operator<<(std::ostream& os, const Vector3D& vec) {
    os << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
    return os;
}