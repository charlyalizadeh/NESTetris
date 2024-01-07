#include "../includes/AGameFallingState.hpp"


AGameFallingState::AGameFallingState() {}

AGameFallingState::~AGameFallingState() {}

void AGameFallingState::init(sf::RenderWindow&)
{
	lastFall = 0;
}

void AGameFallingState::updateEvent(sf::RenderWindow&, State**, float, sf::Event event)
{
	if(event.type == sf::Event::KeyPressed)
	{
		switch(event.key.code)
		{
			case sf::Keyboard::Right:
				if(aGameData->isMovableRight())
					aGameData->moveRight();
				break;
			case sf::Keyboard::Left:
				if(aGameData->isMovableLeft())
					aGameData->moveLeft();
				break;
			default:
				break;
		}
	}
}

void AGameFallingState::update(sf::RenderWindow& window, State** self, float fElapsedTime)
{
	AGameState::update(window, self, fElapsedTime);
	lastFall += fElapsedTime;
	if(aGameData->isMovableDown() && lastFall >= aGameData->getGravity() * (1.0 / 60.0988))
	{
		aGameData->moveDown();
		lastFall = 0;
	}
	if(!aGameData->isMovableDown())
	{
		aGameData->setLockRow();
		*self = aGameAREState;
		(*self)->init(window);
	}
}

void AGameFallingState::draw(sf::RenderWindow& window) const
{
	AGameState::draw(window);
}
