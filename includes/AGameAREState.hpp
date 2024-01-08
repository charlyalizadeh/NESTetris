#ifndef AGAMEARESTATE_H
#define AGAMEARESTATE_H

#include "State.hpp"
#include "StateDef.hpp"
#include "AGameData.hpp"
#include "AGameState.hpp"
#include <SFML/Graphics.hpp>
#include <random>

class AGameAREState: public AGameState
{
	std::random_device dev;
	std::mt19937 rng;
	std::uniform_int_distribution<std::mt19937::result_type> dist7;
	std::uniform_int_distribution<std::mt19937::result_type> dist8;
	float areFrameDelay;
	float secondsSinceInit;

	public:
		AGameAREState();
		~AGameAREState();
		void init(sf::RenderWindow&);
		void setUpNextTetromino();
		void update(sf::RenderWindow&, State**, float);
		void draw(sf::RenderWindow&) const;
};

#endif
