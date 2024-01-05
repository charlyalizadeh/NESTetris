#include "../includes/AGameState.hpp"


AGameState::AGameState() {}

AGameState::~AGameState() {}

void AGameState::init(sf::RenderWindow&) {}

void AGameState::updateEvent(sf::RenderWindow &, State**, float, sf::Event) {}

void AGameState::update(sf::RenderWindow& window, State** self, float fElapsedTime)
{
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

void AGameState::draw_playfield(sf::RenderWindow& window) const
{
	int cell_val;
	for(size_t i = 0; i < 20; i++)
	{
		for(size_t j = 0; j < 10; j++)
		{
			cell_val = aGameData->board[i * 10 + j];
			if(cell_val != 0)
			{
				aGameData->tetrominoeSprites[aGameData->getLevel()][cell_val - 1].setPosition({
						(float)(96 + j * 8),
						(float)(40 + i * 8)
				});
				window.draw(aGameData->tetrominoeSprites[aGameData->getLevel()][cell_val - 1]);
			}
		}
	}
}

void AGameState::draw(sf::RenderWindow& window) const
{
    window.clear(sf::Color::Black);
	window.draw(aGameData->sprites["game"]);
	window.draw(aGameData->statsSprites[aGameData->getLevel() % 10]);
	draw_playfield(window);
}
