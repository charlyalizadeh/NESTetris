#ifndef TETROMINO_HPP
#define TETROMINO_HPP

#include <SFML/Graphics.hpp>
#include <array>
#include <cstdlib>

enum class TetrominoType
{
	I,
    O,
    T,
    J,
    L,
    Z,
    S,
	NONE
};

struct Tetromino
{
	static const std::array<std::array<sf::Vector2f,4>,7> tetrominoPattern;

	sf::Vector2f origin;
	std::array<sf::Vector2f,4> coords;
	TetrominoType type;
	int rotation;

	Tetromino(TetrominoType);
	void move(sf::Vector2f);
	void moveDown();
	void moveRight();
	void moveLeft();
	int up() const;
	int down() const;
	int left() const;
	int right() const;
	void rotateI();
	void rotateZS();
	void rotateLeftTLJ();
	void rotateRightTLJ();
	void rotateLeft();
	void rotateRight();
	bool isInCoords(sf::Vector2f) const;
};

#endif
