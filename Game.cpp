#include <iostream>
#include "Game.h"

Game::Game() {
	//Initialise all Actors
	Initialise();
}

Game::~Game() {

}

void Game::Initialise() {
	deltaTime = clock();

	user.SetMoveSpeed(0.05);
	user.SetRotateSpeed(0.0005);
}

void Game::Run() {
	Update(deltaTime);

	Draw(deltaTime);
}

void Game::Update(float dTime) {
	//Loop and update each actor as necessary
	user.Update();
}

void Game::Draw(float dTime) {
	//Loop and draw each actor in a scene
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	user.Draw();

	glPushMatrix();
		glTranslatef(5.0, 0.0, 0.0);
		a.Draw();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-5.0, 0.0, 0.0);
		b.Draw();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0, 0.0, 5.0);
		c.Draw();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0, 0.0, -5.0);
		d.Draw();
	glPopMatrix();

	glFlush();
}

void Game::LoadData() {

}

void Game::ShutDown() {
	exit(0);
}

void Game::inputDown(unsigned char key, int x, int y) {
	switch (key) {
	case 'a':
	case 'A':
		user.DirectionLR(-1);
		break;
	case 'd':
	case 'D':
		user.DirectionLR(1);
		break;
	case 'w':
	case 'W':
		user.DirectionFB(1);
		break;
	case 's':
	case 'S':
		user.DirectionFB(-1);
		break;
	case 'q':
	case 'Q':
		user.DirectionLookLR(-1);
		break;
	case 'e':
	case 'E':
		user.DirectionLookLR(1);
		break;
	case 27:
		ShutDown();
		break;
	}
}

void Game::inputUp(unsigned char key, int x, int y) {
	switch (key) {
	case 'a':
	case 'A':
	case 'd':
	case 'D':
		user.DirectionLR(0);
		break;
	case 'w':
	case 'W':
	case 's':
	case 'S':
		user.DirectionFB(0);
		break;
	case 'q':
	case 'Q':
	case 'e':
	case 'E':
		user.DirectionLookLR(0);
		break;
	}
}

void Game::SetKeyDown(bool value, KeyCode key) {

}

void Game::SetKeyUp(bool value, KeyCode key) {

}

bool Game::GetKeyDown(KeyCode key) {
	return KeyDown[key];
}

bool Game::GetKeyUp(KeyCode key) {
	return KeyUp[key];
}
