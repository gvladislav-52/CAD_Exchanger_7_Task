#ifndef CIRCLE_H
#define CIRCLE_H

#include "Curve.h"
class Circle : public Curve
{
private:
    double radius;
public:
    Circle(double r) :radius(r) {}
    Point_3D get3dPoint(double t) const override;
    Vector_3D getFirstDerivative(double t) const override;
    void Show(const Curve* const circle, double t) const override;
    bool operator<(const Circle& other) const { return radius < other.radius; }
    double getRadius() { return radius; }
};

#endif //CURVE_H