#include "Player.h"

Player::Player() {
	moveSpeed = 0.0;
	rotateSpeed = 0.0;

	lookFB = { 0.0, 0.0, -1.0 };
	lookLR = { 1.0, 1.0, 0.0 };

	deltaMoveFB = 0.0;
	deltaMoveLR = 0.0;
	deltaMoveUD = 0.0;

	rotLR = 0.0;
	rotUD = 0.0;

	deltaRotLR = 0.0;
	deltaRotUD = 0.0;
}

void Player::Draw() {
//	glTranslatef(position.x, position.y, position.z);
//	glRotatef(rotLR, rotation.x, rotation.y, rotation.z);
//	glScalef(scale.x, scale.y, scale.z);

	//Model and Texture and Collider drawing code
}

void Player::Update() {
	//Process key presses

	Move();

	glLoadIdentity();
	gluLookAt(position.x, position.y, position.z,
		position.x + lookFB.x, position.y + lookFB.y, position.z + lookFB.z,
		0.0, 1.0, 0.0);

}

void Player::SetMoveSpeed(GLdouble tmpSpd) {
	moveSpeed = tmpSpd;
}

void Player::SetRotateSpeed(GLdouble tmpSpd) {
	rotateSpeed = tmpSpd;
}

void Player::DirectionFB(GLdouble const tempMove) {
	deltaMoveFB = tempMove;
}

void Player::DirectionLR(GLdouble const tempMove) {
	deltaMoveLR = tempMove;
}

void Player::DirectionUD(GLdouble const tempMove) {
	deltaMoveUD = tempMove;
}

void Player::DirectionLookLR(GLdouble const tempRot) {
	deltaRotLR = rotateSpeed * tempRot;
}

void Player::DirectionLookUD(GLdouble const tempRot) {
	deltaRotUD = rotateSpeed * tempRot;
}

GLdouble Player::GetLR() {
	return position.x;
}

GLdouble Player::GetUD() {
	return position.y;
}

GLdouble Player::GetFB() {
	return position.z;
}

void Player::Move() {
	if (deltaMoveFB < 0 || deltaMoveFB > 0)
		MoveFB();

	if (deltaMoveLR < 0 || deltaMoveLR > 0)
		MoveLR();

	if (deltaMoveUD < 0 || deltaMoveUD > 0)
		MoveUD();

	if (deltaRotLR / rotateSpeed < 0 || deltaRotLR / rotateSpeed > 0)
		LookLR();

	if (deltaRotUD / rotateSpeed < 0 || deltaRotUD / rotateSpeed > 0)
		LookUD();
}

void Player::MoveFB() {

	GLdouble moveX = deltaMoveFB * lookFB.x * moveSpeed;
	GLdouble moveZ = deltaMoveFB * lookFB.z * moveSpeed;

	position.x += moveX;
	position.z += moveZ;
}

void Player::MoveLR() {

	GLdouble moveX = deltaMoveLR * lookLR.x * moveSpeed;
	GLdouble moveZ = deltaMoveLR * lookLR.z * moveSpeed;

	position.x += moveX;
	position.z += moveZ;
}

void Player::MoveUD() {
	//Throw player into air, apply gravity
}

void Player::LookLR() {
	rotLR += deltaRotLR;

	lookFB.x = sin(rotLR);
	lookFB.z = -cos(rotLR);

	lookLR.x = sin(rotLR + (float)PI/2.0);
	lookLR.z = -cos(rotLR + (float)PI/2.0);
}

void Player::LookUD() {
	rotUD += deltaRotUD;

	lookFB.y = sin(rotUD);

	lookLR.y = sin(rotUD + (float)PI / 2.0);
}
