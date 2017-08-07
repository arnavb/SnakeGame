#include "Snake.hpp"
#include "Direction.hpp"
#include <SFML/Graphics.hpp>
#include <iterator>


sf::RectangleShape Snake::createSnakeNode(sf::Vector2f location)
{
	sf::RectangleShape rectangle{ sf::Vector2f{ bodySize_, bodySize_ } };
	rectangle.setFillColor(bodyColor_);
	rectangle.setPosition(location);
	return rectangle;
}

Snake::Snake(sf::Vector2f startPosition, Direction startDirection, float bodySize, float movementPerFrame, sf::Color bodyColor) :
	currentDirection_{ startDirection },
	bodySize_{ bodySize },
	movementPerFrame_{ movementPerFrame },
	bodyColor_{ bodyColor }
{
	float verticalStartPosition = startPosition.y;
	float horizontalStartPosition = startPosition.x;
	for (int i = 0; i < 4; ++i, horizontalStartPosition -= 16.f)
	{
		bodyParts_.push_back(createSnakeNode(sf::Vector2f{ horizontalStartPosition, verticalStartPosition }));
	}
};

void Snake::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (const auto& rectangle : bodyParts_)
	{
		target.draw(rectangle, states);
	}
}

void Snake::moveForward()
{
	bodyParts_.push_front(bodyParts_.back());
	bodyParts_.pop_back();
	bodyParts_.front().setPosition((*std::next(bodyParts_.begin())).getPosition() + (static_cast<sf::Vector2f>(currentDirection_) * movementPerFrame_));
}

void Snake::changeDirection(Direction newDirection)
{
	if (currentDirection_ != -newDirection)
	{
		currentDirection_ = newDirection;
	}
}

void Snake::increaseSize()
{
	bodyParts_.push_back(createSnakeNode(bodyParts_.back().getPosition()));
}

void Snake::setColor(sf::Color newColor)
{
	bodyColor_ = newColor;
	for (auto& rectangle : bodyParts_)
	{
		rectangle.setFillColor(newColor);
	}
}


bool Snake::collidesWith(const sf::Vector2f& location, bool includesHead) const
{
	if (includesHead)
	{
		for (const auto& bodyPart : bodyParts_)
		{
			if (bodyPart.getPosition() == location)
			{
				return true;
			}
		}
		return false;
	}
	else
	{
		for (auto it = std::next(bodyParts_.begin()); it != bodyParts_.end(); ++it)
		{
			if (it->getPosition() == location)
			{
				return true;
			}
		}
		return false;
	}
}
