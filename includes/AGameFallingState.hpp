#ifndef AGAMEFALLINGSTATE_H
#define AGAMEFALLINGSTATE_H

#include "State.hpp"
#include "StateDef.hpp"
#include "AGameData.hpp"
#include "AGameState.hpp"
#include <SFML/Graphics.hpp>

class AGameFallingState: public AGameState
{

	public:
		AGameFallingState();
		~AGameFallingState();
		virtual void init(sf::RenderWindow&);
		virtual void updateEvent(sf::RenderWindow&, State**, float, sf::Event);
		virtual void update(sf::RenderWindow&, State**, float);
		virtual void draw(sf::RenderWindow&) const;
};

#endif
