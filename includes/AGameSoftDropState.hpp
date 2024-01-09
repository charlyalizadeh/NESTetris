#ifndef AGAMESOFTDROPSTATE_H
#define AGAMESOFTDROPSTATE_H

#include "State.hpp"
#include "StateDef.hpp"
#include "AGameData.hpp"
#include "AGameState.hpp"
#include <SFML/Graphics.hpp>
#include <random>

class AGameSoftDropState: public AGameState
{
	float lastFall;

	public:
		AGameSoftDropState();
		~AGameSoftDropState();
		virtual void init(sf::RenderWindow&);
		virtual void updateEvent(sf::RenderWindow&, State**, float, sf::Event);
		virtual void update(sf::RenderWindow&, State**, float);
		virtual void draw(sf::RenderWindow&) const;
};

#endif
