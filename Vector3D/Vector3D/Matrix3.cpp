#include "Matrix3.h"


Matrix3::Matrix3(double a11, double a12, double a13, double a21, double a22, double a23, double a31, double a32, double a33) :
	A11{ a11 },
	A12{ a12 },
	A13{ a13 },
	A21{ a21 },
	A22{ a22 },
	A23{ a23 },
	A31{ a31 },
	A32{ a32 },
	A33{ a33 }
{
}


Matrix3::~Matrix3()
{
}

static Vector3 operator *(Matrix3 M1, Vector3 V1)
{// An overloaded operator * to return the  product of the matrix by a vector
	return Vector3(M1.A11 * V1.X() + M1.A12 * V1.Y() + M1.A13 * V1.Z(),
		M1.A21 * V1.X() + M1.A22 * V1.Y() + M1.A23 * V1.Z(),
		M1.A31 * V1.X() + M1.A32 * V1.Y() + M1.A33 * V1.Z());
}

static Vector3 operator *(Vector3 V1, Matrix3 M1)
{// An overloaded operator * to return the  product of the matrix by a vector
	return Vector3(M1.A11 * V1.X() + M1.A21 * V1.Y() + M1.A31 * V1.Z(),
		M1.A12 * V1.X() + M1.A22 * V1.Y() + M1.A32 * V1.Z(),
		M1.A13 * V1.X() + M1.A23 * V1.Y() + M1.A33 * V1.Z());
}

static Matrix3 operator +(Matrix3 M1, Matrix3 M2)
{// An overloaded operator + to return the  sum of two matrix 
	return Matrix3(M1.A11 + M2.A11, M1.A12 + M2.A12, M1.A13 + M2.A13,
		M1.A21 + M2.A21, M1.A22 + M2.A22, M1.A23 + M2.A23,
		M1.A31 + M2.A31, M1.A32 + M2.A32, M1.A33 + M2.A33);
}
static Matrix3 operator -(Matrix3 M1, Matrix3 M2)
{// An overloaded operator * to return the  difference of two matrix
	return Matrix3(M1.A11 - M2.A11, M1.A12 - M2.A12, M1.A13 - M2.A13,
		M1.A21 - M2.A21, M1.A22 - M2.A22, M1.A23 - M2.A23,
		M1.A31 - M2.A31, M1.A32 - M2.A32, M1.A33 - M2.A33);
}

static Matrix3 operator *(double x, Matrix3 M1)
{// An overloaded operator * to return the  product of the matrix by a scalar
	Matrix3 answer = Matrix3(M1.A11 * x, M1.A12 * x, M1.A13 * x, M1.A21 * x, M1.A22 * x, M1.A23 * x, M1.A31 * x, M1.A32 * x, M1.A33 * x);
	answer.A11 = M1.A11 * x;
	answer.A12 = M1.A12 * x;
	answer.A13 = M1.A13 * x;

	answer.A21 = M1.A21 * x;
	answer.A22 = M1.A22 * x;
	answer.A23 = M1.A23 * x;

	answer.A31 = M1.A31 * x;
	answer.A32 = M1.A32 * x;
	answer.A33 = M1.A33 * x;

	return answer;
}

static Matrix3 operator *(Matrix3 M1, Matrix3 M2)
{// An overloaded operator * to return the  product of two matrix
	Matrix3 answer = Matrix3(
		M1.A11 * M2.A11 + M1.A12 * M2.A21 + M1.A13 * M2.A31,
		M1.A11 * M2.A12 + M1.A12 * M2.A22 + M1.A13 * M2.A32,
		M1.A11 * M2.A13 + M1.A12 * M2.A23 + M1.A13 * M2.A33,

		M1.A21 * M2.A11 + M1.A12 * M2.A21 + M1.A13 * M2.A31,
		M1.A21 * M2.A12 + M1.A12 * M2.A22 + M1.A13 * M2.A32,
		M1.A21 * M2.A13 + M1.A12 * M2.A23 + M1.A13 * M2.A33,

		M1.A31 * M2.A11 + M1.A32 * M2.A21 + M1.A33 * M2.A31,
		M1.A31 * M2.A12 + M1.A32 * M2.A22 + M1.A33 * M2.A32,
		M1.A31 * M2.A13 + M1.A32 * M2.A23 + M1.A33 * M2.A33
	);

	return answer;
}

Matrix3 Matrix3::Transpose(Matrix3 M1)
{// a method to transpose a given matrix
	return Matrix3(M1.A11, M1.A21, M1.A31,
		M1.A12, M1.A22, M1.A32,
		M1.A13, M1.A23, M1.A33);
}

