#include "../includes/State.hpp"
#include "../includes/StateDef.hpp"
#include "../includes/TitleScreenState.hpp"
#include "../includes/Tetromino.hpp"
#include <SFML/System.hpp>


int main(void)
{
    float scaleFactor;
	float fElapsedTime;
    sf::Clock clock;
	sf::Time elapsed;

	scaleFactor = 3.f;
	clock = sf::Clock();
    sf::RenderWindow window(sf::VideoMode(256 * scaleFactor, 224 * scaleFactor), "SFML");
    sf::View myView(
            sf::Vector2f(128, 112),
            sf::Vector2f(256, 224)
    );
    window.setView(myView);

    State *state;
    State::initGame();
    state = titleScreenState;
    state->init(window);
    while(window.isOpen())
    {
		elapsed = clock.restart();
		fElapsedTime = elapsed.asSeconds();
        state->update(window, &state, fElapsedTime);
        state->draw(window);
        window.display();
    }
    delete titleScreenState;
    delete optionMenuState;
    delete aMenuState;
	delete aGameAREState;
	delete aGameFallingState;
	delete aGameData;
    return 0;
}
