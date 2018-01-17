// author Peter Lowe
#ifndef GAME
#define GAME

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include "Vector3.h"
#include <gl/GL.h>
#include <gl/GLU.h>

using namespace std;
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
	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();

	sf::RenderWindow m_window; // main SFML window
	bool m_exitGame; // control exiting game


	const int primatives = 4;
};

#endif // !GAME

