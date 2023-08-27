#include "camera.hpp"

Camera::Camera(Point3D eyePoint, Point3D lookAtPoint, double distance) : 
    e(eyePoint),
    l(lookAtPoint),
    y(l-e),
    w((e-l)/(e-l).magnitude()),
    up(Vector3D(0.0, 1.0, 0.0)),
    u((up*w)/(up*w).magnitude()),
    v(w*u),
    d(distance) {}

Point3D Camera::gete() const { return e; }
Point3D Camera::getl() const { return l; }
Vector3D Camera::gety() const { return y; }
Vector3D Camera::getw() const { return w; }
Vector3D Camera::getup() const { return up; }
Vector3D Camera::getu() const { return u; }
Vector3D Camera::getv() const { return v; }
double Camera::getd() const { return d; }

std::ostream& operator<<(std::ostream& os, const Camera& camera) {
    os << "eye point: " << camera.e << std::endl;
    os << "look at point: " << camera.l << std::endl;
    os << "viewing direction: " << camera.y << std::endl;
    os << "reverse viewing direction (w): " << camera.w << std::endl;
    os << "up vector: " << camera.up << std::endl;
    os << "right vector (u): " << camera.u << std::endl;
    os << "vector up (v): " << camera.v << std::endl;
    os << "distance: " << camera.d << std::endl;
    return os;
}