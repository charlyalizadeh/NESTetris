#ifndef OPTIONMENUSTATE_H
#define OPTIONMENUSTATE_H

#include "State.hpp"
#include "StateDef.hpp"
#include <SFML/Graphics.hpp>
#include <array>

class OptionMenuState: public State
{
        sf::Texture optionMenuTexture;
        std::array<sf::Texture,2> gameTypeTexture;
        std::array<sf::Texture,4> musicChoiceTexture;

		sf::Sprite optionMenuSprite;
		std::array<sf::Sprite,2> gameTypeSprite;
		std::array<sf::Sprite,4> musicChoiceSprite;

    public:
        OptionMenuState();
        ~OptionMenuState();
        void init(sf::RenderWindow&);
        void update(sf::RenderWindow&, State**, float);
        void draw(sf::RenderWindow&) const;
};

#endif
