#include "Level.h"
#include "Player.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	enemyObject1.setPosition(250, 250);
	playerObject.setSize(sf::Vector2f(100, 100));
	playerObject.setPosition(100, 100);
	playerObject.setInput(input);

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	playerObject.HandleControls(*window, dt);
	// Close window on Escape pressed.
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		window->close();
	}

}

// Update game objects
void Level::update(float dt)
{
	enemyObject1.Bounce(*window,dt);
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(enemyObject1);

	window->draw(playerObject);

	endDraw();
}
