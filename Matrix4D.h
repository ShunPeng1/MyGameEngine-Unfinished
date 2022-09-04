#pragma once
class Matrix4D
{
protected:
	float n[4][4];
public:
	/*Matrix4D() = default;
	Matrix4D(float n00, float n01, float n02, float n03,
		float n10, float n11, float n12, float n13,
		float n20, float n21, float n22, float n23);
		
	Matrix4D(const Vector3D & a, const Vector3D & b, const Vector3D & c, const Vector3D& d);
	*/
	float& operator() (int i, int j);
	const float& operator () (int i, int j) const;

	//Vector3D& operator [] (int j);
	//const Vector3D& operator[] (int j) const;

};


//Matrix4D operator *(const Matrix4D& A, const Matrix4D& B);
//Vector3D operator *(const Matrix4D& M, const Vector3D& v);
//
//float Determinant(const Matrix4D& M);
//Matrix4D Inverse(const Matrix4D& M);

