#pragma once

#include <gl\glut.h>

#define PI 3.141592654

/**
 *	@struct Point
 *	Defines a point in 3D space
 */
struct Point {
	GLdouble x, /*<! The position on the x plane */
		y,		/*<! The position on the y plane */
		z;		/*<! The positoin on the z plane */
};

/**
 *	@enum Tag
 *	Defines a type of Actor
 */
enum Tag {
	
};

/**
 *	@class Actor
 *	@brief
 *	@details
 *
 *	@author Aaron Thomson
 *	@version 1.0
 *	@date 14-08-2018
 */
class Actor {
public:
	/**
	 *	A default constructor
	 */
	Actor();
	//Actor(Model, Texture, Collision, pos, rot, sca, tag);

	/**
	 *	A virtual member
	 */
	virtual void Update();
	/**
	 *	A virtual member
	 */
	virtual void Draw();

	//--------------------------------------------------------------
	// Set methods
	/**
	 *	A normal member taking 3 arguments
	 *	Sets the Actor's position in the 3D world
	 *	@param tempX The desired x position
	 *	@param tempY The desired y position
	 *	@param tempZ The desired z position
	 */
	void SetPos(GLdouble tempX, GLdouble tempY, GLdouble tempZ);
	/**
	 *	A normal member taking one argument
	 *	Sets the Actor's position in the 3D world
	 *	@param pos The desired Point poisition
	 */
	void SetPos(Point pos);
	/**
	 *	A normal member taking three arguments
	 *	Sets the Actor's rotation around individual axis
	 *	@param rotX The degree of rotation around the x axis
	 *	@param rotY The degree of rotation around the y axis
	 *	@param rotZ The degree of rotation around the z axis
	 */
	void SetRot(GLdouble rotX, GLdouble rotY, GLdouble rotZ);
	/**
	 *	A normal member taking one argument
	 *	Sets the Actor's rotation about points
	 *	@param rot The matrix representing desired rotation values
	 */
	void SetRot(Point rot);
	/**
	 *	A normal member taking three arguments
	 *	Sets the Actor's scale in the world
	 *	@param scaX The desired scale factor along the x-axis
	 *	@param scaY The desired scale factor along the y-axis
	 *	@param scaZ The desired scale factor along the z-axis
	 */
	void SetScale(GLdouble scaX, GLdouble scaY, GLdouble scaZ);
	/**
	 *	A normal member taking one argument
	 *	Sets the Actor's scale in the world
	 *	@param sca The scale values to apply
	 */
	void SetScale(Point sca);

	/**
	 *	A normal member taking one argument
	 *	Sets the type of Tag the Actor can be
	 *	@param type The type of Tag to assign to the actor
	 */
	void SetTagType(Tag type);

	/*	FindModel
		FindTex
		FindCollider
	*/
	//--------------------------------------------------------------

	//--------------------------------------------------------------
	// Get methods
	/**
	 *	A normal member returning a Point value
	 *	Returns the current position values
	 *	@return The position values
	 */
	Point GetPos();
	/**
	 *	A normal member returning a Point value
	 *	Returns roatation values aroundaeach axis
	 *	@return The Rotation values around the respective axis
	 */
	Point GetRot();
	/**
	 *	A normal member returning a Point value
	 *	Returns the current scale values
	 *	@return The scale values
	 */
	Point GetScale();
	/**
	 *	A normal member returning a Tag
	 *	Returns the type of Tag associated with the Actor
	 *	@return The Tag value assigned
	 */
	Tag GetTagType();
	//--------------------------------------------------------------

	bool TestCollision();

	
protected:
	Point	position,	/*<! The position of the Actor */
			rotation,	/*<! The rotation of the Actor */
			scale;		/*<! The scale of the Actor */

	Tag		tagType;	/*<! The Tag associated with the Actor*/

	//Model*
	//Texture*
	//Collision

	//---------------------------------------------------------------
	//void RotX();
	//void RotY();
	//void RotZ();
	//---------------------------------------------------------------
};
