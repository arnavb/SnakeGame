#include "SnakeGameApp.hpp"
#include "SnakeGame.hpp"
#include <SFML/Graphics.hpp>
#include <memory>
#include <stdexcept>

SnakeGameApp::SnakeGameApp() :
	gameWindow_{ sf::VideoMode{ windowSize_.x, windowSize_.y}, "Snake!", sf::Style::Close | sf::Style::Titlebar },
	currentState_{ getInitialState() }
{
	gameWindow_.setFramerateLimit(60);
	if (!windowIcon_.loadFromFile("windowIcon.png"))
	{
		throw std::exception{ "Unable to load game image file 'windowIcon.png'. Please check that the file exists in the appropriate application directory!" };
	}
	gameWindow_.setIcon(16, 16, windowIcon_.getPixelsPtr());
}

void SnakeGameApp::processAllEvents()
{
	sf::Event gameEvent;
	while (gameWindow_.pollEvent(gameEvent))
	{
		if ((gameEvent.type == sf::Event::Closed) || ((gameEvent.type == sf::Event::KeyPressed) && (gameEvent.key.code == sf::Keyboard::Escape)))
		{
			gameWindow_.close();
		}
		else
		{
			if (currentState_)
			{
				currentState_->processNextEvent(gameEvent);
			}
		}
	}
}

void SnakeGameApp::updateCurrentState(sf::Time deltaTime)
{
	if (currentState_)
	{
		currentState_->update(deltaTime);
	}
}

void SnakeGameApp::renderCurrentState()
{
	if (currentState_)
	{
		currentState_->render(gameWindow_);
	}
}

void SnakeGameApp::updateStateChange()
{
	if (currentState_->hasStateChange())
	{
		currentState_->doStateChangeDelay();
		currentState_.reset(currentState_->getNextState());
	}
}

void SnakeGameApp::run()
{
	sf::Clock gameClock_;
	while (currentState_ && gameWindow_.isOpen())
	{
		processAllEvents();
		updateCurrentState(gameClock_.restart());
		renderCurrentState();
		updateStateChange();
	}
}