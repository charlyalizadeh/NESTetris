#include "../includes/AGameFallingState.hpp"


AGameFallingState::AGameFallingState() {}

AGameFallingState::~AGameFallingState() {}

void AGameFallingState::init(sf::RenderWindow&)
{
	lastFall = 0;
}

void AGameFallingState::updateEvent(sf::RenderWindow& window, State** self, float, sf::Event event)
{
	if(event.type == sf::Event::KeyPressed)
	{
		switch(event.key.code)
		{
			case sf::Keyboard::Right:
				*self = aGameDASRightState;
				(*self)->init(window);
				break;
			case sf::Keyboard::Left:
				*self = aGameDASLeftState;
				(*self)->init(window);
				break;
			case sf::Keyboard::F:
				aGameData->rotateRight();
				break;
			case sf::Keyboard::D:
				aGameData->rotateLeft();
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
	if(aGameData->isMovableDown() && lastFall >= aGameData->getGravity() * aGameData->frameDuration)
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
