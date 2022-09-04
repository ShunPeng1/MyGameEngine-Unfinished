#include "Vector3D.h"
#include <cmath>

Vector3D::Vector3D(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
};

float& Vector3D::operator [] (int i) {
	return ((&x)[i]);
};

const float& Vector3D::operator [] (int i) const {
	return ((&x)[i]);
};

Vector3D& Vector3D::operator *=(float s) {
	x *= s;
	y *= s;
	z *= s;
	return (*this);
}

Vector3D& Vector3D::operator /=(float s) {
	s = 1.0F / s;
	x *= s;
	y *= s;
	z *= s;
	return (*this);
}

Vector3D operator-(const Vector3D& v)
{
	return (Vector3D(-v.x, -v.y, -v.z));
}

float Magnitude(const Vector3D& v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

Vector3D Normalize(const Vector3D& v)
{
	return (v / Magnitude(v));
}

Vector3D& Vector3D::operator+=(const Vector3D& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	return (*this);
}

Vector3D& Vector3D::operator-=(const Vector3D& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return (*this);
}

float Dot(const Vector3D& a, const Vector3D& b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

Vector3D Cross(const Vector3D& a, const Vector3D& b)
{
	return (Vector3D(a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x));
}

Vector3D Project(const Vector3D& a, const Vector3D& b)
{
	return (b * (Dot(a, b) / Dot(b, b)));
}

Vector3D Reject(const Vector3D& a, const Vector3D& b)
{
	return (a - b * (Dot(a, b) / Dot(b, b)));
}

Vector3D operator*(const Vector3D& v, float s)
{
	return (Vector3D(v.x * s, v.y * s, v.z * s));
}

Vector3D operator/(const Vector3D& v, float s)
{
	s = 1.0F / s;
	return (Vector3D(v.x * s, v.y * s, v.z * s));
}

Vector3D operator+(const Vector3D& a, const Vector3D& b)
{
	return (Vector3D(a.x + b.x, a.y + b.y, a.z + b.z));
}

Vector3D operator-(const Vector3D& a, const Vector3D& b)
{
	return (Vector3D(a.x - b.x, a.y - b.y, a.z - b.z));
}

