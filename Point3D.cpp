#include "Vector3D.h"
#include "Point3D.h"


Point3D operator+(const Point3D& a, const Vector3D& b)
{
	return (Point3D(a.x + b.x, a.y + b.y, a.z + b.z));
}

Vector3D operator -(const Point3D& a, const Point3D& b)
{
	return (Vector3D(a.x - b.x, a.y - b.y, a.z - b.z));
}
