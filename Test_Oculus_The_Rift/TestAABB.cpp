#include "pch.h"
#include "AABB.h"
#include "Vector3.h"

TEST(TestSuite1, TestAABB)
{
	AABB objectOne;
	AABB objectTwo;
	Vector3 inputMin;
	Vector3 inputMax;

	inputMin.setPointX(0.00);
	inputMin.setPointY(0.00);
	inputMin.setPointZ(0.00);
	inputMax.setPointX(1.0);
	inputMax.setPointY(1.0);
	inputMax.setPointZ(1.0);

	objectOne.SetMinPoint(inputMin);
	objectOne.SetMaxPoint(inputMax);

	inputMin.setPointX(2.00);
	inputMin.setPointY(2.00);
	inputMin.setPointZ(2.00);
	inputMax.setPointX(3.0);
	inputMax.setPointY(3.0);
	inputMax.setPointZ(3.0);

	objectTwo.SetMinPoint(inputMin);
	objectTwo.SetMaxPoint(inputMax);


	std::cout << "Test: " << objectOne.AABBtoAABB(objectTwo) << std::endl;

	SUCCEED();
}

TEST(TestSuite1, CollisionTest001)
{
	AABB objectOne;
	AABB objectTwo;
	Vector3 inputMin;
	Vector3 inputMax;

	inputMin.setPointX(0.00);
	inputMin.setPointY(0.00);
	inputMin.setPointZ(0.00);
	inputMax.setPointX(1.0);
	inputMax.setPointY(1.0);
	inputMax.setPointZ(1.0);

	objectOne.SetMinPoint(inputMin);
	objectOne.SetMaxPoint(inputMax);

	inputMin.setPointX(2.00);
	inputMin.setPointY(2.00);
	inputMin.setPointZ(2.00);
	inputMax.setPointX(3.0);
	inputMax.setPointY(3.0);
	inputMax.setPointZ(3.0);

	objectTwo.SetMinPoint(inputMin);
	objectTwo.SetMaxPoint(inputMax);


	std::cout << "Test: " << objectOne.AABBtoAABB(objectTwo) << std::endl;

	SUCCEED();
}

TEST(TestSuite1, CollisionTest002)
{
	AABB objectOne;
	AABB objectTwo;
	Vector3 inputMin;
	Vector3 inputMax;

	inputMin.setPointX(0.00);
	inputMin.setPointY(0.00);
	inputMin.setPointZ(0.00);
	inputMax.setPointX(1.0);
	inputMax.setPointY(1.0);
	inputMax.setPointZ(1.0);

	objectOne.SetMinPoint(inputMin);
	objectOne.SetMaxPoint(inputMax);

	inputMin.setPointX(0.5);
	inputMin.setPointY(0.5);
	inputMin.setPointZ(0.5);
	inputMax.setPointX(1.5);
	inputMax.setPointY(1.5);
	inputMax.setPointZ(1.5);

	objectTwo.SetMinPoint(inputMin);
	objectTwo.SetMaxPoint(inputMax);


	std::cout << "Test: " << objectOne.AABBtoAABB(objectTwo) << std::endl;

	SUCCEED();
}

TEST(TestSuite1, CollisionTest003)
{
	AABB objectOne;
	AABB objectTwo;
	Vector3 inputMin;
	Vector3 inputMax;

	inputMin.setPointX(0.00);
	inputMin.setPointY(0.00);
	inputMin.setPointZ(0.00);
	inputMax.setPointX(1.0);
	inputMax.setPointY(1.0);
	inputMax.setPointZ(1.0);

	objectOne.SetMinPoint(inputMin);
	objectOne.SetMaxPoint(inputMax);

	inputMin.setPointX(1.0);
	inputMin.setPointY(1.0);
	inputMin.setPointZ(1.0);
	inputMax.setPointX(2.0);
	inputMax.setPointY(2.0);
	inputMax.setPointZ(2.0);

	objectTwo.SetMinPoint(inputMin);
	objectTwo.SetMaxPoint(inputMax);


	std::cout << "Test: " << objectOne.AABBtoAABB(objectTwo) << std::endl;

	SUCCEED();
}