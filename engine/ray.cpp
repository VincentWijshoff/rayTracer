#include "ray.hpp"

Ray::Ray(Point3D start, Vector3D direction) : start(start), direction(direction) {}

Point3D Ray::getStart() const {return start;}
Vector3D Ray::getDirection() const {return direction;}

void Ray::setStart(Point3D st) {start=st;}
void Ray::setDirection(Vector3D dr) {direction=dr;}

std::ostream& operator<<(std::ostream& os, const Ray& ray) {
    os << "startpoint: " << ray.start << std::endl;
    os << "direction: " << ray.direction << std::endl;
    return os;
}