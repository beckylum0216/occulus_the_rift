#pragma once

#include <gl\glut.h>

#define PI 3.141592654

struct Point {
	GLdouble x, y, z;
};

enum Tag {
	
};

class Actor {
public:
	Actor();
	//Actor(Model, Texture, Collision, pos, rot, sca, tag);

	virtual void Update();
	virtual void Draw();

	//--------------------------------------------------------------
	// Set methods
	void SetPos(GLdouble tempX, GLdouble tempY, GLdouble tempZ);
	void SetPos(Point pos);
	void SetRot(GLdouble rotX, GLdouble rotY, GLdouble rotZ);
	void SetRot(Point rot);
	void SetScale(GLdouble scaX, GLdouble scaY, GLdouble scaZ);
	void SetScale(Point sca);

	void SetTagType(Tag type);

	/*	FindModel
		FindTex
		FindCollider
	*/
	//--------------------------------------------------------------

	//--------------------------------------------------------------
	// Get methods
	Point GetPos();
	Point GetRot();
	Point GetScale();
	Tag GetTagType();
	//--------------------------------------------------------------

protected:
	Point position,
		rotation,
		scale;

	Tag tagType;

	//Model*
	//Texture*
	//Collision
};
