#include "../includes/AMenuState.hpp"


AMenuState::AMenuState()
{
    if(
            !aMenuStateTexture.loadFromFile("static/sprite/a_menu.png") ||
            !levelSelectTexture.loadFromFile("static/sprite/level_select_square.png")
      )
    {
        exit(1);
    }
    aMenuStateSprite.setTexture(aMenuStateTexture);
    levelSelectSprite.setTexture(levelSelectTexture);
}

AMenuState::~AMenuState() {}

void AMenuState::levelLeft()
{
    aLevelDown(1);
}

void AMenuState::levelRight()
{
    aLevelUp(1);
}

void AMenuState::levelUp()
{
    aLevelDown(5);
}

void AMenuState::levelDown()
{
    aLevelUp(5);
}

void AMenuState::init(sf::RenderWindow &) {}

void AMenuState::update(sf::RenderWindow &window, State **self, float)
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
                case sf::Keyboard::Up:
                    sounds["moveSelect"].play();
                    levelUp();
                    break;
                case sf::Keyboard::Down:
                    sounds["moveSelect"].play();
                    levelDown();
                    break;
                case sf::Keyboard::Left:
                    sounds["moveSelect"].play();
                    levelLeft();
                    break;
                case sf::Keyboard::Right:
                    sounds["moveSelect"].play();
                    levelRight();
                    break;
                case sf::Keyboard::E:
                    *self = optionMenuState;
                    (*self)->init(window);
					break;
				case sf::Keyboard::Enter:
					aGameData->setLevel(getALevel());
					*self = aGameAREState;
					(*self)->init(window);
					break;
                default:
                    break;
            }
        }
    }
    levelSelectSprite.setPosition({
            52 + 16 * (float)(getALevel() - (getALevel() / 5 * 5)),
            76 + 16 * (float)(getALevel() / 5)
    });
}

void AMenuState::draw(sf::RenderWindow &window) const
{
    window.clear(sf::Color::Black);
    window.draw(levelSelectSprite);
    window.draw(aMenuStateSprite);
}

