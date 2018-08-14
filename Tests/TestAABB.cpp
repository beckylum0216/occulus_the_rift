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


bool TestAABB::CollisionTest001()
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

bool TestAABB::CollisionTest002()
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

	inputMin.x = 0.5;
	inputMin.y = 0.5;
	inputMin.z = 0.5;
	inputMax.x = 1.5;
	inputMax.y = 1.5;
	inputMax.z = 1.5;

	objectTwo.SetMinPoint(inputMin);
	objectTwo.SetMaxPoint(inputMax);


	std::cout << "Test: " << objectOne.AABBtoAABB(objectTwo) << std::endl;

	return objectOne.AABBtoAABB(objectTwo);
}

bool TestAABB::CollisionTest003()
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

	inputMin.x = 1.0;
	inputMin.y = 1.0;
	inputMin.z = 1.0;
	inputMax.x = 2.0;
	inputMax.y = 2.0;
	inputMax.z = 2.0;

	objectTwo.SetMinPoint(inputMin);
	objectTwo.SetMaxPoint(inputMax);


	std::cout << "Test: " << objectOne.AABBtoAABB(objectTwo) << std::endl;

	return objectOne.AABBtoAABB(objectTwo);
}