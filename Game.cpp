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

void Game::inputDown(unsigned char key, int x, int y) 
{
	KeyCode button = KeyToButton(key);
	SetButtonDown(true, button);
	return;
}

void Game::inputUp(unsigned char key, int x, int y) 
{
	KeyCode button = KeyToButton(key);
	SetButtonUp(true, button);
	return;
}

void Game::SetButtonDown(bool value, KeyCode button) 
{
	KeyDown[button] = value;
	if (value)
	{
		switch (button)
		{
		case keyW:
			user.DirectionFB(1);
			break;
		case keyA:
			user.DirectionLR(-1);
			break;
		case keyS:
			user.DirectionFB(-1);
			break;
		case keyD:
			user.DirectionLR(1);
			break;
		case keyQ:
			user.DirectionLookLR(-1);
			break;
		case keyE:
			user.DirectionLookLR(1);
			break;
		case keyR:
			user.DirectionLookUD(1);
			break;
		case keyF:
			user.DirectionLookUD(-1);
			break;
		}
	}
	return;
}

void Game::SetButtonUp(bool value, KeyCode button) 
{
	KeyUp[button] = value;
	if (value)
	{
		SetButtonDown(false, button);

		switch (button)
		{
		case keyW:
		case keyS:
			user.DirectionFB(0);
			break;
		case keyA:
		case keyD:
			user.DirectionLR(0);
			break;
		case keyQ:
		case keyE:
			user.DirectionLookLR(0);
			break;
		case keyR:
		case keyF:
			user.DirectionLookUD(0);
			break;
		}
	}
	return;
}

bool Game::GetButtonDown(KeyCode button) 
{
	return KeyDown[button];
}

bool Game::GetButtonUp(KeyCode button) 
{
	return KeyUp[button];
}

KeyCode Game::KeyToButton(char key)
{
	KeyCode button;
	switch (key)
	{
	case 27:
		ShutDown();
		break;
	case 'w':
	case 'W':
		button = keyW;
		break;
	case 'a':
	case 'A':
		button = keyA;
		break;
	case 's':
	case 'S':
		button = keyS;
		break;
	case 'd':
	case 'D':
		button = keyD;
		break;
	case 'r':
	case 'R':
	case '8':
		button = keyR;
		break;
	case 'q':
	case 'Q':
	case '4':
		button = keyQ;
		break;
	case 'f':
	case 'F':
	case '2':
		button = keyF;
		break;
	case 'e':
	case 'E':
	case '6':
		button = keyE;
		break;
	case ' ':
		button = keySpace;
		break;
	}
	return button;
}