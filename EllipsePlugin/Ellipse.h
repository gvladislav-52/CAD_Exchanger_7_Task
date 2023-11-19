#ifndef ELLIPS_H
#define ELLIPS_H

#include "Curve.h"

class Ellips : public Curve
{
private:
    double a, b;
public:
    Ellips(double first, double second) : a(first), b(second) {}
    Point_3D get3dPoint(double t) const override;
    Vector_3D getFirstDerivative(double t) const override;
    void Show(const Curve* const ellipse, double t) const override;
};

#endif //ELLIPS_H