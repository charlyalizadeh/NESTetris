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
		virtual void init(sf::RenderWindow&);
		virtual void updateEvent(sf::RenderWindow&, State**, float, sf::Event);
		virtual void update(sf::RenderWindow&, State**, float);
		void drawPlayfield(sf::RenderWindow&) const;
		void drawNextTetromino(sf::RenderWindow&) const;
		virtual void draw(sf::RenderWindow&) const;
		void clearGame(sf::RenderWindow&);
};

#endif
