#include "../includes/AGameAREState.hpp"


AGameAREState::AGameAREState()
{
	rng = std::mt19937(dev());
	dist7 = std::uniform_int_distribution<std::mt19937::result_type>(0, 6);
	dist8 = std::uniform_int_distribution<std::mt19937::result_type>(0, 7);
}

AGameAREState::~AGameAREState() {}

void AGameAREState::init(sf::RenderWindow&)
{
	if(aGameData->tetrominoLockRow == - 1)
	{
		aGameData->nextTetromino = Tetromino(getNextType());
		return;
	}
	areFrameDelay = 10 + (5 - (aGameData->tetrominoLockRow + 3) / 4);
	secondsSinceInit = 0;
}

TetrominoType AGameAREState::getNextType()
{
	TetrominoType nextType;
	if(aGameData->currentTetromino.type == TetrominoType::NONE)
		nextType = static_cast<TetrominoType>(dist7(rng));
	else
	{
		nextType = static_cast<TetrominoType>(dist8(rng));
		if(nextType == aGameData->currentTetromino.type || nextType == TetrominoType::NONE)
			nextType = static_cast<TetrominoType>(dist7(rng));
	}
	return nextType;
}

void AGameAREState::setupCurrentTetromino()
{
	aGameData->currentTetromino = Tetromino(aGameData->nextTetromino.type);
	aGameData->tetrominosCount[static_cast<int>(aGameData->currentTetromino.type)]++;
	if(aGameData->currentTetromino.type == TetrominoType::I)
		aGameData->currentTetromino.move({3, 0});
	else if(aGameData->currentTetromino.type == TetrominoType::O)
		aGameData->currentTetromino.move({4, 0});
	else
		aGameData->currentTetromino.move({4, 0});
	aGameData->nextTetromino = Tetromino(getNextType());
	aGameData->updateBoard();
}


void AGameAREState::update(sf::RenderWindow& window, State** self, float fElapsedTime)
{
	secondsSinceInit += fElapsedTime;
	if(aGameData->tetrominoLockRow == -1 || (secondsSinceInit >= aGameData->frameDuration * areFrameDelay))
	{
		setupCurrentTetromino();
		*self = aGameFallingState;
		(*self)->init(window);
	}
}

void AGameAREState::draw(sf::RenderWindow& window) const
{
	AGameState::draw(window);
}
