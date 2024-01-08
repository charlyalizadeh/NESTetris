#include "../includes/Tetromino.hpp"


static void rotateCoordsLeft(sf::Vector2f origin, std::array<sf::Vector2f,4>& coords, int dim)
{
	for(auto& coord: coords)
	{
		sf::Vector2f coord_norm = coord - origin;
		coord.x = origin.x + coord_norm.y;
		coord.y = origin.y + (dim - 1 - coord_norm.x);
	}
}

static void rotateCoordsRight(sf::Vector2f origin, std::array<sf::Vector2f,4>& coords, int dim)
{
	for(auto& coord: coords)
	{
		sf::Vector2f coord_norm = coord - origin;
		coord.x = origin.x + (dim - 1 - coord_norm.y);
		coord.y = origin.y + coord_norm.x;
	}
}


Tetromino::Tetromino(TetrominoType type): type(type), rotation(0)  {}

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
	for(auto& c: coords)
		c.y++;
}

void Tetromino::moveRight()
{
	origin.x++;
	for(auto& c: coords)
		c.x++;
}

void Tetromino::moveLeft()
{
	origin.x--;
	for(auto& c: coords)
		c.x--;
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

void Tetromino::rotateI()
{
	sf::Vector2f rotationOrigin = origin;
	rotationOrigin.y -= 2;
	if(rotation == 0)
	{
		rotateCoordsLeft(rotationOrigin, coords, 4);
		rotation = 1;
	}
	else
	{
		rotateCoordsRight(rotationOrigin, coords, 4);
		rotation = 0;
	}
}

void Tetromino::rotateZS()
{
	sf::Vector2f rotationOrigin = origin;
	rotationOrigin.y--;
	if(rotation == 0)
	{
		rotateCoordsLeft(rotationOrigin, coords, 3);
		rotation = 1;
	}
	else
	{
		rotateCoordsRight(rotationOrigin, coords, 3);
		rotation = 0;
	}
}

void Tetromino::rotateLeftTLJ()
{
	sf::Vector2f rotationOrigin = origin;
	rotationOrigin.y--;
	rotateCoordsLeft(rotationOrigin, coords, 3);
}

void Tetromino::rotateRightTLJ()
{
	sf::Vector2f rotationOrigin = origin;
	rotationOrigin.y--;
	rotateCoordsRight(rotationOrigin, coords, 3);
}

void Tetromino::rotateLeft()
{
	switch(type)
	{
		case TetrominoType::O:
			break;
		case TetrominoType::I:
			rotateI();
			break;
		case TetrominoType::Z:
		case TetrominoType::S:
			rotateZS();
			break;
		case TetrominoType::T:
		case TetrominoType::L:
		case TetrominoType::J:
			rotateLeftTLJ();
			break;
		default:
			break;
	}
}


void Tetromino::rotateRight()
{
	switch(type)
	{
		case TetrominoType::O:
			break;
		case TetrominoType::I:
			rotateI();
			break;
		case TetrominoType::Z:
		case TetrominoType::S:
			rotateZS();
			break;
		case TetrominoType::T:
		case TetrominoType::L:
		case TetrominoType::J:
			rotateRightTLJ();
			break;
		default:
			break;
	}
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
