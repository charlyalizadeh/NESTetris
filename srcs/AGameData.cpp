#include "../includes/AGameData.hpp"

static int getNbValAbove(int value, std::vector<int> values)
{
	int nbValAbove = 0;
	int i = values.size() - 1;
	while(i >= 0 && values[i--] >= value)
		nbValAbove++;
	return nbValAbove;
}

AGameData::AGameData():
	lastFrame(0),
	frameCounter(0),
	lastFall(0),
	currentTetromino(Tetromino(TetrominoType::NONE)),
	nextTetromino(Tetromino(TetrominoType::NONE)),
	tetrominoLockRow(-1),
	fps(60.0988),
	frameDuration(1.0 / 60.0988),
	isDownPressed(false),
	gravity(48),
	gravityTable({
			48, 43, 38, 33, 28, 23, 18, 13, 8, 6,
			5, 5, 5,
			4, 4, 4,
			3, 3, 3,
			2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
			1
	})
{
    textures["game"].loadFromFile("static/sprite/a_game.png");
    textures["stats0"].loadFromFile("static/sprite/a_game_stats0.png");
    textures["stats1"].loadFromFile("static/sprite/a_game_stats1.png");
    textures["stats2"].loadFromFile("static/sprite/a_game_stats2.png");
    textures["stats3"].loadFromFile("static/sprite/a_game_stats3.png");
    textures["stats4"].loadFromFile("static/sprite/a_game_stats4.png");
    textures["stats5"].loadFromFile("static/sprite/a_game_stats5.png");
    textures["stats6"].loadFromFile("static/sprite/a_game_stats6.png");
    textures["stats7"].loadFromFile("static/sprite/a_game_stats7.png");
    textures["stats8"].loadFromFile("static/sprite/a_game_stats8.png");
    textures["stats9"].loadFromFile("static/sprite/a_game_stats9.png");
	textures["statsDigit0"].loadFromFile("static/sprite/stat_digit_0.png");
	textures["statsDigit1"].loadFromFile("static/sprite/stat_digit_1.png");
	textures["statsDigit2"].loadFromFile("static/sprite/stat_digit_2.png");
	textures["statsDigit3"].loadFromFile("static/sprite/stat_digit_3.png");
	textures["statsDigit4"].loadFromFile("static/sprite/stat_digit_4.png");
	textures["statsDigit5"].loadFromFile("static/sprite/stat_digit_5.png");
	textures["statsDigit6"].loadFromFile("static/sprite/stat_digit_6.png");
	textures["statsDigit7"].loadFromFile("static/sprite/stat_digit_7.png");
	textures["statsDigit8"].loadFromFile("static/sprite/stat_digit_8.png");
	textures["statsDigit9"].loadFromFile("static/sprite/stat_digit_9.png");
    gameSprite.setTexture(textures["game"]);

    statsSprites[0].setTexture(textures["stats0"]);
    statsSprites[1].setTexture(textures["stats1"]);
    statsSprites[2].setTexture(textures["stats2"]);
    statsSprites[3].setTexture(textures["stats3"]);
    statsSprites[4].setTexture(textures["stats4"]);
    statsSprites[5].setTexture(textures["stats5"]);
    statsSprites[6].setTexture(textures["stats6"]);
    statsSprites[7].setTexture(textures["stats7"]);
    statsSprites[8].setTexture(textures["stats8"]);
    statsSprites[9].setTexture(textures["stats9"]);

    statsDigitSprites[0].setTexture(textures["statsDigit0"]);
    statsDigitSprites[1].setTexture(textures["statsDigit1"]);
    statsDigitSprites[2].setTexture(textures["statsDigit2"]);
    statsDigitSprites[3].setTexture(textures["statsDigit3"]);
    statsDigitSprites[4].setTexture(textures["statsDigit4"]);
    statsDigitSprites[5].setTexture(textures["statsDigit5"]);
    statsDigitSprites[6].setTexture(textures["statsDigit6"]);
    statsDigitSprites[7].setTexture(textures["statsDigit7"]);
    statsDigitSprites[8].setTexture(textures["statsDigit8"]);
    statsDigitSprites[9].setTexture(textures["statsDigit9"]);

	tetrominoSpriteSheet.loadFromFile("static/sprite/tetrominoes_sheet.png");
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			tetrominoSprites[i][j].setTexture(tetrominoSpriteSheet);
			tetrominoSprites[i][j].setTextureRect({j * 7, i * 7, 7, 7});
		}
	}
	for(size_t i = 0; i < 10; i++)
		statsSprites[i].setPosition({24.f, 85.f});
	for(size_t i = 0; i < 200; i++)
		board[i] = 0;
	for(size_t i = 0; i < 7; i++)
		tetrominosCount[i] = 0;
}

