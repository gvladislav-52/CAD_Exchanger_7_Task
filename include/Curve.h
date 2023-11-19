#ifndef CURVE_H
#define CURVE_H

#include <iostream>
#include <cmath>
#include <vector>
#include <time.h>

class Curve
{
public:
    struct Point_3D
    {
        double x, y, z;
    };
    struct Vector_3D
    {
        double x, y, z;
    };
    virtual Point_3D get3dPoint(double) const = 0;
    virtual Vector_3D getFirstDerivative(double) const = 0;
    virtual void Show(const Curve* const, double t) const = 0;
    virtual ~Curve() {}
};

#endif //CURVE_H
