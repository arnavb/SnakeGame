#pragma once
#ifndef SNAKE_GAME_APP_HPP_
#define SNAKE_GAME_APP_HPP_

#include "MainMenu.hpp"
#include "GameState.hpp"
#include <SFML/Graphics.hpp>
#include <memory>

class SnakeGameApp
{
	const sf::Vector2u windowSize_{ 400, 336 };

	sf::RenderWindow gameWindow_;
	sf::Image windowIcon_;
	std::unique_ptr<GameState> currentState_;

	void processAllEvents();
	void updateCurrentState(sf::Time deltaTime);
	void renderCurrentState();
	void updateStateChange();

	inline std::unique_ptr<GameState> getInitialState() { return std::make_unique<MainMenu>(windowSize_); };

public:
	SnakeGameApp();
	void run();
};


#endif //SNAKE_GAME_APP_HPP_