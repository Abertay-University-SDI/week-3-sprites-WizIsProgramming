#pragma once
#include "Framework/GameObject.h"
class Player: public GameObject
{

public:

	Player();

	void HandleControls(sf::RenderWindow& window, float dt);

private:
	sf::Texture playerTexture;

};