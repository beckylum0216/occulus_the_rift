#pragma once

#include "gl/glut.h"

struct Point {
	GLdouble x, y, z;
};

struct Box {
	Point minBox;
	Point maxBox;
};

class AABB
{
	public:
		AABB();
		virtual~AABB();
		void SetMinPoint(Point inputMin);
		Point GetMinPoint();
		void SetMaxPoint(Point inputMax);
		Point GetMaxPoint();
		bool AABBtoAABB(const Box &objectOne, const Box &objectTwo);

	private:
		Point minPoint;
		Point maxPoint;


};
