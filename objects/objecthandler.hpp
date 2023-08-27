#ifndef OBJECTHANDLER_H
#define OBJECTHANDLER_H

#include <vector>
#include "object.hpp"
#include "./helper/point.hpp"

class Objecthandler {
private:

std::vector<Object*> objects = {};
std::vector<Point3D*> lightSources = {};

public:
    Objecthandler();

    std::vector<Object*> getObjects() const;
};

#endif