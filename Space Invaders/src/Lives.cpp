#include "Lives.h"

Lives::Lives(GameDataRef data) : _data(data)
{
	life.setTexture(_data->assets.GetTexture("Life Texture"));
}

void Lives::setPos(float x, float y)
{
	life.setPosition(x, y);
}

void Lives::Draw()
{
	_data->window.draw(life);
}

sf::Sprite Lives::getSprite()
{
	return sf::Sprite();
}
