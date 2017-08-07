#include "SnakeGame.hpp"
#include "Direction.hpp"
#include "VectorUtil.hpp"
#include "GameOver.hpp"
#include <SFML/Graphics.hpp>
#include <deque>
#include <stdexcept>

SnakeGame::SnakeGame(sf::Vector2u windowSize) :
	GameState{ windowSize },
	framesPerSecond_{ 10.f },
	gameMap_{ vector2Cast<float>(getWindowSize()), cellWidth_, gridColor1_, gridColor2_ },
	snake_{ vector2Cast<float>((getWindowSize().x / 2) - (getWindowSize().x / 2) % 16, getWindowSize().y / 2 - (getWindowSize().y / 2) % 16), snakeStartDirection_, entityWidth_, snakeMovementPerFrame_, snakeColor_ }, 
		    //First parameter approximately centers the snake on the map 
	snakeFood_{ sf::Vector2f{ entityWidth_, entityWidth_ } }
{
	snakeFood_.setFillColor(sf::Color::Yellow);
	do
	{
		snakeFood_.setPosition(gameMap_.generateRandomPosition());
	} while (snake_.collidesWith(snakeFood_.getPosition()));
}

void SnakeGame::processNextEvent(const sf::Event& gameEvent)
{
	if (gameEvent.type == sf::Event::KeyPressed)
	{
		switch (gameEvent.key.code)
		{
		case sf::Keyboard::Up:
			directionCommands_.push_back(Direction::UP);
			break;
		case sf::Keyboard::Down:
			directionCommands_.push_back(Direction::DOWN);
			break;
		case sf::Keyboard::Left:
			directionCommands_.push_back(Direction::LEFT);
			break;
		case sf::Keyboard::Right:
			directionCommands_.push_back(Direction::RIGHT);
			break;
		default:
			break;
		}
	}
}

void SnakeGame::update(const sf::Time& deltaTime)
{
	timeAccumulator_ += deltaTime;
	const sf::Time timeStep{ sf::seconds(1.f / framesPerSecond_) };

	if (timeAccumulator_ >= timeStep)
	{
		timeAccumulator_ -= timeStep;

		if (!directionCommands_.empty())
		{
			snake_.changeDirection(directionCommands_.front());
			directionCommands_.pop_front();
		} //This is done to prevent multiple events overlapping in the game, causing the logic of the game to be broken

		sf::Vector2f currentSnakeLocation = snake_.getPosition();

		if (snakeFood_.getPosition() == currentSnakeLocation)
		{
			snake_.increaseSize();
			do
			{
				snakeFood_.setPosition(gameMap_.generateRandomPosition());
			} while (snake_.collidesWith(snakeFood_.getPosition()));

			if ((snake_.length() % 10) == 0) //Increase the speed of the snake every time 10 pieces of food are eaten
											 //by increasing the frames per second
			{
				framesPerSecond_ = (framesPerSecond_ < 20.f) ? (framesPerSecond_ + 1.f) : 20.f;
			}
		}

		if (
			(currentSnakeLocation.x >= gameMap_.getSize().x) ||
			(currentSnakeLocation.x < 0.f) ||
			(currentSnakeLocation.y >= gameMap_.getSize().y) ||
			(currentSnakeLocation.y < 0.f) ||
			(snake_.collidesWith(currentSnakeLocation, false)) //If the snake is out of bounds or has a self collision
			)
		{
			snake_.setColor(snakeDeadColor_);
			setNextState(new GameOver{getWindowSize(), static_cast<int>(snake_.length())});
		}
		else
		{
			snake_.moveForward();
		}
	}
}

void SnakeGame::render(sf::RenderWindow& gameWindow) const
{
	gameWindow.clear();
	gameWindow.draw(gameMap_);
	gameWindow.draw(snake_);
	gameWindow.draw(snakeFood_);
	gameWindow.display();
}