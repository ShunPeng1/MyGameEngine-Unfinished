#pragma once
class Point3D: public Vector3D
{
public:
	Point3D() = default;
	Point3D(float a, float b, float c) :Vector3D(a, b, c) {}

	friend Point3D operator +(const Point3D& a, const Vector3D& b);

	friend Vector3D operator -(const Point3D& a, const Point3D& b) ;
};

