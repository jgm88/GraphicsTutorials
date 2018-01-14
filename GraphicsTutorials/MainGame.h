#pragma once
#include <SDL/SDL.h>
#include <GL/glew.h>

#include "Sprite.h"

enum class GameState 
{
	PLAY,
	EXIT
};

class MainGame
{
public:
	MainGame();
	~MainGame();

	void run();	

private:
	void initSystems();
	void gameLoop();
	void processInput();
	void draw();

	SDL_Window* window;
	int screenWidth;
	int screenHeight;
	GameState gameState;

	Sprite sprite;
};

