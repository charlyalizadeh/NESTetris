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
		sf::Sprite gameSprite;
		std::array<sf::Sprite,10> statsSprites;
		std::array<sf::Sprite,10> statsDigitSprites;
		sf::Texture tetrominoSpriteSheet;
		std::array<std::array<sf::Sprite,3>,10> tetrominoSprites;

		// Other
		float lastFrame;
		unsigned int frameCounter;
		float lastFall;
		std::array<int,200> board;
		std::array<int,7> tetrominosCount;
		Tetromino currentTetromino;
		Tetromino nextTetromino;
		int tetrominoLockRow;
		float fps;
		float frameDuration;
		bool isDownPressed;

		int getLevel() const;
		int getGravity() const;
		bool isMovableDown() const;
		bool isMovableRight() const;
		bool isMovableLeft() const;
		int getTetrominoSpriteId(TetrominoType) const;

		void setLevel(int);
		void clearData();
		void moveDown();
		void moveRight();
		void moveLeft();
		void rotateRight();
		void rotateLeft();
		void updateBoard();
		void setLockRow();
		void deleteRows(std::vector<int>);

	private:
		void removeTetrominoFromBoard();

		int gravity;
		std::array<int,30> gravityTable;
		int level;
};

#endif
