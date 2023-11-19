#ifndef ELLIPSE_H
#define ELLIPSE_H

#ifdef ELLIPSEPLUGIN_EXPORTS
#define ELLIPSE_API _declspec(dllexport)
#else
#define ELLIPSE_API _declspec(dllimport)
#endif

#include "Curve.h"

class ELLIPSE_API Ellipse : public Curve
{
private:
    double a, b;
public:
    Ellipse(double first, double second) : a(first), b(second) {}
    Point_3D get3dPoint(double t) const override;
    Vector_3D getFirstDerivative(double t) const override;
    void Show(const Curve* const ellipse, double t) const override;
};

#endif //ELLIPSE_H