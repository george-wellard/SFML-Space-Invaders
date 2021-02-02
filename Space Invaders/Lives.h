#pragma once
#include "Game.h"

class Lives
{

public:

	Lives(GameDataRef data);

	void setPos();

	void Draw();

	sf::Sprite getSprite(); 

private:

	GameDataRef _data;

	sf::Sprite life;

	sf::Texture lifeTex;

};

