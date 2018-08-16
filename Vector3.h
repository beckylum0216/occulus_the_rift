#pragma once

#include "pch.h"
#include "gl/glut.h"

class Vector3
{
	public:
		Vector3();
		virtual~Vector3();
		void setPointX(GLdouble inputX);
		GLdouble getPointX();
		
		void setPointY(GLdouble inputY);
		GLdouble getPointY();

		void setPointZ(GLdouble inputZ);
		GLdouble getPointZ();
		

		Vector3 MultiplyScalar(GLdouble theScalar);
		GLdouble DotProduct(Vector3 inputVector);
		GLdouble VectorMagnitude();
		Vector3 CrossProduct(Vector3 otherVector);
		Vector3 UnitNormal(Vector3 vectorInput);

	private:
		GLdouble x;
		GLdouble y;
		GLdouble z;
};