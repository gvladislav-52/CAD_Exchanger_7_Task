#include "pch.h"

#include "Circle.h"

Circle::Point_3D Circle::get3dPoint(double t) const
{
    Curve::Point_3D temp;
    temp.x = cos(t) * radius;
    temp.y = sin(t) * radius;
    temp.z = NULL;
    return temp;
}

Circle::Vector_3D Circle::getFirstDerivative(double t) const
{
    Curve::Vector_3D temp;
    temp.x = -sin(t) * radius;
    temp.y = cos(t) * radius;
    temp.z = NULL;
    return temp;
}

void Circle::Show(const Curve* const circle, double t) const
{
    using std::cout; 
    using std::endl;
    Curve::Point_3D point_temp = circle->get3dPoint(t);
    Curve::Vector_3D vector_temp = circle->getFirstDerivative(t);

    cout << "Circle:\nget3dPoint: ( x:= " << point_temp.x << ", y:= " << point_temp.y << ", z:= " << point_temp.z << ")" << endl;
    cout << "getFirstDerivative: ( x:= " << vector_temp.x << ", y:= " << vector_temp.y << ", z:= " << vector_temp.z << ")" << endl;
    cout << "Radius: " << radius << endl;
}
