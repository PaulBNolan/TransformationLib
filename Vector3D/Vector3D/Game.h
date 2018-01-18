// author Peter Lowe
#ifndef GAME
#define GAME

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Vector3.h"
#include "Matrix3.h"
using namespace std;
using namespace sf;

class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();

private:
	GLuint index;

	Vector3D position;
	Matrix3 rotation;


	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();

	Window m_window; // main SFML window
	bool m_exitGame = false; // control exiting game

	const int primatives = 4;
};

#endif // !GAME

