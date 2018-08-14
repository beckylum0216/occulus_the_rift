#include <iostream>
#include "TestAABB.h"
#include "../AABB.h"

using namespace std;

TestAABB::TestAABB()
{

}

TestAABB::~TestAABB()
{

}


bool TestAABB::CollisionTest()
{
	AABB objectOne;
	AABB objectTwo;
	Pointz inputMin;
	Pointz inputMax;

	inputMin.x = 0.0;
	inputMin.y = 0.0;
	inputMin.z = 0.0;
	inputMax.x = 1.0;
	inputMax.y = 1.0;
	inputMax.z = 1.0;

	objectOne.SetMinPoint(inputMin);
	objectOne.SetMaxPoint(inputMax);

	inputMin.x = 2.0;
	inputMin.y = 2.0;
	inputMin.z = 2.0;
	inputMax.x = 3.0;
	inputMax.y = 3.0;
	inputMax.z = 3.0;

	objectTwo.SetMinPoint(inputMin);
	objectTwo.SetMaxPoint(inputMax);

	
	std::cout << "Test: " << objectOne.AABBtoAABB(objectTwo) << std::endl;

	return objectOne.AABBtoAABB(objectTwo);
}