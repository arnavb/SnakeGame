#include "Direction.hpp"
#include <stdexcept>

Direction::Direction(int directionNum)
{
	if (!(directionNum >= 0 && directionNum <= 3))
	{
		throw std::invalid_argument{ "class 'Direction' was passed invalid constructor argument of 'directionNum'" };
	}
	directionNum_ = directionNum;
}

Direction::operator sf::Vector2f() const
{
	sf::Vector2f result{ 0.f, 0.f };
	switch (directionNum_)
	{
	case UP:
		--result.y;
		break;
	case DOWN:
		++result.y;
		break;
	case LEFT:
		--result.x;
		break;
	case RIGHT:
		++result.x;
	}
	return result;
}

Direction operator-(const Direction& dir)
{
	switch (dir.directionNum_)
	{
	case Direction::UP:
		return Direction::DOWN;
		break;
	case Direction::DOWN:
		return Direction::UP;
		break;
	case Direction::LEFT:
		return Direction::RIGHT;
		break;
	default:
		return Direction::LEFT;
		break;
	}
}

bool operator==(const Direction& left, const Direction& right)
{
	return left.directionNum_ == right.directionNum_;
}

bool operator!=(const Direction& left, const Direction& right)
{
	return !(left == right);
}
