#pragma once
#ifndef SNAKE_GAME_HPP_
#define SNAKE_GAME_HPP_

#include "Snake.hpp"
#include "Direction.hpp"
#include "BackgroundGrid.hpp"
#include "GameState.hpp"
#include <SFML/Graphics.hpp>
#include <deque>

class SnakeGame : public GameState
{
	const Direction snakeStartDirection_{ Direction::RIGHT };
	const sf::Color snakeColor_{ 0, 255, 148 };
	const sf::Color snakeDeadColor_{ 178, 181, 186 };
	const sf::Color gridColor1_{ 77, 26, 107 };
	const sf::Color gridColor2_{ 77, 26, 90 };
	static constexpr float cellWidth_ = 16.f;
	static constexpr float snakeMovementPerFrame_ = 16.f;
	static constexpr float entityWidth_ = 15.f; //So that either of the two entities (snake_ /snakeFood_) 
												//are inside, not on top of the cell

	float framesPerSecond_;
	sf::Time timeAccumulator_;

	Snake snake_;
	BackgroundGrid gameMap_;
	std::deque<Direction> directionCommands_;
	sf::RectangleShape snakeFood_;

public:
	SnakeGame(sf::Vector2u windowSize);

	void processNextEvent(const sf::Event& gameEvent) override;
	void update(const sf::Time& deltaTime) override;
	void render(sf::RenderWindow& gameWindow) const override;

	inline void doStateChangeDelay() const override { sf::sleep(sf::milliseconds(750)); };
};

#endif //SNAKE_GAME_HPP_

