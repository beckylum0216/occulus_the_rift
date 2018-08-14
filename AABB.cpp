
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


bool AABB::AABBtoAABB(const AABB &objectOther)
{
	return (maxPoint.x > objectOther.minBox.x &&
			minPoint.x < objectOther.maxBox.x &&
			maxPoint.y > objectOther.minBox.y &&
			minPoint.y < objectOther.maxBox.y &&
			maxPoint.z > objectOther.minBox.z &&
			minPoint.z < objectOther.maxBox.z);
}


