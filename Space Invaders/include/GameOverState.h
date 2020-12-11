#pragma once
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "State.h"
#include "StateMachine.h"
#include "Game.h"
#include "Definitions.h"
#include "AssetManager.h"

class GameOverState : public State
{
public:

	GameOverState(GameDataRef data);

	void Init();

	void Input();

	void Update();

	void Draw();

private:

	GameDataRef _data;

};