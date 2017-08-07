#include "BackgroundGrid.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>

BackgroundGrid::BackgroundGrid(sf::Vector2f gridSize, float squareWidth, sf::Color gridColor1, sf::Color gridColor2) :
	gridSize_{ gridSize },
	generator_{ randomDevice_() }
{
	for (float i = 0.f; i < gridSize.x; i += squareWidth)
	{
		for (float j = 0.f; j < gridSize.y; j += squareWidth)
		{
			sf::RectangleShape nextTile{ sf::Vector2f{ squareWidth, squareWidth } };
			nextTile.setPosition(sf::Vector2f{ i, j });
			nextTile.setOutlineColor(sf::Color::Black);
			nextTile.setOutlineThickness(.5f);

			if (std::fmod(i + j, squareWidth * 2.f) == 0)
			{
				nextTile.setFillColor(gridColor1);
			}
			else
			{
				nextTile.setFillColor(gridColor2);
			}
			tiles_.push_back(nextTile);
		}
	}
}

sf::Vector2f BackgroundGrid::generateRandomPosition()
{
	std::uniform_int_distribution<size_t> randomDistribution{ 0, tiles_.size() - 1 };
	return tiles_[randomDistribution(generator_)].getPosition();
}

void BackgroundGrid::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (const auto& rectangle : tiles_)
	{
		target.draw(rectangle, states);
	}
}
