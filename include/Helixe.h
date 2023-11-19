#ifndef HELIXE_H
#define HELIXE_H

#ifdef HELIXEPLUGIN_EXPORTS
#define HELIXE_API _declspec(dllexport)
#else
#define HELIXE_API _declspec(dllimport)
#endif

#include "Curve.h"

class HELIXE_API Helixe :public Curve
{
private:
    double radius;
    double height;
public:
    Helixe(double radius_temp, double height_temp) :radius(radius_temp), height(height_temp) {}
    Point_3D get3dPoint(double t) const override;
    Vector_3D getFirstDerivative(double t) const override;
    void Show(const Curve* const helixe, double t) const override;
};

#endif //HELIXE_H