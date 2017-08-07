#pragma once
#ifndef GAME_STATE_HPP_
#define GAME_STATE_HPP_

#include <SFML/Graphics.hpp>

class GameState
{
private:
	GameState* nextState_;
	sf::Vector2u windowSize_;

protected:
	void setNextState(GameState* nextState)
	{
		if (hasStateChange())
		{
			delete nextState_;
		}
		nextState_ = nextState;
	};
	inline sf::Vector2u getWindowSize() { return windowSize_; };

public:
	GameState(sf::Vector2u windowSize) : windowSize_{ windowSize }, nextState_ { this } { };
	                                      //nextState_ initialized with 'this' to signify that the state will not change
										  //in the next frame


	virtual void processNextEvent(const sf::Event& gameEvent) = 0;
	virtual void update(const sf::Time& deltaTime) = 0;
	virtual void render(sf::RenderWindow& gameWindow) const = 0;

	inline virtual void doStateChangeDelay() const { };

	inline GameState* getNextState() { return nextState_; };
	inline bool hasStateChange() { return nextState_ != this; };

	virtual ~GameState() { };
};

#endif //GAME_STATE_HPP_