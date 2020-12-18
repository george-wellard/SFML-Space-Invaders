#include "GameOverState.h"

GameOverState::GameOverState(GameDataRef data) : _data(data)
{
}

void GameOverState::Init()
{
	_data->assets.LoadTexture("Background Texture", BACKGROUND_TEX);
	_data->assets.LoadTexture("Button Texture", PLAY_BUTTON_TEX);

	_data->assets.LoadFont("Font", FONT);

	background = new Background(_data);

	title.setOrigin(title.getGlobalBounds().width / 2, title.getGlobalBounds().height / 2);
	title.setPosition(SCREEN_WIDTH / 3, SCREEN_HEIGHT / 4);
	title.setFont(this->_data->assets.GetFont("Font"));
	title.setString("GAME OVER");
	title.setCharacterSize(56);
	title.setFillColor(sf::Color::White);

	Button.setOrigin(Button.getGlobalBounds().width / 2, Button.getGlobalBounds().height / 2);
	Button.setPosition(SCREEN_WIDTH / 2 - 150, SCREEN_HEIGHT / 2 + 75);
	Button.setTexture(this->_data->assets.GetTexture("Button Texture"));
}

void GameOverState::HandleInput()
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

void GameOverState::Update(float dt)
{
}

void GameOverState::Draw(float dt)
{
	_data->window.clear(); 

	background->Draw();

	_data->window.draw(Button);
	_data->window.draw(title);

	_data->window.display();
}
