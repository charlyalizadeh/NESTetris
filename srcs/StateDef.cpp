#include "../includes/Tetromino.hpp"
#include "../includes/State.hpp"
#include "../includes/StateDef.hpp"
#include "../includes/TitleScreenState.hpp"
#include "../includes/OptionMenuState.hpp"
#include "../includes/AMenuState.hpp"
#include "../includes/AGameData.hpp"
#include "../includes/AGameState.hpp"
#include "../includes/AGameAREState.hpp"
#include "../includes/AGameFallingState.hpp"
#include "../includes/AGameDASState.hpp"
#include "../includes/AGameSoftDropState.hpp"
#include "../includes/AGameLockState.hpp"

const std::array<std::array<sf::Vector2f,4>,7> Tetromino::tetrominoPattern = {{
		{sf::Vector2f(0, 0), sf::Vector2f(1, 0), sf::Vector2f(2, 0), sf::Vector2f(3, 0)}, // I
		{sf::Vector2f(0, 0), sf::Vector2f(1, 0), sf::Vector2f(0, 1), sf::Vector2f(1, 1)}, // O
		{sf::Vector2f(0, 0), sf::Vector2f(1, 0), sf::Vector2f(2, 0), sf::Vector2f(1, 1)}, // T
		{sf::Vector2f(0, 0), sf::Vector2f(1, 0), sf::Vector2f(2, 0), sf::Vector2f(2, 1)}, // J
		{sf::Vector2f(0, 0), sf::Vector2f(1, 0), sf::Vector2f(2, 0), sf::Vector2f(0, 1)}, // L
		{sf::Vector2f(0, 0), sf::Vector2f(1, 0), sf::Vector2f(1, 1), sf::Vector2f(2, 1)}, // Z
		{sf::Vector2f(0, 1), sf::Vector2f(1, 1), sf::Vector2f(1, 0), sf::Vector2f(2, 0)}  // S
}};

State *titleScreenState = new TitleScreenState();
State *optionMenuState = new OptionMenuState();
State *aMenuState = new AMenuState();
AGameData *aGameData = new AGameData();
State *aGameState = new AGameState();
State *aGameAREState = new AGameAREState();
State *aGameFallingState = new AGameFallingState();
State *aGameDASRightState = new AGameDASState(DASDirection::Right);
State *aGameDASLeftState = new AGameDASState(DASDirection::Left);
State *aGameSoftDropState = new AGameSoftDropState();
State *aGameLockState = new AGameLockState();
