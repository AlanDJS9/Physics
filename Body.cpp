#include "Body.h"
#include <iostream>
#define PI 3.14159265
using namespace std;


Body::Body()
{
	// Set pos, vel, and acc to [0, 0, 0]
	pos.x = 0;
	pos.y = 0;
	pos.z = 0;

	vel.x = 0;
	vel.y = 0;
	vel.z = 0;

	acc.x = 0;
	acc.y = 0;
	acc.z = 0;

	// Set mass to a default value of 1.0f
	mass = 1.0f;
}

Body::Body(double mass_, double rotationalInertia_)
{
	pos.x = 0.0;
	pos.y = 0.0;
	pos.z = 0.0;

	vel.x = 0.0;
	vel.y = 0.0;
	vel.z = 0.0;

	acc.x = 0.0;
	acc.y = 0.0;
	acc.z = 0.0;

	mass = mass_;
	rotationalInertia = rotationalInertia_;


}

void Body::update(double deltaTime)
{
	//WE CALCULATE THE ANGULAR VELOCITY HERE

	if (angularAcc != 0) //THIS IF HELPS IN CASE THE ANGULAR ACC = 0
	{
		//CALCULATING THE ANGULAR DISPLACEMENT
		angularDis = angularDis + (angularVel * deltaTime) + (0.5f * angularAcc * pow(deltaTime, 2));
			//((angularVel * angularVel) - (initialAngularVel * initialAngularVel)) / (2.0 * angularAcc);
	}
	angularVel = angularVel + (angularAcc * deltaTime);

	printf("| t = %f s | angularAcc = %f s | angularVel = %f s | angularDis = %f s | force.x = %f s | force.y = %f s | acc.x = %f s | acc.y = %f s | vel.x = %f s | vel.y = %f s | pos.x = %f m |  pos.y = %f m/s | \n", ttime, angularAcc, angularVel, angularDis, force.x, force.y, acc.x, acc.y, vel.x, vel.y, pos.x, pos.y);



	//UPDATING LINEAR STUFF, POSITION, VELOCITY, ACCELERATION 
	force = Vec3(((force.x) * cos(angularDis) - (force.y * sin(angularDis))), ((force.x) * sin(angularDis) + ((force.y) * cos(angularDis))), 0.0);
	acc = Vec3(force.x / mass, force.y / mass, 0.0);

	pos.x += vel.x * deltaTime + 0.5f * acc.x * deltaTime * deltaTime;
	pos.y += vel.y * deltaTime + 0.5f * acc.y * deltaTime * deltaTime;
	pos.z += vel.z * deltaTime + 0.5f * acc.z * deltaTime * deltaTime;
	vel.y += acc.y * deltaTime;
	vel.x += acc.x * deltaTime;

	//SECONDS ELAPSED
	ttime += 1;
}

void Body::applyForce(Vec3 incomingFForce)
{
	force = incomingFForce;
	acc = Vec3(incomingFForce.x / mass, incomingFForce.y / mass, 0.0);
}


void Body::applyTorque(Vec3 torqueAppplied)
{
	angularAcc = torqueAppplied.x / rotationalInertia;
	force = Vec3(((force.x) * cos(angularDis) - (force.y * sin(angularDis))), ((force.x) * sin(angularDis) + ((force.y) * cos(angularDis))), 0.0);

}


//printf("\n Alan Jimenez - Physics II -  Assignment1/PART B - n01487231");

