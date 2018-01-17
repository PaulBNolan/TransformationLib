#pragma once
class Vector3
{
public:
	Vector3(double x, double y, double z);
	~Vector3();

	double x;
	double y;
	double z;

	double X();
	double Y();
	double Z();

	double Length();
	double LengthSquared();

	void Normalise();
};

