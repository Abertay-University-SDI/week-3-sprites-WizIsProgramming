#include "Level.h"
#include "Player.h"
#include "Enemy.h"
#include "Background.h"
#include "Cursor.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	new Enemy("gfx/Beach_Ball.png");
	enemyObject1.setPosition(250, 250);
	playerObject.setSize(sf::Vector2f(100, 100));
	playerObject.setPosition(100, 100);
	playerObject.setInput(input);
	cursor.setInput(input);
	view = window->getView();
	window->setMouseCursorVisible(false);
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

	//Move camera with PgUp and PgDn
	if (input->isKeyDown(sf::Keyboard::PageUp) && view.getCenter().x <= (background.getSize().x-(view.getSize().x/2)))
	{
		std::cout << "Move Right" << std::endl;
		view.move(250.f * dt, 0);
	}
	if (input->isKeyDown(sf::Keyboard::PageDown) && view.getCenter().x >= view.getSize().x / 2)
	{
		std::cout << "Move Left" << std::endl;
		view.move(-250.f * dt, 0);
	}


}

// Update game objects
void Level::update(float dt)
{
	cursor.MoveMouse();
	enemyObject1.Bounce(background,dt); //Enemies now bounce within the bounds of the level rather than the bounds of the screen
	enemyObject2.Bounce(background,dt);
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(background);

	window->draw(enemyObject1);

	window->draw(enemyObject2);

	window->draw(playerObject);

	window->draw(cursor);

	window->setView(view);

	endDraw();
}
