#ifndef CIRCLE_H
#define CIRCLE_H

#include "../helper/point.hpp"
#include "../helper/vector.hpp"
#include "object.hpp"
#include "../screen/colour.hpp"

class Circle : public Object {
private:
    const Point3D origin;
    const double radius;
public:
    // constructor
    Circle(Point3D o, double r, Colour* c);

    Point3D getOrigin() const;
    double getRadius() const;

    std::optional<Point3D> Circle::intersect(Ray& ray) const override {
        Vector3D oc = ray.getStart()-origin;
        double a = ray.getDirection().dotProduct(ray.getDirection());
        double b = 2.0 * ray.getDirection().dotProduct(oc);
        double c = oc.dotProduct(oc) - (radius*radius);
        double D = (b*b) - (4 * a * c);
        if ( D < 0) {
            return std::nullopt;
        }
        double t1 = (-b + std::sqrt(D)) / (2.0 * a);
        double t2 = (-b - std::sqrt(D)) / (2.0 * a);

        // Find the closer intersection point
        double t = std::min(t1, t2);

        Point3D intersection = ray.getStart() + ray.getDirection() * t;
        return intersection;
    }
    
};

#endif