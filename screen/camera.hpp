#ifndef CAMERA_H
#define CAMERA_H
// define projection point e as the eye point
// define the look at point l, the direction the camera will be facing
// define the y viewing direction as y = l - e (from eye point to looking direction)
// define w = (e - l) / ||e - l|| going out the back of the camera and normalised
// define the up-vector = (0, 1, 0)
// define u = up x w / ||up x w|| to the right of the camera
// define v = w x u as the upwards directino of the camera
// need a distance d between eye point and window
#include "../helper/vector.hpp"
#include "../helper/point.hpp"
#include <iostream>

class Camera {
private:
    Point3D e;      // eye point
    Point3D l;      // look at point
    Vector3D y;     // viewing direction
    Vector3D w;     // reverse viewing direction
    Vector3D up;    // vector always up
    Vector3D u;     // right from camera
    Vector3D v;     // up from camera
    double d;       // distance between eye point and view plane
public:
    Camera(Point3D eyePoint, Point3D lookAtPoint, double distance);

    // Getter functions
    Point3D gete() const;
    Point3D getl() const;
    Vector3D gety() const;
    Vector3D getw() const;
    Vector3D getup() const;
    Vector3D getu() const;
    Vector3D getv() const;
    double getd() const;

    friend std::ostream& operator<<(std::ostream& os, const Camera& point);
};

#endif