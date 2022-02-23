#include <iostream>
#include "Body.h"
#include "Vec3.h"

using namespace std;


int main()
{
	//Assignment 1 values
	Body spaceShip(1e6 , 2.67e10); //CREATING THE SPACESHIP WITH THE MASS AND ROTATIONAL INERTIA
	Vec3 resultantForce(5e7, 0, 0); //FORCE OF NOTH ENGINES
	Vec3 resultantTorque(6.291e8, 0, 0); //TORQUE


	//THE SHIP TAKES OFF
	spaceShip.applyForce(resultantForce);
	do {
		spaceShip.update(1.0f);
	} while(spaceShip.getTimeElapsed() < 5); //5 SECONDS UNTIL THE RIGHT ENGINE FAILS

	
	spaceShip.applyForce(Vec3((5e7 / 2), 0.0, 0.0)); //THE FORCE OF THE LEFT ENGINE 
	spaceShip.applyTorque(resultantTorque); //TORUQE CREATING THE ANGULAR STUFF 


	for (int i = 0; i < 500; i++)
	{
		spaceShip.update(1.0f); //UPDATE THE DATA 
	}
	printf("\n Alan Jimenez - Physics II -  Assignment1/PART B - n01487231");
	return 0;
}