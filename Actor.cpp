#include "Actor.h"

Actor::Actor() {
	position = { 0.0, 0.0, 0.0 };
	rotation = { 0.0, 0.0, 0.0 };
	scale = { 1.0, 1.0, 1.0 };
}

void Actor::Update() {
	//Based on input, do something
}

void Actor::Draw() {
	//Draw at position, according to rotation, apply scale
	//Draw Model, apply Texture, construct Collider box
}

void Actor::SetPos(GLdouble tempX, GLdouble tempY, GLdouble tempZ) {
	position = { tempX, tempY, tempZ };
}

void Actor::SetPos(Point pos) {
	position = { pos.x, pos.y, pos.z };
}

void Actor::SetRot(GLdouble rotX, GLdouble rotY, GLdouble rotZ) {
	rotation = { rotX, rotY, rotZ };
}

void Actor::SetRot(Point rot) {
	rotation = { rot.x, rot.y, rot.z };
}

void Actor::SetScale(GLdouble scaX, GLdouble scaY, GLdouble scaZ) {
	scale = { scaX, scaY, scaZ };
}

void Actor::SetScale(Point sca) {
	scale = { sca.x, sca.y, sca.z };
}

void Actor::SetTagType(Tag type) {
	tagType = type;
}

Point Actor::GetPos() {
	return position;
}

Point Actor::GetRot() {
	return rotation;
}

Point Actor::GetScale() {
	return scale;
}

Tag Actor::GetTagType() {
	return tagType;
}


