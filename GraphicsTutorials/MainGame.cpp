#include "MainGame.h"
#include <iostream>
#include <string>


void fatalError(std::string errorString) 
{
	std::cout << errorString << std::endl;
	std::cout << "Enter any key to quit...";
	int tmp;
	std::cin >> tmp;
	SDL_Quit();
}


MainGame::MainGame()
{
	window = nullptr;
	screenWidth = 1024;
	screenHeight = 768;
	gameState = GameState::PLAY;
}


MainGame::~MainGame()
{
}

void MainGame::run()
{
	initSystems();
	sprite.init(-1.0f, -1.0f, 1, 1);
	gameLoop();
}

void MainGame::initSystems()
{
	// Initialize SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow(
		"Game Engine", 
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
		screenWidth, screenHeight, 
		SDL_WINDOW_OPENGL);
	if (window == nullptr)
	{
		fatalError("SDL Window could not be created");
	}

	SDL_GLContext glContext = SDL_GL_CreateContext(window);
	if (glContext == nullptr)
		fatalError("SDL_GL context could not be created");
	
	GLenum glewError = glewInit();
	if (glewError != GLEW_OK)
		fatalError("Glew could not be initialize");

	// Two buffers, one drawing, other cleaning, that avoids flickering
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}

void MainGame::gameLoop() 
{
	while (gameState != GameState::EXIT)
	{
		processInput();
		draw();
	}
}
void MainGame::processInput() 
{
	SDL_Event event;
	while (SDL_PollEvent(&event) == true)
	{
		switch (event.type)
		{
		case SDL_QUIT:
			gameState = GameState::EXIT;
			break;
		case SDL_MOUSEMOTION:
			std::cout << event.motion.x << " " << event.motion.y << std::endl;
			break;
		}
	}
}
void MainGame::draw()
{
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	sprite.draw();

	// Uses the double buffer
	SDL_GL_SwapWindow(window);
}