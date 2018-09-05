#pragma once

#include "pch.h"
#include "gl/glut.h"
#include "Vector3.h"
#include "Projection.h"

/**
*	@class AABB
*	@brief class encapsulating collision detection and utlity functions
*	@author Rebecca Lim
*	@version 1.0
*	@date 14-08-2018
*/


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
		void SetMinPoint(Vector3 inputMin);
		/**
		*	@brief accessor for minPoint
		*	@param 
		*	@return minimum point of bounding box in 3d space
		*	@pre point must exist
		*	@post
		*/
		Vector3 GetMinPoint();
		/**
		*	@brief mutator for maxPoint
		*	@param inputMax maximum point of bounding box in 3d space
		*	@return 
		*	@pre
		*	@post
		*/
		void SetMaxPoint(Vector3 inputMax);
		/**
		*	@brief accessor for maxPoint
		*	@param
		*	@return maximum point of bounding box in 3d space
		*	@pre point must exist
		*	@post
		*/
		Vector3 GetMaxPoint();
		/**
		*	@brief collision detection function
		*	@param objectOther target object for comparison
		*	@return a boolean of intersection is returned
		*	@pre minimum and maximum points must exist
		*	@post
		*/
		bool AABBtoAABB(AABB &objectOther);

		/**
		*	@brief to find the orthognoal vector to the projection
		*	@param inputTargetVector the comparison vector
		*	@return vector perpendicular to the projection is returned
		*	@pre
		*	@post
		*/
		Vector3 ProjectionNormal();


		/**
		*	@brief to find the projection between two bounding boxes
		*	@param targetVector the comparison vector
		*	@return projected projection is returned
		*	@pre 
		*	@post
		*/
		Projection VectorProjection();

		/**
		*	@brief to find the depth of intersection
		*	@param objectOther target object for comparison
		*	@return a depth of intersection is returned
		*	@pre minimum and maximum points must exist
		*	@post
		*/
		GLdouble ProjectionOverlap(Projection targetProjection);

		/**
		*	@brief to find the depth of intersection
		*	@param objectOther target object for comparison
		*	@return a depth of intersection is returned
		*	@pre minimum and maximum points must exist
		*	@post
		*/
		Vector3 MinimumTranslationVector(AABB &projectTarget);

	private:
		
		Vector3 minPoint;
		Vector3 maxPoint;
};
