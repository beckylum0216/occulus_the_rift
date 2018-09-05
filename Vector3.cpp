
#include <math.h>

#include "pch.h"
#include "Vector3.h"
#include "glut_bin/gl/glut.h"

Vector3::Vector3()
{

}

Vector3::~Vector3()
{

}

void Vector3::setPointX(GLdouble inputX)
{
	x = inputX;
}

GLdouble Vector3::getPointX()
{
	return x;
}

void Vector3::setPointY(GLdouble inputY)
{
	y = inputY;
}

GLdouble Vector3::getPointY()
{
	return y;
}

void Vector3::setPointZ(GLdouble inputZ)
{
	z = inputZ;
}

GLdouble Vector3::getPointZ()
{
	return z;
}

//applies a scalar to the vector
Vector3 Vector3::MultiplyScalar(GLdouble theScalar)
{
	Vector3 tempResult;

	tempResult.x = x * theScalar;
	tempResult.y = y * theScalar;
	tempResult.z = z * theScalar;

	return tempResult;
}

// calculates the dot product
GLdouble Vector3::DotProduct(Vector3 inputVector)
{
	GLdouble productResult;

	productResult = x * inputVector.x + y * inputVector.y + z * inputVector.z;
	
	return productResult;
}

// calculates the magnitude
GLdouble Vector3::VectorMagnitude()
{
	GLdouble theMagnitude;

	theMagnitude = x * x + y * y + z * z;
	theMagnitude = sqrt(theMagnitude);

	return theMagnitude;
}

Vector3 Vector3::CrossProduct(Vector3 otherVector)
{
	Vector3 tempVector;

	tempVector.x = y * otherVector.z - z * otherVector.y;
	tempVector.y = x * otherVector.z - z * otherVector.x;
	tempVector.z = x * otherVector.y - y * otherVector.x;

	return tempVector;
}

Vector3 Vector3::UnitNormal()
{
	GLdouble theVectorMagnitude;
	Vector3 theResultVector;

	theVectorMagnitude = VectorMagnitude();
	theResultVector.x = x / theVectorMagnitude;
	theResultVector.y = y / theVectorMagnitude;
	theResultVector.z = z / theVectorMagnitude;

	return theResultVector;
}

GLdouble Vector3::VectorAngle(Vector3 targetVector)
{
	GLdouble tempDotResult;
	GLdouble magnitudeOne;
	GLdouble magnitudeTwo;
	GLdouble magnitudeProduct;
	GLdouble resultAngle;

	tempDotResult = DotProduct(targetVector);
	magnitudeOne = VectorMagnitude();
	magnitudeTwo = targetVector.VectorMagnitude();
	magnitudeProduct = magnitudeOne * magnitudeTwo;
	resultAngle = acos(tempDotResult / magnitudeProduct);

	return resultAngle;
}

Vector3 Vector3::SubtractVector(Vector3 theInputVector)
{
	Vector3 resultVector;

	resultVector.x = x - theInputVector.x;
	resultVector.y = y - theInputVector.y;
	resultVector.z = z - theInputVector.z;

	return resultVector;
}