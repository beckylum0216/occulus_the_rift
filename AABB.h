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
		bool AABBtoAABB(const AABB &objectOther);

	private:
		Point minPoint;
		Point maxPoint;


};
