#pragma once
#include "Vector3.h"
#include <math.h>
class Matrix3
{
public:
	Matrix3(double a11, double a12, double a13, double a21, double a22, double a23, double a31, double a32, double a33);
	~Matrix3();

	double A11;
	double A12;
	double A13;

	double A21;
	double A22;
	double A23;

	double A31;
	double A32;
	double A33;

	double Determinant(Matrix3 M1);

	Vector3 Row(int i);

	Vector3 Column(int i);


	Matrix3 Inverse(Matrix3 M1);

	Matrix3 Rotation(int _angle);

	Matrix3 Transpose(Matrix3 M1);

	Matrix3 Translate(int dx, int dy);

	Matrix3 Scale(int dx, int dy);

	Matrix3 operator -(Matrix3 M1);

	static Matrix3 RotationX(int _angle);

	static Matrix3 RotationY(int _angle);

	static Matrix3 RotationZ(int _angle);

	static Matrix3 Scale3D(int dx);
};