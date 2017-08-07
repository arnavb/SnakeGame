#include "GameOver.hpp"
#include "GameState.hpp"
#include "SnakeGame.hpp"
#include "VectorUtil.hpp"
#include <SFML/Graphics.hpp>
#include <string>
#include <stdexcept>

GameOver::GameOver(sf::Vector2u windowSize, int gameScore) :
	GameState{windowSize},
	scoreString_{"Score: " + std::to_string(gameScore)}
{
	if (!gameOverFont_.loadFromFile("SFPixelate-Bold.ttf"))
	{
		throw std::exception{ "Unable to load game font file 'SFPixelate-Bold.ttf'.Please check that the file exists in the appropriate application directory!" };
	}
	gameOverText_.setString("GAME OVER!");
	scoreText_.setString(scoreString_);
	restartText_.setString("Press SPACE to restart!");

	gameOverText_.setFont(gameOverFont_);
	scoreText_.setFont(gameOverFont_);
	restartText_.setFont(gameOverFont_);

	gameOverText_.setCharacterSize(48);
	scoreText_.setCharacterSize(32);
	restartText_.setCharacterSize(20);

	gameOverText_.setOrigin(gameOverText_.getGlobalBounds().width / 2.f, gameOverText_.getGlobalBounds().height / 2.f);
	scoreText_.setOrigin(scoreText_.getGlobalBounds().width / 2.f, scoreText_.getGlobalBounds().height / 2.f);
	restartText_.setOrigin(restartText_.getGlobalBounds().width / 2.f, restartText_.getGlobalBounds().height / 2.f);

	gameOverText_.setPosition(vector2Cast<float>(getWindowSize().x / 2u, getWindowSize().y / 4u));
	scoreText_.setPosition(static_cast<float>(getWindowSize().x / 2u), gameOverText_.getPosition().y + 50.f);
	restartText_.setPosition(vector2Cast<float>(getWindowSize() / 2u));

}

void GameOver::processNextEvent(const sf::Event& gameEvent)
{
	if ((gameEvent.type == sf::Event::KeyPressed) && (gameEvent.key.code == sf::Keyboard::Space))
	{
		setNextState(new SnakeGame{ getWindowSize() }); //Restart the game
	}
}

void GameOver::update(const sf::Time& deltaTime)
{
}

void GameOver::render(sf::RenderWindow& gameWindow) const
{
	gameWindow.clear();
	gameWindow.draw(gameOverText_);
	gameWindow.draw(scoreText_);
	gameWindow.draw(restartText_);
	gameWindow.display();
}
