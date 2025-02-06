#pragma once
#include "Framework/Input.h"
#include "Framework/GameObject.h"

class Cursor: public GameObject
{

public:

	Cursor();
	void MoveMouse();

private:

	sf::Texture mouseTexture;
};

