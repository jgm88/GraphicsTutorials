#pragma once
#include <GL/glew.h>

class Sprite
{
public:
	//Sprite(int x, int y, int width, int height) : x(x), y(y), width(width), height(height)
	//{
	//}
	Sprite();
	~Sprite();

	void init(int x, int y, int width, int height);
	void draw();

private:

	int x;
	int y;
	int width;
	int height;

	// Vertex buffer
	GLuint vboID;
};

