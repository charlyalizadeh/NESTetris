#include "../includes/AGameState.hpp"


AGameState::AGameState() {}

AGameState::~AGameState() {}

void AGameState::init(sf::RenderWindow&) {}

void AGameState::updateEvent(sf::RenderWindow &, State**, float, sf::Event) {}

void AGameState::update(sf::RenderWindow& window, State** self, float fElapsedTime)
{
	aGameData->lastFrame += fElapsedTime;
	if(aGameData->lastFrame >= aGameData->frameDuration)
	{
		aGameData->frameCounter++;
		aGameData->lastFrame = 0;
	}
    sf::Event event;
    while(window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
            window.close();
        if(event.type == sf::Event::KeyPressed)
        {
            switch(event.key.code)
            {
				case sf::Keyboard::E:
					aGameData->clearData();
					*self = aMenuState;
					break;
				default:
					break;
            }
        }
		updateEvent(window, self, fElapsedTime, event);
    }
}

void AGameState::drawPlayfield(sf::RenderWindow& window) const
{
	int cell_val;
	sf::Sprite sprite;

	for(size_t i = 0; i < 20; i++)
	{
		for(size_t j = 0; j < 10; j++)
		{
			cell_val = aGameData->board[i * 10 + j];
			if(cell_val != 0)
			{
				sprite = aGameData->tetrominoSprites[aGameData->getLevel()][cell_val - 1];
				sprite.setPosition({
						(float)(96 + j * 8),
						(float)(40 + i * 8)
				});
				window.draw(sprite);
			}
		}
	}
}

void AGameState::drawNextTetromino(sf::RenderWindow& window) const
{
	sf::Vector2f originDraw;
	switch(aGameData->nextTetromino.type)
	{
		case TetrominoType::O:
			originDraw = {200, 112};
			break;
		case TetrominoType::I:
			originDraw = {192, 116};
			break;
		default:
			originDraw = {196, 112};
	}
	aGameData->nextTetromino.move({0, 0});
	sf::Sprite sprite = aGameData->tetrominoSprites[aGameData->getLevel()][aGameData->getTetrominoSpriteId(aGameData->nextTetromino.type) - 1];
	for(auto const& c: aGameData->nextTetromino.coords)
	{
		sprite.setPosition({
				originDraw.x + c.x * 8,
				originDraw.y + c.y * 8
		});
		window.draw(sprite);
	}
}

void AGameState::drawStatNumber(sf::RenderWindow& window, int number, sf::Vector2f origin) const
{
	int digit;

	digit = number / 100;
	aGameData->statsDigitSprites[digit].setPosition(origin);
	window.draw(aGameData->statsDigitSprites[digit]);

	digit = (number / 10) % 10;
	origin.x += 8;
	aGameData->statsDigitSprites[digit].setPosition(origin);
	window.draw(aGameData->statsDigitSprites[digit]);

	digit = number % 10;
	origin.x += 8;
	aGameData->statsDigitSprites[digit].setPosition(origin);
	window.draw(aGameData->statsDigitSprites[digit]);
}

void AGameState::drawStats(sf::RenderWindow& window) const
{
	std::array<int,7> order = {2, 3, 5, 1, 6, 4, 0};
	std::array<int,7> yCoords = {88, 104, 120, 136, 152, 168, 184};
	for(int i = 0; i < 7; i++)
		drawStatNumber(window, aGameData->tetrominosCount[order[i]], sf::Vector2f(48, yCoords[i]));
}

void AGameState::draw(sf::RenderWindow& window) const
{
    window.clear(sf::Color::Black);
	window.draw(aGameData->gameSprite);
	window.draw(aGameData->statsSprites[aGameData->getLevel() % 10]);
	drawPlayfield(window);
	drawNextTetromino(window);
	drawStats(window);
}
