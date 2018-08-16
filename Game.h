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
	keyW=1,
	keyw=1,
	keyA=2,
	keya=2,
	keyS=3,
	keys=3,
	keyD=4,
	keyd=4,
	keyR=5,
	keyr=5,
	upArrow=5,
	keyQ=6,
	keyq=6,
	leftArrow=6,
	keyF=7,
	keyf=7,
	downArrow=7,
	keyE=8,
	keye=8,
	rightArrow=8,
	keySpace=9,
	leftShift=10,
	leftClick=11,
	rightClick=12,
	MAX_KeyCode
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

	void SetButtonDown(bool value, KeyCode button);
	void SetButtonUp(bool value, KeyCode button);

	bool GetButtonDown(KeyCode button);
	bool GetButtonUp(KeyCode button);

	/**
	* A normal member taking 1 argument
	* Is used to convert a char representing a key to an enum representing an ingame action
	* @param key the key to be converted
	*/
	KeyCode KeyToButton(char key);

private:
	//vector<Model*> models
	//vector<Texture*> textures
	//std::vector<Actor> actors;

	//--------------------------
	/* Testing purposes */
	/**/ Player user;
	/**/ Cube a, b, c, d;
	//--------------------------
	bool KeyDown[MAX_KeyCode];
	bool KeyUp[MAX_KeyCode];

	float deltaTime; /*<! A change in time variable */
};
