#ifndef VEC3_H
#define VEC3_H

#include <iostream>
#include <math.h>

using namespace std;

class Vec3
{
public:
	//Class variables
	double x;
	double y;
	double z;
	
	
	//Construct
	Vec3();
	Vec3(double x_, double y_, double z_);

	//Handy methods
	void Add(Vec3 b);
	void Subtract(Vec3 b);
	void ScalarMultiplication(float s);
	float Mag();
	void Normalize();
	float Dot(Vec3);
	void Lerp(Vec3, float t);
	void RotateZ(float angle);

};

#endif