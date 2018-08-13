#pragma once

#include <vector>
#include <ctime>

#include "Actor.h"
#include "Player.h"
#include "Cube.h"

enum KeyCode {
	W,
	A,
	S,
	D,
	Space,
	LeftShift,
	LeftClick,
	RightClick
};

class Game {
public:
	Game();
	~Game();

	void Initialise();

	void Run();

	void Update(float dTime);

	void Draw(float dTime);

	void LoadData();

	void ShutDown();

	void inputDown(unsigned char key, int x, int y);
	void inputUp(unsigned char key, int x, int y);

	void SetKeyDown(bool value, KeyCode key);
	void SetKeyUp(bool value, KeyCode key);

	bool GetKeyDown(KeyCode key);
	bool GetKeyUp(KeyCode key);

private:
	//vector<Model*> models
	//vector<Texture*> textures
	std::vector<Actor> actors;

	Player user;
	Cube a, b, c, d;

	std::vector<bool> KeyDown;
	std::vector<bool> KeyUp;

	float deltaTime;
};
