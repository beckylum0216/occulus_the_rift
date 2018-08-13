
#include "AABB.h"
#include "gl/glut.h"

AABB::AABB()
{

}

AABB::~AABB()
{

}

void AABB::SetMinPoint(Point inputMinPoint)
{
	minPoint = inputMinPoint;
}

Point AABB::GetMinPoint()
{
	return minPoint;
}

void AABB::SetMaxPoint(Point inputMaxPoint)
{
	maxPoint = inputMaxPoint;
}


Point AABB::GetMaxPoint()
{
	return maxPoint;
}


bool AABB::AABBtoAABB(const Box &objectOne, const Box &objectTwo)
{
	return (objectOne.maxBox.x > objectTwo.minBox.x &&
			objectOne.minBox.x < objectTwo.maxBox.x &&
			objectOne.maxBox.y > objectTwo.minBox.y &&
			objectOne.minBox.y < objectTwo.maxBox.y &&
			objectOne.maxBox.z > objectTwo.minBox.z &&
			objectOne.minBox.z < objectTwo.maxBox.z);
}


