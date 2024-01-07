#include "../includes/AGameData.hpp"


AGameData::AGameData():
	currentTetromino(Tetromino(TetrominoType::NONE)),
	tetrominoLockRow(-1),
	fps(60.0988),
	frameDuration(1.0 / 60.0988),
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
    sprites["game"].setTexture(textures["game"]);
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
	tetrominoeSpriteSheet.loadFromFile("static/sprite/tetrominoes_sheet.png");
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			tetrominoeSprites[i][j].setTexture(tetrominoeSpriteSheet);
			tetrominoeSprites[i][j].setTextureRect({j * 7, i * 7, 7, 7});
		}
	}
	for(size_t i = 0; i < 10; i++)
		statsSprites[i].setPosition({26.f, 85.f});
	for(size_t i = 0; i < 200; i++)
		board[i] = 0;
	for(size_t i = 0; i < 6; i++)
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
	for(const auto &coord: currentTetromino.coords)
	{
		if(coord.y == 19)
			return false;
		if(!currentTetromino.isInCoords({coord.x, coord.y + 1}) && board[(coord.y + 1) * 10 + coord.x] != 0)
			return false;
	}
	return true;
}

bool AGameData::isMovableRight() const
{
	for(const auto &coord: currentTetromino.coords)
	{
		if(coord.x == 9)
			return false;
		if(!currentTetromino.isInCoords({coord.x + 1, coord.y}) && board[(coord.y) * 10 + coord.x + 1] != 0)
			return false;
	}
	return true;
}

bool AGameData::isMovableLeft() const
{
	for(const auto &coord: currentTetromino.coords)
	{
		if(coord.x == 0)
			return false;
		if(!currentTetromino.isInCoords({coord.x - 1, coord.y}) && board[(coord.y) * 10 + coord.x - 1] != 0)
			return false;
	}
	return true;
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
	for(auto &coord: currentTetromino.coords)
		board[coord.y * 10 + coord.x] = 0;
	currentTetromino.moveRight();
	updateBoard();
}

void AGameData::moveLeft()
{
	for(auto &coord: currentTetromino.coords)
		board[coord.y * 10 + coord.x] = 0;
	currentTetromino.moveLeft();
	updateBoard();
}

void AGameData::updateBoard()
{
	for(size_t i = 0; i < 4; i++)
	{
		int indexBoard = currentTetromino.coords[i].y * 10 + currentTetromino.coords[i].x;
		board[indexBoard] = 1;
	}
}

void AGameData::setLockRow()
{
	tetrominoLockRow = currentTetromino.down();
}
