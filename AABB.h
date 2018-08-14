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
		/**
		*	@brief mutator for minPoint
		*	@param inputMin defines the minimum point of bounding box in 3d space
		*	@return
		*	@pre
		*	@post
		*/
		void SetMinPoint(Pointz inputMin);
		/**
		*	@brief accessor for minPoint
		*	@param 
		*	@return minimum point of bounding box in 3d space
		*	@pre point must exist
		*	@post
		*/
		Pointz GetMinPoint();
		/**
		*	@brief mutator for maxPoint
		*	@param inputMax maximum point of bounding box in 3d space
		*	@return 
		*	@pre
		*	@post
		*/
		void SetMaxPoint(Pointz inputMax);
		/**
		*	@brief accessor for maxPoint
		*	@param
		*	@return maximum point of bounding box in 3d space
		*	@pre point must exist
		*	@post
		*/
		Pointz GetMaxPoint();
		/**
		*	@brief collision detection function
		*	@param objectOther target object for comparison
		*	@return a boolean of intersection is returned
		*	@pre minimum and maximum points must exist
		*	@post
		*/
		bool AABBtoAABB(AABB &objectOther);

	private:
		
		Pointz minPoint;
		Pointz maxPoint;
};
