#include "../includes/AGameAREState.hpp"


AGameAREState::AGameAREState()
{
	rng = std::mt19937(dev());
	dist6 = std::uniform_int_distribution<std::mt19937::result_type>(0, 5);
	dist7 = std::uniform_int_distribution<std::mt19937::result_type>(0, 6);
}

AGameAREState::~AGameAREState() {}

void AGameAREState::init(sf::RenderWindow&) {}

void AGameAREState::update(sf::RenderWindow& window, State** self, float fElapsedTime)
{
	AGameState::update(window, self, fElapsedTime);
	TetrominoType nextType;
	if(aGameData->currentTetromino.type == TetrominoType::NONE)
		nextType = static_cast<TetrominoType>(dist6(rng));
	else
	{
		nextType = static_cast<TetrominoType>(dist7(rng));
		if(nextType == aGameData->currentTetromino.type || nextType == TetrominoType::NONE)
			nextType = static_cast<TetrominoType>(dist6(rng));
	}
	aGameData->currentTetromino = Tetromino(nextType);
	if(nextType == TetrominoType::L)
		aGameData->currentTetromino.move({3, 0});
	else if(nextType == TetrominoType::O)
		aGameData->currentTetromino.move({4, 0});
	else
		aGameData->currentTetromino.move({4, 0});
	aGameData->updateBoard();
	*self = aGameFallingState;
}

void AGameAREState::draw(sf::RenderWindow& window) const
{
	AGameState::draw(window);
}
