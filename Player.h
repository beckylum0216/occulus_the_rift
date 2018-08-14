#pragma once

#include <gl/glut.h>
#include <math.h>

#include "Actor.h"

/**
 *	@class Player
 *
 *
 *
 *	@author Aaron Thomson
 *	@version 1.0
 *	@date 14-08-2018
 */
class Player : public Actor {
public:
	/**
	 *	A default constructor
	 */
	Player();

	/**
	 *	An overriding method that takes no arguments
	 */
	void Draw() override;
	/**
	 *	An overriding method that takes no arguments
	 */
	void Update() override;

	//-------------------------------------------
	// Set methods
	/**
	 *	A normal method that takes one argument
	 *	Sets the Player's movement speed
	 *	@param tmpSpd The desired movement speed value
	 */
	void SetMoveSpeed(GLdouble tmpSpd);
	/**
	 *	A normal method that takes on argument
	 *	Sets the Player's rotation speed
	 *	@param tmpSpd The desired rotation speed value
	 */
	void SetRotateSpeed(GLdouble tmpSpd);

	/**
	 *	A normal method that takes one argument
	 *	Used to determine which way the Player will move: forward or backward
	 *	@param tempMove A value of 1 (forward), -1 (backward) or 0 (stationary)
	 */
	void DirectionFB(GLdouble const tempMove);
	/**
	 *	A normal method which takes one argument
	 *	Used to determine which way the Player will move: left or right
	 *	@param tempMove A value of 1 (right), -1 (left) or 0 (stationary)
	 */
	void DirectionLR(GLdouble const tempMove);
	/**
	 *	A normal method which takes one argument
	 *	Used to determine which way the Player will move: up or down
	 *	@param tempMove A value of 1 (up), -1 (down) or 0 (stationary)
	 */
	void DirectionUD(GLdouble const tempMove);
	/**
	 *	A normal method which takes one argument
	 *	Used to determine which way the Player is rotating: left or right
	 *	@param tempRot A value of 1 (right), -1 (left) or 0 (stationary)
	 */
	void DirectionLookLR(GLdouble const tempRot);
	/**
	 *	A normal method which takes one argument
	 *	Used to determine which way the Player is rotating: up or down
	 *	@param tempRot A value of 1 (up), -1 (down) or 0 (stationary)
	 */
	void DirectionLookUD(GLdouble const tempRot);
	//-------------------------------------------

	//-------------------------------------------
	// Get methods
	/**
	 *	A normal method returning a GLdouble value
	 *	Returns the left/right (x) value of the Player
	 *	@return The x value of the Player's position
	 */
	GLdouble GetLR();
	/**
	 *	A normal method returning a GLdouble value
	 *	Returns the up/down (y) value of the Player
	 *	@return The y value of the Player's position
	 */
	GLdouble GetUD();
	/**
	 *	A normal method return a GLdouble value
	 *	Returns the front/back (z) value of the Player
	 *	@return The z value of the Player's position
	 */
	GLdouble GetFB();
	//-------------------------------------------

	/**
	 *	A normal method taking no arguments and returning nothing
	 *	Performs a check on values to determine if the Player has moved and performs necessary calculations
	 */
	void Move();

private:
	//Movement
	GLdouble moveSpeed,		/*<! The movement speed of the Player */
		rotateSpeed;		/*<! The rotation speed of the Player */

	//Directional vectors for looking
	Point lookFB,			/*<! A Point representing where the Player is looking, and used for front/back movement */
		lookLR;				/*<! A Point representing where the Player is looking, and used for left/right movement */

	//Change in movement
	GLdouble deltaMoveFB,	/*<! Change in movement front/back */
		deltaMoveLR,		/*<! Change in movement left/right */
		deltaMoveUD;		/*<! Change in movement up/down */

	//Rotation
	GLdouble rotLR,			/*<! The Player's left/right rotation */
		rotUD,				/*<! The Player's up/down rotation */
		deltaRotLR,			/*<! The change in Player's rotation left/right */
		deltaRotUD;			/*<! The change in Player's rotation up/down */

	//-------------------------------------------
	// Move the player
	/**
	 *	A normal method
	 *	Moves the Player location forward/backwards
	 */
	void MoveFB();
	/**
	 *	A normal method
	 *	Moves the Player left/right
	 */
	void MoveLR();
	/**
	 *	A normal method
	 *	Moves the Player up/down
	 */
	void MoveUD();
	/**
	 *	A normal method
	 *	Moves the Player's view left/right
	 */
	void LookLR();
	/**
	 *	A normal method
	 *	Moves the Player's view up/down
	 */
	void LookUD();
	//-------------------------------------------
};