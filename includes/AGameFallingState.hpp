#ifndef AGAMEFALLINGSTATE_H
#define AGAMEFALLINGSTATE_H

#include "State.hpp"
#include "StateDef.hpp"
#include "AGameData.hpp"
#include "AGameState.hpp"
#include <SFML/Graphics.hpp>

class AGameFallingState: public AGameState
{
	float lastFall;

	public:
		AGameFallingState();
		~AGameFallingState();
		void init(sf::RenderWindow&);
		void updateEvent(sf::RenderWindow&, State**, float, sf::Event);
		void update(sf::RenderWindow&, State**, float);
		void draw(sf::RenderWindow&) const;
};

#endif
