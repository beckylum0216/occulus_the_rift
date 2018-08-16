
#include "pch.h"
#include "AABB.h"
#include "Vector3.h"
#include "gl/glut.h"



AABB::AABB()
{

}

AABB::~AABB()
{

}

void AABB::SetMinPoint(Vector3 inputMinPoint)
{
	minPoint = inputMinPoint;
}

Vector3 AABB::GetMinPoint()
{
	return minPoint;
}

void AABB::SetMaxPoint(Vector3 inputMaxPoint)
{
	maxPoint = inputMaxPoint;
}


Vector3 AABB::GetMaxPoint()
{
	return maxPoint;
}


bool AABB::AABBtoAABB(AABB &objectOther)
{	
	
	
	return (	maxPoint.getPointX() > objectOther.minPoint.getPointX() &&
				minPoint.getPointX() < objectOther.maxPoint.getPointX() &&
				maxPoint.getPointY() > objectOther.minPoint.getPointY() &&
				minPoint.getPointY() < objectOther.maxPoint.getPointY() &&
				maxPoint.getPointZ() > objectOther.minPoint.getPointZ() &&
				minPoint.getPointZ() < objectOther.maxPoint.getPointZ());
}


Vector3 AABB::IntersectionDepth(AABB &objectTarget)
{
	Vector3 theResult;
	if (AABBtoAABB(objectTarget))
	{
		theResult.setPointX(minPoint.getPointX() - objectTarget.maxPoint.getPointX());
		theResult.setPointY(minPoint.getPointY() - objectTarget.maxPoint.getPointY());
		theResult.setPointZ(minPoint.getPointZ() - objectTarget.maxPoint.getPointZ());
	}

	return theResult;
}