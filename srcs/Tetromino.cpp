#include "../includes/Tetromino.hpp"


Tetromino::Tetromino(TetrominoType type): type(type)  {}

void Tetromino::move(sf::Vector2f new_origin)
{
	origin = new_origin;
	int tetrominoTypeId = static_cast<int>(type);
	for(size_t i = 0; i < 4; i++)
		coords[i] = origin + tetrominoPattern[tetrominoTypeId][i];
}

void Tetromino::moveDown()
{
	origin.y++;
	move(origin);
}

void Tetromino::moveRight()
{
	origin.x++;
	move(origin);
}

void Tetromino::moveLeft()
{
	origin.x--;
	move(origin);
}

int Tetromino::up() const
{
	int _up = coords[0].y;
	for(size_t i = 1; i < 4; i++)
		if(coords[i].y < _up)
			_up = coords[i].y;
	return _up;
}

int Tetromino::down() const
{
	int _down = coords[0].y;
	for(size_t i = 1; i < 4; i++)
		if(coords[i].y > _down)
			_down = coords[i].y;
	return _down;
}

int Tetromino::left() const
{
	int _left = coords[0].x;
	for(size_t i = 1; i < 4; i++)
		if(coords[i].x < _left)
			_left = coords[i].x;
	return _left;
}

int Tetromino::right() const
{
	int _right = coords[0].x;
	for(size_t i = 1; i < 4; i++)
		if(coords[i].x > _right)
			_right = coords[i].x;
	return _right;
}

bool Tetromino::isInCoords(sf::Vector2f coord) const
{
	for(const auto& c: coords)
	{
		if(c.x == coord.x && c.y == coord.y)
			return true;
	}
	return false;
}
