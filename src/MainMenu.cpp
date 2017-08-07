#include "MainMenu.hpp"
#include "VectorUtil.hpp"
#include "SnakeGame.hpp"
#include <SFML/Graphics.hpp>
#include <stdexcept>

MainMenu::MainMenu(sf::Vector2u windowSize) :
	GameState{ windowSize },
	introTextInPlace_{ false }
{
	if (!introTextFont_.loadFromFile("karmaticArcade.ttf"))
	{
		throw std::exception{ "Unable to load game font file 'karmaticArcade.ttf'.Please check that the file exists in the appropriate application directory!" };
	}
	if (!confirmPlayFont_.loadFromFile("pixelFont7.ttf"))
	{
		throw std::exception{ "Unable to load game font file 'pixelFont7.ttf'.Please check that the file exists in the appropriate application directory!" };
	}
	introText_.setString("Snake!");
	confirmPlay_.setString("Press SPACE to begin!");

	introText_.setFont(introTextFont_);
	confirmPlay_.setFont(confirmPlayFont_);

	introText_.setFillColor(sf::Color::White);
	confirmPlay_.setFillColor(sf::Color::Transparent);

	introText_.setCharacterSize(48);
	confirmPlay_.setCharacterSize(24);

	introText_.setOrigin(introText_.getGlobalBounds().width / 2, introText_.getGlobalBounds().height / 2);
	confirmPlay_.setOrigin(introText_.getGlobalBounds().width / 2, introText_.getGlobalBounds().height / 2);

	introText_.setPosition(static_cast<float>(getWindowSize().x / 2u), 0.f); //At the top of the screen at the beginning
	confirmPlay_.setPosition(vector2Cast<float>(getWindowSize() / 2u)); //In the middle of the screen
}

void MainMenu::processNextEvent(const sf::Event& gameEvent)
{
	if ((gameEvent.type == sf::Event::KeyPressed) && (gameEvent.key.code == sf::Keyboard::Space) && (introTextInPlace_))
	{
		setNextState(new SnakeGame{ getWindowSize() });
	}
}

void MainMenu::update(const sf::Time& deltaTime)
{
	if (!introTextInPlace_)
	{
		introText_.move(textMovement_ * deltaTime.asSeconds());
		if (introText_.getPosition().y >= (getWindowSize().y / 4.5))
		{
			introTextInPlace_ = true;
		}
	}
	if (introTextInPlace_)
	{
		confirmPlay_.setFillColor(sf::Color::White); //The 'Snake!' text is in place, so now display the instructions
	}
}

void MainMenu::render(sf::RenderWindow& gameWindow) const
{
	gameWindow.clear(windowBackgroundColor_);
	gameWindow.draw(introText_);
	gameWindow.draw(confirmPlay_);
	gameWindow.display();
}
