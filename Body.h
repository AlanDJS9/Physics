#pragma once
#include "Vec3.h"

using namespace std;

struct Body
{
	//Class variables
	double mass = 0;
	double angle = 0;
	double ttime = 0;

	double rotationalInertia = 0;
	double torq = 6.291e8;
	double angularVel = 0.;
	double angularAcc = 0;
	double angularDis = 0;
	double torqueForce = 0;
	double initialAngularVel = 0;

	Vec3 pos;
	Vec3 vel;
	Vec3 acc;
	Vec3 force;
	Vec3 torque;

	//Construct
	Body();
	Body(double mass_, double rotationalInertia_);

	//Handy methods
	void applyTorque(Vec3 torque);
	void applyForce(Vec3 force);
	void update(const double deltaTime);
	double getTimeElapsed() { return ttime; }
};