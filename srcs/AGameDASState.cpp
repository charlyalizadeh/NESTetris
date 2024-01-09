#include "../includes/AGameDASState.hpp"

AGameDASState::AGameDASState(DASDirection direction): direction(direction) {}

AGameDASState::~AGameDASState() {}

void AGameDASState::move()
{
	if(direction == DASDirection::Right && aGameData->isMovableRight())
		aGameData->moveRight();
	else if(direction == DASDirection::Left && aGameData->isMovableLeft())
		aGameData->moveLeft();
}

bool AGameDASState::isMovable()
{
	if(direction == DASDirection::Right)
		return aGameData->isMovableRight();
	return aGameData->isMovableLeft();
}

void AGameDASState::init(sf::RenderWindow& window)
{
	AGameFallingState::init(window);
	move();
	firstMove = true;
	lastMove = 0;
}

void AGameDASState::updateEvent(sf::RenderWindow& window, State** self, float, sf::Event event)
{
	if(event.type == sf::Event::KeyPressed)
	{
		switch(event.key.code)
		{
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
	if(event.type == sf::Event::KeyReleased)
	{
		switch(event.key.code)
		{
			case sf::Keyboard::Right:
				if(direction == DASDirection::Right)
				{
					*self = aGameFallingState;
					(*self)->init(window);
				}
				break;
			case sf::Keyboard::Left:
				if(direction == DASDirection::Left)
				{
					*self = aGameFallingState;
					(*self)->init(window);
				}
				break;
			default:
				break;
		}
	}
}

void AGameDASState::update(sf::RenderWindow& window, State** self, float fElapsedTime)
{
	AGameFallingState::update(window, self, fElapsedTime);
	lastMove += fElapsedTime;
	if(firstMove && lastMove >= 16 * aGameData->frameDuration)
	{
		move();
		firstMove = false;
		lastMove = 0;
	}
	else if(!firstMove && lastMove >= 6 * aGameData->frameDuration)
	{
		move();
		lastMove = 0;
	}
}

void AGameDASState::draw(sf::RenderWindow& window) const
{
	AGameState::draw(window);
}
