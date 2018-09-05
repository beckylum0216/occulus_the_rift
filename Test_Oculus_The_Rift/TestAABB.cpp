#include "pch.h"

#include <AABB.h>
#include <Vector3.h>
#include "Projection.h"

TEST(TestSuite1_AABBTesting, CollisionTest000_TestObjectCreation)
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

TEST(TestSuite1_AABBTesting, CollisionTest001_TestCollisionObjectApart)
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

	EXPECT_FALSE(objectOne.AABBtoAABB(objectTwo));
}

TEST(TestSuite1_AABBTesting, CollisionTest002_TestCollisionObjectsCollided)
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

	EXPECT_TRUE(objectOne.AABBtoAABB(objectTwo));
}

TEST(TestSuite1_AABBTesting, CollisionTest003_TestObjectJustTouching)
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

	EXPECT_FALSE(objectOne.AABBtoAABB(objectTwo));
}

TEST(TestSuite_AABBTesting, CollisionTest004_TestObjectOverlap)
{
	AABB objectOne;
	AABB objectTwo;
	Vector3 inputMin;
	Vector3 inputMax;
	GLdouble testOverlap;

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

	Projection targetTest;

	targetTest = objectTwo.VectorProjection();

	testOverlap = objectOne.ProjectionOverlap(targetTest);

	std::cout << "Overlap test: " << testOverlap << std::endl;

	SUCCEED();
}

