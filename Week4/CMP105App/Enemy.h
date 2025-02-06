#pragma once
#include "Framework/GameObject.h"
class Enemy: public GameObject
{
public:
	Enemy();

	Enemy(sf::String TexturePath);

	void Bounce(sf::RenderWindow& window, float dt);

private:

	sf::Texture enemyTexture;

	sf::Vector2f movement;
};

