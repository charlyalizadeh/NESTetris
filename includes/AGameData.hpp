#ifndef AGAMEDATA_H
#define AGAMEDATA_H

#include "Tetromino.hpp"
#include <SFML/Graphics.hpp>
#include <array>
#include <map>
#include <string>

class AGameData
{
	public:
		AGameData();

		// Textures and Sprites
		std::map<std::string,sf::Texture> textures;
		std::map<std::string,sf::Sprite> sprites;
		std::array<sf::Sprite,10> statsSprites;
		sf::Texture tetrominoeSpriteSheet;
		std::array<std::array<sf::Sprite,3>,10> tetrominoeSprites;

		// Other
		std::array<int, 200> board;
		std::array<int,6> tetrominosCount;
		Tetromino currentTetromino;
		int tetrominoLockRow;
		float fps;
		float frameDuration;

		int getLevel() const;
		int getGravity() const;
		bool isMovableDown() const;
		bool isMovableRight() const;
		bool isMovableLeft() const;

		void setLevel(int);
		void clearData();
		void moveDown();
		void moveRight();
		void moveLeft();
		void rotateRight();
		void rotateLeft();
		void updateBoard();
		void setLockRow();

	private:
		void removeTetrominoFromBoard();

		int gravity;
		std::array<int,30> gravityTable;
		int level;
};

#endif
