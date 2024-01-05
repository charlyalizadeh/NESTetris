#ifndef TITLESCREENSTATE_H
#define TITLESCREENSTATE_H

#include "State.hpp"
#include "StateDef.hpp"
#include <SFML/Graphics.hpp>

class TitleScreenState: public State
{
    sf::Texture titleScreenTexture;
    sf::Sprite titleScreenSprite;

    public:
        TitleScreenState();
        ~TitleScreenState();
        virtual void init(sf::RenderWindow&);
        virtual void update(sf::RenderWindow&, State**, float);
        virtual void draw(sf::RenderWindow&) const;
};

#endif
