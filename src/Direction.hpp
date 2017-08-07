#pragma once
#ifndef DIRECTION_HPP_
#define DIRECTION_HPP_

#include <SFML/Graphics.hpp>

class Direction
{
	int directionNum_;

public:
	enum
	{
		UP = 0,
		DOWN,
		LEFT,
		RIGHT
	};

	Direction(int directionNum);
	explicit operator sf::Vector2f() const;
	friend Direction operator-(const Direction& dir);
	friend bool operator==(const Direction& left, const Direction& right);
	friend bool operator!=(const Direction& left, const Direction& right);
};

#endif //DIRECTION_HPP_
