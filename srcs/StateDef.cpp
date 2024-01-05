#include "AGameAREState.hpp"
#include "AGameData.hpp"
#include "AGameFallingState.hpp"
#include "AGameState.hpp"
#include "AMenuState.hpp"
#include "OptionMenuState.hpp"
#include "StateDef.hpp"
#include "State.hpp"
#include "Tetromino.hpp"
#include "TitleScreenState.hpp"

const std::array<std::array<sf::Vector2f,4>,6> Tetromino::tetrominoPattern = {{
	{sf::Vector2f(0, 0), sf::Vector2f(1, 0), sf::Vector2f(0, 1), sf::Vector2f(1, 1)}, // O
		{sf::Vector2f(0, 0), sf::Vector2f(1, 0), sf::Vector2f(2, 0), sf::Vector2f(1, 1)}, // T
		{sf::Vector2f(0, 0), sf::Vector2f(1, 0), sf::Vector2f(2, 0), sf::Vector2f(2, 1)}, // J
		{sf::Vector2f(0, 0), sf::Vector2f(1, 0), sf::Vector2f(2, 0), sf::Vector2f(3, 0)}, // L
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
