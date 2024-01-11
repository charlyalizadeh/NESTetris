#ifndef AGAMELOCKSTATE_H
#define AGAMELOCKSTATE_H

#include "State.hpp"
#include "StateDef.hpp"
#include "AGameData.hpp"
#include "AGameState.hpp"
#include <SFML/Graphics.hpp>
#include <algorithm>

class AGameLockState: public AGameState
{
	int previousFrameStep;
	std::vector<int> rowsToClear;
	bool noRowToClear;
	int step;
	public:
		AGameLockState();
		~AGameLockState();
		bool checkRowFull(int row) const;
		std::vector<int> getRowToClear() const;
		void init(sf::RenderWindow&);
		void updateStep();
		void update(sf::RenderWindow&, State**, float);
		void drawStep(sf::RenderWindow&) const;
		void draw(sf::RenderWindow&) const;
};

#endif
