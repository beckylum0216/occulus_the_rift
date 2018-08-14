#pragma once

#include <vector>
#include <ctime>

#include "Actor.h"
#include "Player.h"
#include "Cube.h"

/**
 *	@enum KeyCode
 */
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

/**
 *	@class Game
 *	@brief Is the 'task manager'
 *	@details Loads and manages all aspects of the Game and it's running
 *	
 *	@author Aaron Thomson
 *	@version 1.0
 *	@date 14-08-2018
 */
class Game {
public:
	/**
	 *	A default constructor
	 *	Only calls the Initialise function to create all entities
	 */
	Game();
	/**
	 *	A destructor
	 */
	~Game();

	/**
	 *	A normal member taking no arguments 
	 *	Initialises vectors of Actors, Models, Textures and provides a way for them to be linked together
	 */
	void Initialise();

	/**
	 *	A normal member taking no arguments
	 *	Begins Running game logic by calling Update and Draw
	 */
	void Run();

	/**
	 *	A normal member taking one argument
	 *	Used to call all Update methods of all Actors
	 *	@param dTime A float argument, representing change in time
	 */
	void Update(float dTime);

	/**
	 *	A normal member taking one argument
	 *	Used to call all Run methods of all Actors
	 *	@param dTime A float argument, representing change in time
	 */
	void Draw(float dTime);

	/**
	 *
	 */
	void LoadData();

	/**
	 *	A normal member taking no arguments
	 *	When called, will shut the program down completely
	 */
	void ShutDown();

	/**
	 *	A normal member taking 3 arguments
	 *	Is used to resolve keyboard press input
	 *	@param key The key that was pressed
	 *	@param x The mouse's x position on screen
	 *	@param y The mouse's y position on screen
	 */
	void inputDown(unsigned char key, int x, int y);
	/**
	 *	A normal member taking 3 arguments
	 *	Is used to resolve keyboard release input
	 *	@param key The key released
	 *	@param x The mouse's x position on screen
	 *	@param y The mouse's y position on screen
	 */
	void inputUp(unsigned char key, int x, int y);

	void SetKeyDown(bool value, KeyCode key);
	void SetKeyUp(bool value, KeyCode key);

	bool GetKeyDown(KeyCode key);
	bool GetKeyUp(KeyCode key);

private:
	//vector<Model*> models
	//vector<Texture*> textures
	//std::vector<Actor> actors;

	//--------------------------
	/* Testing purposes */
	/**/ Player user;
	/**/ Cube a, b, c, d;
	//--------------------------
	std::vector<bool> KeyDown;
	std::vector<bool> KeyUp;

	float deltaTime; /*<! A change in time variable */
};
