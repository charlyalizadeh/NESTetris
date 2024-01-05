#include "../includes/OptionMenuState.hpp"


OptionMenuState::OptionMenuState()
{
    if(
            !optionMenuTexture.loadFromFile("static/sprite/option_menu.png") ||
            !gameTypeTexture[0].loadFromFile("static/sprite/option_menu_a_select.png") ||
            !gameTypeTexture[1].loadFromFile("static/sprite/option_menu_b_select.png") ||
            !musicChoiceTexture[0].loadFromFile("static/sprite/option_menu_music1_select.png") ||
            !musicChoiceTexture[1].loadFromFile("static/sprite/option_menu_music2_select.png") ||
            !musicChoiceTexture[2].loadFromFile("static/sprite/option_menu_music3_select.png") ||
            !musicChoiceTexture[3].loadFromFile("static/sprite/option_menu_musicoff_select.png")
      )
    {
        exit(1);
    }
    optionMenuSprite.setTexture(optionMenuTexture);
    gameTypeSprite[0].setTexture(gameTypeTexture[0]);
    gameTypeSprite[1].setTexture(gameTypeTexture[1]);
    musicChoiceSprite[0].setTexture(musicChoiceTexture[0]);
    musicChoiceSprite[1].setTexture(musicChoiceTexture[1]);
    musicChoiceSprite[2].setTexture(musicChoiceTexture[2]);
    musicChoiceSprite[3].setTexture(musicChoiceTexture[3]);
}

OptionMenuState::~OptionMenuState() {}

void OptionMenuState::init(sf::RenderWindow&)
{
    if(getMusicChoice() != MusicChoice::OFF)
        musics[static_cast<int>(getMusicChoice())].play();
}

void OptionMenuState::update(sf::RenderWindow& window, State **self, float)
{
    sf::Event event;
    while(window.pollEvent(event))
    {
        MusicChoice prevMusicChoice = getMusicChoice();
        if(event.type == sf::Event::Closed)
            window.close();
        if(event.type == sf::Event::KeyPressed)
        {
            switch(event.key.code)
            {
                case sf::Keyboard::Down:
                    sounds["moveSelect"].play();
                    musicChoiceUp();
                    if(prevMusicChoice != getMusicChoice())
                    {
                        musics[static_cast<int>(prevMusicChoice)].stop();
                        if(getMusicChoice() != MusicChoice::OFF)
                            musics[static_cast<int>(getMusicChoice())].play();
                    }
                    break;
                case sf::Keyboard::Up:
                    sounds["moveSelect"].play();
                    musicChoiceDown();
                    if(prevMusicChoice != getMusicChoice())
                    {
                        musics[static_cast<int>(prevMusicChoice)].stop();
                        musics[static_cast<int>(getMusicChoice())].play();
                    }
                    break;
                case sf::Keyboard::Left:
                    sounds["moveSelect"].play();
                    gameTypeDown();
                    break;
                case sf::Keyboard::Right:
                    sounds["moveSelect"].play();
                    gameTypeUp();
                    break;
                case sf::Keyboard::E:
                    sounds["validateSelect"].play();
                    *self = titleScreenState;
                    if(getMusicChoice() != MusicChoice::OFF)
                        musics[static_cast<int>(getMusicChoice())].stop();
                    (*self)->init(window);
                    break;
                case sf::Keyboard::Enter:
                    sounds["validateSelect"].play();
                    if(getGameType() == GameType::A)
                        *self = aMenuState;
                    if(getMusicChoice() != MusicChoice::OFF)
                        musics[static_cast<int>(getMusicChoice())].stop();
                    (*self)->init(window);
                    break;
                default:
                    break;
            }
        }
    }
}

void OptionMenuState::draw(sf::RenderWindow& window) const
{
    window.draw(optionMenuSprite);
    window.draw(gameTypeSprite[static_cast<int>(getGameType())]);
    window.draw(musicChoiceSprite[static_cast<int>(getMusicChoice())]);
}
