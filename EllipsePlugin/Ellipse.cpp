#include "pch.h"

#include "Ellipse.h"

Ellips::Point_3D Ellips::get3dPoint(double t) const
{
    Curve::Point_3D temp;
    temp.x = a * cos(t);
    temp.y = b * sin(t);
    temp.z = NULL;
    return temp;
}

Ellips::Vector_3D Ellips::getFirstDerivative(double t) const
{
    Curve::Vector_3D temp;
    temp.x = a * (-sin(t));
    temp.y = cos(t) * b;
    temp.z = NULL;
    return temp;
}

void Ellips::Show(const Curve* const ellipse, double t) const
{
    using std::cout;
    using std::endl;
    Curve::Point_3D point_temp = ellipse->get3dPoint(t);
    Curve::Vector_3D vector_temp = ellipse->getFirstDerivative(t);

    cout << "Ellipse:\nget3dPoint: ( x:= " << point_temp.x << ", y:= " << point_temp.y << ", z:= " << point_temp.z << ")" << endl;
    cout << "getFirstDerivative: ( x:= " << vector_temp.x << ", y:= " << vector_temp.y << ", z:= " << vector_temp.z << ")" << endl;
}