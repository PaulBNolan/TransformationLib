#include "Vector3.h"
#include <math.h>


Vector3::Vector3(double x, double y, double z)
{
	
}


Vector3::~Vector3()
{
}

double Vector3::X()
{
	return  x;
}

double Vector3::Y()
{
	return y;
}
double Vector3::Z()
{
	return z;
}


static Vector3 operator +(Vector3 V1, Vector3 V2)
{  // An overloaded operator + to return the sum of 2 vectors
	return Vector3(V1.x + V2.x, V1.y + V2.y, V1.z + V2.z);
}

static Vector3 operator -(Vector3 V1, Vector3 V2)
{ // An overloaded operator - to return the difference of 2 vectors
	return Vector3(V1.x - V2.x, V1.y - V2.y, V1.z - V2.z);
}

static Vector3 operator -(Vector3 V)
{// An overloaded operator - to return the negation of a single vector
	Vector3 V1 =  Vector3(-V.x, -V.y, -V.z);
	return V1;
}

static double operator *(Vector3 V1, Vector3 V2)
{// An overloaded operator * to return the scalar product of 2 vectors
	return (V1.x * V2.x + V1.y * V2.y + V1.z * V2.z);
}

static Vector3 operator *(double k, Vector3 V1)
{// An overloaded operator * to return the product of a scalar by a vector
	return Vector3(V1.x * (float)k, V1.y * (float)k, V1.z * (float)k);
}

static Vector3 operator *(float k, Vector3 V1)
{// An overloaded operator * to return the product of a scalar by a vector
	return Vector3(V1.x * k, V1.y * k, V1.z * k);
}

static Vector3 operator *(int k, Vector3 V1)
{// An overloaded operator * to return the product of a scalar by a vector
	return Vector3(V1.x * k, V1.y * k, V1.z * k);
}

static Vector3 operator ^(Vector3 V1, Vector3 V2)
{// An overloaded operator ^ to return the vector product of 2 vectors
	return Vector3(V1.y * V2.z - V1.z * V2.y, V1.z * V2.x - V1.x * V2.z, V1.x * V2.y - V1.y * V2.x);
}

double Vector3::Length()
{
	return double(sqrt(x * x + y * y + z * z));
}
double Vector3::LengthSquared()
{
	return double(x * x + y * y + z * z);
}

void Vector3::Normalise()
{
	double length = Length();
	if (length > 0)
	{
		x /= length;
		y /= length;
		z /= length;
	}
}