int AGameData::getLevel() const
{
	return level;
}

int AGameData::getGravity() const
{
	return gravity;
}

bool AGameData::isMovableDown() const
{
	int index;

	for(const auto &coord: currentTetromino.coords)
	{
		if(coord.y < 0)
			continue;
		if(coord.y == 19)
			return false;
		index = (coord.y + 1) * 10 + coord.x;
		if(!currentTetromino.isInCoords({coord.x, coord.y + 1}) && board[index] != 0)
			return false;
	}
	return true;
}

bool AGameData::isMovableRight() const
{
	int index;

	for(const auto &coord: currentTetromino.coords)
	{
		if(coord.x == 9)
			return false;
		if(coord.y < 0)
			continue;
		index = (coord.y) * 10 + coord.x + 1;
		if(!currentTetromino.isInCoords({coord.x + 1, coord.y}) && board[index] != 0)
			return false;
	}
	return true;
}

bool AGameData::isMovableLeft() const
{
	int index;

	for(const auto &coord: currentTetromino.coords)
	{
		if(coord.x == 0)
			return false;
		if(coord.y < 0)
			continue;
		index = (coord.y) * 10 + coord.x - 1;
		if(!currentTetromino.isInCoords({coord.x - 1, coord.y}) && board[index] != 0)
			return false;
	}
	return true;
}

int AGameData::getTetrominoSpriteId(TetrominoType type) const
{
	switch(type)
	{
		case TetrominoType::T:
		case TetrominoType::O:
		case TetrominoType::I:
			return 1;
		case TetrominoType::J:
		case TetrominoType::S:
			return 2;
		case TetrominoType::Z:
		case TetrominoType::L:
			return 3;
		default:
			return 0;
	}
	return 0;
}

void AGameData::removeTetrominoFromBoard()
{
	for(auto &coord: currentTetromino.coords)
		board[coord.y * 10 + coord.x] = 0;
}

void AGameData::updateBoard()
{
	for(size_t i = 0; i < 4; i++)
	{
		int indexBoard = currentTetromino.coords[i].y * 10 + currentTetromino.coords[i].x;
		if(!(indexBoard < 0 || indexBoard >= 200))
			board[indexBoard] = getTetrominoSpriteId(currentTetromino.type);
	}
}

void AGameData::setLevel(int val)
{
	if(val < 0)
		return ;
	level = val < 29 ? val: 29;
	gravity = gravityTable[level];
}

void AGameData::clearData()
{
	currentTetromino = Tetromino(TetrominoType::NONE);
	for(size_t i = 0; i < 200; i++)
		board[i] = 0;
	for(size_t i = 0; i < 6; i++)
		tetrominosCount[i] = 0;
}

void AGameData::moveDown()
{
	for(auto &coord: currentTetromino.coords)
		board[coord.y * 10 + coord.x] = 0;
	currentTetromino.moveDown();
	updateBoard();
}

void AGameData::moveRight()
{
	removeTetrominoFromBoard();
	currentTetromino.moveRight();
	updateBoard();
}

void AGameData::moveLeft()
{
	removeTetrominoFromBoard();
	currentTetromino.moveLeft();
	updateBoard();
}

void AGameData::rotateRight()
{
	removeTetrominoFromBoard();
	currentTetromino.rotateRight();
	updateBoard();
}

void AGameData::rotateLeft()
{
	removeTetrominoFromBoard();
	currentTetromino.rotateLeft();
	updateBoard();
}

void AGameData::setLockRow()
{
	tetrominoLockRow = currentTetromino.down();
}

void AGameData::deleteRows(std::vector<int> rows)
{
	std::array<int,200> newBoard;
	int nbRowUnder;

	for(int i = 0; i < 200; i++)
		newBoard[i] = 0;
	for(int y = 19; y >= 0; y--)
	{
		if(std::find(rows.begin(), rows.end(), y) != rows.end())
			continue;
		nbRowUnder = getNbValAbove(y, rows);
		if(y + nbRowUnder > 19)
			continue;
		for(size_t x = 0; x < 10; x++)
			newBoard[(y + nbRowUnder) * 10 + x] = board[y * 10 + x];
	}
	board = newBoard;
}
