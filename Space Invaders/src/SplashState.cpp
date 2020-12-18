#include "SplashState.h"

SplashState::SplashState(GameDataRef data) : _data(data)
{
}

void SplashState::Init()
{
	_data->assets.LoadTexture("Background Texture", BACKGROUND_TEX);
	_data->assets.LoadTexture("Button Texture", PLAY_BUTTON_TEX);
	_data->assets.LoadTexture("Logo Texture", LOGO_TEX);

	background = new Background(_data);

	Logo.setOrigin(Logo.getGlobalBounds().width / 2, Logo.getGlobalBounds().height / 2);
	Logo.setPosition(SCREEN_WIDTH / 14, SCREEN_HEIGHT / 8);
	Logo.setTexture(this->_data->assets.GetTexture("Logo Texture"));

	Button.setOrigin(Button.getGlobalBounds().width / 2, Button.getGlobalBounds().height / 2);
	Button.setPosition(SCREEN_WIDTH / 2 - 150, SCREEN_HEIGHT / 2 + 75);
	Button.setTexture(this->_data->assets.GetTexture("Button Texture"));
}

void SplashState::HandleInput()
{
	while (_data->window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			_data->window.close();
		}

		if (_data->input.IsSpriteClicked(Button, sf::Mouse::Left, _data->window))
		{
			_data->machine.AddState(StateRef(new GameState(_data)), true);
		}
	}
}

void SplashState::Update(float dt)
{
}

void SplashState::Draw(float dt)
{
	_data->window.clear();

	background->Draw();

	_data->window.draw(Logo);
	
	_data->window.draw(Button);

	_data->window.display();
}
