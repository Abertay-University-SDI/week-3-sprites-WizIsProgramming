#include "Cursor.h"
#include <iostream>

Cursor::Cursor()
{
	mouseTexture.loadFromFile("gfx/icon.png");
	this->setTexture(&mouseTexture);
	this->setSize(sf::Vector2f(50,50));
}

void Cursor::MoveMouse()
{
	this->setPosition(input->getMouseX(), input->getMouseY());
}