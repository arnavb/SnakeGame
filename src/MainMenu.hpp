#pragma once
#ifndef MAIN_MENU_HPP_
#define MAIN_MENU_HPP_

#include "GameState.hpp"
#include <SFML/Graphics.hpp>

class MainMenu : public GameState
{
	const sf::Color windowBackgroundColor_{ 77, 26, 90 };

	sf::Font introTextFont_;
	sf::Font confirmPlayFont_;
	sf::Text introText_;
	sf::Text confirmPlay_;
	const sf::Vector2f textMovement_{ 0.f, 50.f };
	bool introTextInPlace_;

public:
	MainMenu(sf::Vector2u windowSize);

	void processNextEvent(const sf::Event& gameEvent) override;
	void update(const sf::Time& deltaTime) override;
	virtual void render(sf::RenderWindow& gameWindow) const override;

};

#endif //MAIN_MENU_HPP_