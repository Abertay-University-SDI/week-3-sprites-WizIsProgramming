#include "Background.h"

Background::Background()
{
	BackgroundTexture.loadFromFile("gfx/Level1_1.png");
	this->setTexture(&BackgroundTexture);
	this->setSize(sf::Vector2f(11038, 675));

}
