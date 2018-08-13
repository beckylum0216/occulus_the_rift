#pragma once

#include <gl/glut.h>
#include <math.h>

#include "Actor.h"

class Player : public Actor {
public:
	Player();

	void Draw();
	void Update();

	//-------------------------------------------
	// Set methods
	void SetMoveSpeed(GLdouble tmpSpd);
	void SetRotateSpeed(GLdouble tmpSpd);

	void DirectionFB(GLdouble const tempMove);
	void DirectionLR(GLdouble const tempMove);
	void DirectionUD(GLdouble const tempMove);
	void DirectionLookLR(GLdouble const tempRot);
	void DirectionLookUD(GLdouble const tempRot);
	//-------------------------------------------

	//-------------------------------------------
	// Get methods
	GLdouble GetLR();
	GLdouble GetUD();
	GLdouble GetFB();
	//-------------------------------------------

	void Move();

private:
	//Movement
	GLdouble moveSpeed,
		rotateSpeed;

	//Directional vectors for looking
	Point lookFB,
		lookLR;

	//Change in movement
	GLdouble deltaMoveFB,
		deltaMoveLR,
		deltaMoveUD;

	//Rotation
	GLdouble rotLR,
		rotUD,
		deltaRotLR,
		deltaRotUD;

	//-------------------------------------------
	// Move the player
	void MoveFB();
	void MoveLR();
	void MoveUD();
	void LookLR();
	void LookUD();
};