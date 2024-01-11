#include "../includes/AGameLockState.hpp"

AGameLockState::AGameLockState() {}

AGameLockState::~AGameLockState() {}

bool AGameLockState::checkRowFull(int row) const
{
	for(int x = 0; x < 10; x++)
	{
		if(aGameData->board[row * 10 + x] == 0)
			return false;
	}
	return true;
}

std::vector<int> AGameLockState::getRowToClear() const
{
	std::vector<int> rowLooked;
	std::vector<int> rowsToClear;
	for(auto const& c: aGameData->currentTetromino.coords)
	{
		if(std::find(rowLooked.begin(), rowLooked.end(), c.y) != rowLooked.end())
			continue;
		rowLooked.push_back((int)c.y);
		if(checkRowFull(c.y))
			rowsToClear.push_back(c.y);
	}
	return rowsToClear;
}


void AGameLockState::init(sf::RenderWindow&)
{
	previousFrameStep = -1;
	rowsToClear = getRowToClear();
	noRowToClear = rowsToClear.empty();
	step = 0;
}

void AGameLockState::updateStep()
{
	int index1;
	int index2;

	for(auto const& row: rowsToClear)
	{
		index1 = row * 10 + 4 - step;
		index2 = row * 10 + 5 + step;
		aGameData->board[index1] = 0;
		aGameData->board[index2] = 0;
	}
}

void AGameLockState::update(sf::RenderWindow& window, State** self, float fElapsedTime)
{
	AGameState::update(window, self, fElapsedTime);
	if(noRowToClear || step == 5)
	{
		if(!noRowToClear)
			aGameData->deleteRows(rowsToClear);
		*self = aGameAREState;
		(*self)->init(window);
		return;
	}
	if(aGameData->frameCounter % 4 == 0 && previousFrameStep != (long)aGameData->frameCounter)
	{
		previousFrameStep = aGameData->frameCounter;
		updateStep();
		step++;
	}
}

void AGameLockState::draw(sf::RenderWindow& window) const
{
	AGameState::draw(window);
}