double Matrix3::Determinant(Matrix3 M1)
{// method to return the determinant of a 3x3 matrix
 //                     aei      -     ahf                  + dhc                     - gec                      +    gbh                    -     dbi   
	return M1.A11 * M1.A22 * M1.A33 - M1.A11 * M1.A32 * M1.A23 + M1.A21 * M1.A32 * M1.A13 - M1.A31 * M1.A22 * M1.A13 + M1.A31 * M1.A12 * M1.A23 - M1.A21 * M1.A12 * M1.A33;
}

Vector3 Matrix3::Row(int i)
{
	// a method to return as Row as vector3 0 == first row, default == last row
	switch (i)
	{
	case 0:
		return Vector3(A11, A12, A13);
	case 1:
		return Vector3(A21, A22, A23);
	case 2:
	default:
		return Vector3(A31, A32, A33);
	}
}

Vector3 Matrix3::Column(int i)
{// a method to return as column as vector3 0 == first column, default == last column
	switch (i)
	{
	case 0:
		return Vector3(A11, A21, A31);
	case 1:
		return Vector3(A12, A22, A32);
	case 2:
	default:
		return Vector3(A13, A23, A33);
	}
}

Matrix3 Matrix3::Inverse(Matrix3 M1)
{
	// method to return the inverse of a matrix if exists else zero vector
	double det = Determinant(M1);
	if (det == 0)
		return Matrix3(M1);
	else
	{
		double scale = 1 / det;
		Matrix3 answer = Matrix3(
			scale * (M1.A22 * M1.A33 - M1.A23 * M1.A32), // ei-fh
			scale * (M1.A13 * M1.A32 - M1.A12 * M1.A33), // ch-bi
			scale * (M1.A12 * M1.A23 - M1.A13 * M1.A22), // ch-bi

			scale * (M1.A23 * M1.A31 - M1.A21 * M1.A33), // fg-di
			scale * (M1.A11 * M1.A33 - M1.A13 * M1.A31), // ai-cg
			scale * (M1.A13 * M1.A21 - M1.A11 * M1.A23), // cd-af

			scale * (M1.A21 * M1.A32 - M1.A22 * M1.A31), // dh-eg
			scale * (M1.A12 * M1.A31 - M1.A11 * M1.A32), // bg-ah
			scale * (M1.A11 * M1.A22 - M1.A12 * M1.A21) // ae-bd
		);
		return answer;
	}

}

Matrix3 Matrix3::Rotation(int _angle)
{
	double radians = (22.0 / 7.0) / 180 * _angle;
	Matrix3 answer = Matrix3(
		cos(radians),
		sin(radians),
		0,
		-sin(radians),
		cos(radians),
		0,
		0,
		0,
		1
	);
	return answer;
}

Matrix3 Matrix3::Translate(int dx, int dy)
{
	Matrix3 answer = Matrix3(
		1,
		0,
		0,
		0,
		1,
		0,
		dx,
		dy,
		1
	);
	return answer;
}

Matrix3 Matrix3::Scale(int dx, int dy)
{
	Matrix3 answer = Matrix3(
		(double)dx / 100,
		0,
		0,
		0,
		(double)dy / 100,
		0,
		0,
		0,
		1
	);
	return answer;
}

static Matrix3 operator -(Matrix3 M1)
{
	return -1 * M1;
}

Matrix3 Matrix3::RotationX(int _angle)
{
	double radians = (22.0 / 7.0) / 180 * _angle;
	Matrix3 answer = Matrix3(
		1,
		0,
		0,
		0,
		cos(radians),
		-sin(radians),
		0,
		sin(radians),
		cos(radians)
	);
	return answer;
}
Matrix3 Matrix3::RotationY(int _angle)
{
	double radians = (22.0 / 7.0) / 180 * _angle;
	Matrix3 answer = Matrix3(
		cos(radians),
		0,
		sin(radians),
		0,
		1,
		0,
		-sin(radians),
		0,
		cos(radians)
	);
	return answer;
}
Matrix3 Matrix3::RotationZ(int _angle)
{
	double radians = (22.0 / 7.0) / 180 * _angle;
	Matrix3 answer = Matrix3(
		cos(radians),
		-sin(radians),
		0,
		sin(radians),
		cos(radians),
		0,
		0,
		0,
		1
	);
	return answer;
}

Matrix3 Matrix3::Scale3D(int dx)
{
	Matrix3 answer = Matrix3(
		(double)dx / 100,
		0,
		0,
		0,
		(double)dx / 100,
		0,
		0,
		0,
		(double)dx / 100
	);
	return answer;
}