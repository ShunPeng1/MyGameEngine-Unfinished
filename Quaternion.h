#pragma once
class Quaternion
{
public:
	float x, y, z, w;
	Quaternion() = default;
	Quaternion(float a, float b, float c, float s);
		
	Quaternion(const Vector3D& v, float s);
		
	const Vector3D& GetVectorPart(void) const;
		
	Matrix3D GetRotationMatrix(void);
	void SetRotationMatrix(const Matrix3D & m);
	
};

Quaternion operator *(const Quaternion& ql, const Quaternion& q2);

Vector3D Transform(const Vector3D& v, const Quaternion& q);
