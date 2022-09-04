#pragma once
class Vector3D
{	
public:
	float x, y, z;
	

	Vector3D() = default;
	Vector3D(float x, float y, float z);
	
	float& operator [] (int i);
	const float& operator [] (int i) const;

	Vector3D& operator *=(float s);
	Vector3D& operator /=(float s);

	Vector3D& operator +=(const Vector3D& v);
	Vector3D& operator -=(const Vector3D& v);

	friend Vector3D operator *(const Vector3D& v, float s);
	friend Vector3D operator /(const Vector3D& v, float s);
	friend Vector3D operator -(const Vector3D& v);

	friend Vector3D operator +(const Vector3D& a, const Vector3D& b);
	friend Vector3D operator -(const Vector3D& a, const Vector3D& b);
	
};




float Magnitude(const Vector3D& v);
Vector3D Normalize(const Vector3D& v);

float Dot(const Vector3D& a, const Vector3D& b);
Vector3D Cross(const Vector3D& a, const Vector3D& b);
Vector3D Project(const Vector3D& a, const Vector3D& b);
Vector3D Reject(const Vector3D& a, const Vector3D& b);