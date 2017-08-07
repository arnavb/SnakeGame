#pragma once
#ifndef BACKGROUND_GRID_HPP_
#define BACKGROUND_GRID_HPP_

#include <SFML/Graphics.hpp>
#include <vector>
#include <random>

class BackgroundGrid : public sf::Drawable
{
	std::vector<sf::RectangleShape> tiles_;
	sf::Vector2f gridSize_;
	std::random_device randomDevice_;
	std::mt19937 generator_;

public:
	BackgroundGrid(sf::Vector2f gridSize, float squareWidth, sf::Color gridColor1, sf::Color gridColor2);
	sf::Vector2f generateRandomPosition();
	inline sf::Vector2f getSize() { return gridSize_; };
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif //BACKGROUND_GRID_HPP_