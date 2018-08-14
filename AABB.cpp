
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


bool AABB::AABBtoAABB(const AABB &objectOther)
{	
	return (	maxPoint.x > objectOther.GetMinPoint.x &&
				minPoint.x < objectOther.GetMaxPoint.x &&
				maxPoint.y > objectOther.GetMinPoint.y &&
				minPoint.y < objectOther.GetMaxPoint.y &&
				maxPoint.z > objectOther.GetMinPoint.z &&
				minPoint.z < objectOther.GetMaxPoint.z);
}


