#pragma once

#include "gl/glut.h"

/**
*	@class AABB
*
*
*
*	@author Rebecca Lim
*	@version 1.0
*	@date 14-08-2018
*/

/**
*	@struct Pointz
*	Defines a point in 3D space
*/
struct Pointz 
{
	GLdouble x;
	GLdouble y;
	GLdouble z;
};

class AABB
{
	
	public:
		AABB();
		virtual~AABB();
		void SetMinPoint(Pointz inputMin);
		Pointz GetMinPoint();
		void SetMaxPoint(Pointz inputMax);
		Pointz GetMaxPoint();
		bool AABBtoAABB(const AABB &objectOther);

	private:
		
		Pointz minPoint;
		Pointz maxPoint;
};
