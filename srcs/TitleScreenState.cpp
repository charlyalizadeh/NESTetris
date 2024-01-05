#include "../includes/TitleScreenState.hpp"


TitleScreenState::TitleScreenState()
{
    if(!titleScreenTexture.loadFromFile("static/sprite/title_screen.png"))
        exit(1);
    titleScreenSprite.setTexture(titleScreenTexture);
}

TitleScreenState::~TitleScreenState() {}

void TitleScreenState::init(sf::RenderWindow &) {}

void TitleScreenState::update(sf::RenderWindow& window, State **self, float)
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
                case sf::Keyboard::Enter:
                    sounds["validateSelect"].play();
                    *self = optionMenuState;
                    (*self)->init(window);
                    break;
                case sf::Keyboard::A:
                    break;
                default:
                    break;
            }

        }
    }
}

void TitleScreenState::draw(sf::RenderWindow &window) const
{
    window.clear(sf::Color::Black);
    window.draw(titleScreenSprite);
}
