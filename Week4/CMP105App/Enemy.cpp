#include "Enemy.h"
#include "Background.h"

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
	this->setTexture(&enemyTexture);
	this->setSize(sf::Vector2f(100, 100));
	movement.x = 100;
	movement.y = 75;

}

void Enemy::Bounce(Background background, float dt)
{
	this->move(movement * dt);
	if (this->getPosition().x <= 0 || this->getPosition().x >= (background.getSize().x - this->getSize().x))
	{
		movement.x *= -1;
	}

	if (this->getPosition().y <= 0 || this->getPosition().y >= (background.getSize().y - this->getSize().y))
	{
		movement.y *= -1;
	}
}


