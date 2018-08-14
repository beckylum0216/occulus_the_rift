
#include "AABB.h"
#include "gl/glut.h"



AABB::AABB()
{

}

AABB::~AABB()
{

}

void AABB::SetMinPoint(Pointz inputMinPoint)
{
	minPoint = inputMinPoint;
}

Pointz AABB::GetMinPoint()
{
	return minPoint;
}

void AABB::SetMaxPoint(Pointz inputMaxPoint)
{
	maxPoint = inputMaxPoint;
}


Pointz AABB::GetMaxPoint()
{
	return maxPoint;
}


bool AABB::AABBtoAABB(AABB &objectOther)
{	
	return (	maxPoint.x > objectOther.minPoint.x &&
				minPoint.x < objectOther.maxPoint.x &&
				maxPoint.y > objectOther.minPoint.y &&
				minPoint.y < objectOther.maxPoint.y &&
				maxPoint.z > objectOther.minPoint.z &&
				minPoint.z < objectOther.maxPoint.z);
}


Pointz AABB::IntersectionDepth(AABB &objectTarget)
{
	Pointz theResult;
	if (AABBtoAABB(objectTarget))
	{
		theResult.x = minPoint.x - objectTarget.maxPoint.x;
		theResult.y = minPoint.y - objectTarget.maxPoint.y;
		theResult.z = minPoint.z - objectTarget.maxPoint.z;
	}

	return theResult;
}

