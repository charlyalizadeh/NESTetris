#ifndef AGAMEDASSTATE_H
#define AGAMEDASSTATE_H

#include "State.hpp"
#include "StateDef.hpp"
#include "AGameData.hpp"
#include "AGameState.hpp"
#include "AGameFallingState.hpp"

enum class DASDirection
{
	Right,
	Left
};

class AGameDASState: public AGameFallingState
{
	// I could do two different states:
	//  - the first move left or right
	//  - the rest of the moves if the left/right key is pressed for a longer time
	// But I feel it's clearer this way
	bool firstMove;
	float lastMove;
	DASDirection direction;
	public:
		AGameDASState(DASDirection direction);
		~AGameDASState();
		void move();
		bool isMovable();
		void init(sf::RenderWindow&);
		void update(sf::RenderWindow&, State**, float);
		void updateEvent(sf::RenderWindow&, State**, float, sf::Event);
		void draw(sf::RenderWindow&) const;
};


#endif
