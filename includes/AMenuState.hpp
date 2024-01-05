#ifndef AMENUSTATE_H
#define AMENUSTATE_H

#include "State.hpp"
#include "StateDef.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <array>

class AMenuState: public State
{
    sf::Texture aMenuStateTexture;
	sf::Texture levelSelectTexture;
	sf::Sprite aMenuStateSprite;
    sf::Sprite levelSelectSprite;

    public:
        AMenuState();
        ~AMenuState();
        void levelLeft();
        void levelRight();
        void levelUp();
        void levelDown();

        void init(sf::RenderWindow&);
        void update(sf::RenderWindow&, State**, float);
        void draw(sf::RenderWindow&) const;
};

#endif
