#pragma once
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "State.h"
#include "StateMachine.h"
#include "Game.h"
#include "Definitions.h"
#include "AssetManager.h"
#include "Background.h"
#include "GameState.h"

class SplashState : public State
{
public:

	SplashState(GameDataRef data);

	void Init();

	void HandleInput();

	void Update(float dt);

	void Draw(float dt);

private:

	GameDataRef _data;

	sf::Event event;

	sf::Sprite Logo;
	sf::Sprite Button; 

	Background* background; 

};