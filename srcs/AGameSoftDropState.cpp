#include "../includes/AGameSoftDropState.hpp"


AGameSoftDropState::AGameSoftDropState() {}

AGameSoftDropState::~AGameSoftDropState() {}

void AGameSoftDropState::init(sf::RenderWindow&)
{
	lastFall = 0;
}

void AGameSoftDropState::updateEvent(sf::RenderWindow& window, State** self, float, sf::Event event)
{
	if(event.type == sf::Event::KeyReleased)
	{
		switch(event.key.code)
		{
			case sf::Keyboard::Down:
				aGameData->isDownPressed = false;
				*self = aGameFallingState;
				(*self)->init(window);
				break;
			default:
				break;
		}
	}
}

void AGameSoftDropState::update(sf::RenderWindow& window, State** self, float fElapsedTime)
{
	AGameState::update(window, self, fElapsedTime);
	lastFall += fElapsedTime;
	if(aGameData->isMovableDown() && lastFall >= 2 * aGameData->frameDuration)
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

void AGameSoftDropState::draw(sf::RenderWindow& window) const
{
	AGameState::draw(window);
}
