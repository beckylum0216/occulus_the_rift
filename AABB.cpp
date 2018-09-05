
#include "pch.h"

#include <math.h>

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


Vector3 AABB::ProjectionNormal()
{
	Vector3 theProjection;
	Vector3 theNormalVector;

	theProjection = maxPoint.SubtractVector(minPoint);
	theNormalVector = theProjection.UnitNormal();

	return theNormalVector;
}


Projection AABB::VectorProjection()
{
	Vector3 resultNormal;
	GLdouble projectionOne;
	GLdouble projectionTwo;
	Projection resultProjection;

	resultNormal = ProjectionNormal();
	projectionOne = minPoint.DotProduct(resultNormal);
	projectionTwo = maxPoint.DotProduct(resultNormal);

	resultProjection = Projection(std::min(projectionOne, projectionTwo), std::max(projectionOne, projectionTwo));

	return resultProjection;
}


//float intersectionDepth = (mina < minb)? (maxa - minb) : (mina - maxb);
GLdouble AABB::ProjectionOverlap(Projection targetProjection)
{
	Projection theProjection;
	GLdouble theOverlap;

	theProjection = VectorProjection();

	if (theProjection.GetMinProjection() < targetProjection.GetMinProjection())
	{
		theOverlap = theProjection.GetMaxProjection() - targetProjection.GetMinProjection();
	}
	else
	{
		theOverlap = theProjection.GetMinProjection() - targetProjection.GetMaxProjection();
	}

	return theOverlap;

}


// calculating depth penetration using SAT to find the minimum translation vector
Vector3 AABB::MinimumTranslationVector(AABB &projectTarget)
{
	Projection targetObject;
	GLdouble overlapDepth;
	Vector3 theMTV;

	targetObject = projectTarget.VectorProjection();

	if (AABBtoAABB(projectTarget))
	{
		overlapDepth = ProjectionOverlap(targetObject);
	}
	
	// don't know what I am doing here
	theMTV.setPointX( cos(minPoint.VectorAngle(maxPoint)) * overlapDepth);

	return theMTV;
}