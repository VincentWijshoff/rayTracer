#ifndef RAY_H
#define RAY_H

#include <iostream>
#include "../helper/point.hpp"
#include "../helper/vector.hpp"

class Ray {
private:
    Point3D start;
    Vector3D direction;

public:
    // Constructors
    Ray(Point3D start, Vector3D direction);

    // Getter functions
    Point3D getStart() const;
    Vector3D getDirection() const;

    // Setter functions
    void setStart(Point3D st);
    void setDirection(Vector3D dir);
    
    friend std::ostream& operator<<(std::ostream& os, const Ray& vp);
};

#endif