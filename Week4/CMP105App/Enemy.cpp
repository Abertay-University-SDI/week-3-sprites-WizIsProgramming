#include "Enemy.h"

Enemy::Enemy()
{
	srand(time(0));
	enemyTexture.loadFromFile("gfx/Goomba.png");
	this->setTexture(&enemyTexture);
	this->setSize(sf::Vector2f(100, 100));
	movement.x = 50;
	movement.y = 100;
}

Enemy::Enemy(sf::String TexturePath)
{
	enemyTexture.loadFromFile(TexturePath);
	this->setSize(sf::Vector2f(100, 100));
	movement.x = 100;
	movement.y = 75

}

void Enemy::Bounce(sf::RenderWindow& window, float dt)
{
	this->move(movement * dt);
	if (this->getPosition().x <= 0 || this->getPosition().x >= (window.getSize().x - this->getSize().x))
	{
		movement.x *= -1;
	}

	if (this->getPosition().y <= 0 || this->getPosition().y >= (window.getSize().y - this->getSize().y))
	{
		movement.y *= -1;
	}
}


