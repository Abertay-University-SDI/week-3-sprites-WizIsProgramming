#pragma once
#include "Framework/GameObject.h"
#include "Background.h"

class Enemy: public GameObject
{
public:
	Enemy();

	Enemy(sf::String TexturePath);

	void Bounce(Background window, float dt);

private:

	sf::Texture enemyTexture;

	sf::Vector2f movement;
};

