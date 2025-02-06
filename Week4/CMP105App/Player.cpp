#include "Player.h"



Player::Player()
{
	playerTexture.loadFromFile("gfx/Mushroom.png");
	//this->setInput(input);
	this->setTexture(&playerTexture);
}

void Player::HandleControls(sf::RenderWindow& window, float dt)
{
	if (input->isKeyDown(sf::Keyboard::Up)&&this->getPosition().y >= 0)
	{
		this->move(0, -100 * dt);
	}
	if (input->isKeyDown(sf::Keyboard::Down) && this->getPosition().y <= (window.getSize().y - this->getSize().y))
	{
		this->move(0, 100 * dt);
	}
	if (input->isKeyDown(sf::Keyboard::Left) && this->getPosition().x >= 0)
	{
		this->move(-100 * dt, 0);
	}
	if (input->isKeyDown(sf::Keyboard::Right) && this->getPosition().x <= (window.getSize().x - this->getSize().x))
	{
		this->move(100 * dt, 0);
	}
	
}
