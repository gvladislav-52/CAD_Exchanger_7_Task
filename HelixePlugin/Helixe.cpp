#include "pch.h"

#include "Helixe.h"

Helixe::Point_3D Helixe::get3dPoint(double t) const
{
    Curve::Point_3D temp;
    temp.x = radius * cos(t);
    temp.y = radius * sin(t);
    temp.z = height * t;
    return temp;
}

Helixe::Vector_3D Helixe::getFirstDerivative(double t) const
{
    Curve::Vector_3D temp;
    temp.x = -sin(t) * radius;
    temp.y = radius * cos(t);
    temp.z = height;
    return temp;
}

void Helixe::Show(const Curve* const helixe, double t) const
{
    using std::cout;
    using std::endl;
    Curve::Point_3D point_temp = helixe->get3dPoint(t);
    Curve::Vector_3D vector_temp = helixe->getFirstDerivative(t);

    cout << "Helixe:\nget3dPoint: ( x:= " << point_temp.x << ", y:= " << point_temp.y << ", z:= " << point_temp.z << ")" << endl;
    cout << "getFirstDerivative: ( x:= " << vector_temp.x << ", y:= " << vector_temp.y << ", z:= " << vector_temp.z << ")" << endl;
}