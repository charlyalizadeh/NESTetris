#ifndef AGAMESTATE_HPP
#define AGAMESTATE_HPP

#include "State.hpp"
#include "StateDef.hpp"
#include <array>

class AGameState: public State
{
	public:
		AGameState();
		~AGameState();
		void init(sf::RenderWindow&);
		virtual void updateEvent(sf::RenderWindow&, State**, float, sf::Event);
		void update(sf::RenderWindow&, State**, float);
		void draw_playfield(sf::RenderWindow&) const;
		void draw(sf::RenderWindow&) const;
		void clearGame(sf::RenderWindow&);
};

#endif
