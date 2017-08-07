#pragma once
#ifndef SNAKE_HPP_
#define SNAKE_HPP_

#include "Direction.hpp"
#include <SFML/Graphics.hpp>
#include <list>

class Snake : public sf::Drawable
{
	std::list<sf::RectangleShape> bodyParts_;
	Direction currentDirection_;
	const float bodySize_;
	const float movementPerFrame_;
	sf::Color bodyColor_;

	sf::RectangleShape createSnakeNode(sf::Vector2f location);

public:
	Snake(sf::Vector2f startPosition, Direction startDirection, float bodySize, float movementPerFrame, sf::Color bodyColor);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	void changeDirection(Direction newDirection);
	void moveForward();
	void increaseSize();
	void setColor(sf::Color newColor);
	inline void setHeadColor(sf::Color newColor) { bodyParts_.front().setFillColor(newColor); };

	bool collidesWith(const sf::Vector2f& location, bool includesHead = true) const;

	inline Direction getDirection() const { return currentDirection_; };
	inline sf::Vector2f getPosition() const { return bodyParts_.front().getPosition(); };
	inline size_t length() const { return bodyParts_.size(); };
};

#endif //SNAKE_HPP_