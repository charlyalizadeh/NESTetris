#include "../includes/State.hpp"

GameType State::gameType = GameType::A;
MusicChoice State::musicChoice = MusicChoice::ONE;
int State::aLevel = 0;
int State::bLevel = 0;
std::array<sf::Music,10> State::musics = {};
std::map<std::string,sf::Sound> State::sounds = {};
std::map<std::string,sf::SoundBuffer> State::soundsBuff = {};

State::State() {}

State::~State() {}

void State::initGame()
{
    // Musics
    musics[0].openFromFile("static/music/01_-_Tetris_-_NES_-_Music_1.ogg");
    musics[1].openFromFile("static/music/03_-_Tetris_-_NES_-_Music_2.ogg");
    musics[2].openFromFile("static/music/05_-_Tetris_-_NES_-_Music_3.ogg");
    musics[3].openFromFile("static/music/02_-_Tetris_-_NES_-_Music_1_-_Fast.ogg");
    musics[4].openFromFile("static/music/04_-_Tetris_-_NES_-_Music_2_-_Fast.ogg");
    musics[5].openFromFile("static/music/06_-_Tetris_-_NES_-_Music_3_-_Fast.ogg");
    musics[6].openFromFile("static/music/07_-_Tetris_-_NES_-_Success!.ogg");
    musics[7].openFromFile("static/music/08_-_Tetris_-_NES_-_Victory.ogg");
    musics[8].openFromFile("static/music/09_-_Tetris_-_NES_-_High_Score.ogg");
    musics[9].openFromFile("static/music/10_-_Tetris_-_NES_-_Unknown.ogg");

    // Sounds
    soundsBuff["moveSelect"].loadFromFile("static/sound/move_select.wav");
    sounds["moveSelect"].setBuffer(soundsBuff["moveSelect"]);
    soundsBuff["validateSelect"].loadFromFile("static/sound/validate_select.wav");
    sounds["validateSelect"].setBuffer(soundsBuff["validateSelect"]);

}

void State::init(sf::RenderWindow&) { }

void State::update(sf::RenderWindow&, State**, float) {}

void State::draw(sf::RenderWindow&) const {}

GameType State::getGameType() const { return State::gameType; }

MusicChoice State::getMusicChoice() const { return musicChoice; }

int State::getALevel() const { return aLevel; }

int State::getBLevel() const { return bLevel; }

void State::gameTypeUp()
{
    if(gameType == GameType::A)
        gameType = GameType::B;
}

void State::gameTypeDown()
{
    if(gameType == GameType::B)
        gameType = GameType::A;
}

void State::musicChoiceUp()
{
    if(musicChoice != MusicChoice::OFF)
        musicChoice = static_cast<MusicChoice>(static_cast<int>(musicChoice) + 1);
}

void State::musicChoiceDown()
{
    if(musicChoice != MusicChoice::ONE)
        musicChoice = static_cast<MusicChoice>(static_cast<int>(musicChoice) - 1);
}

void State::aLevelUp(int n)
{
    if(aLevel + n <= 9)
        aLevel += n;
}

void State::aLevelDown(int n)
{
    if(aLevel - n >= 0)
        aLevel -= n;
}

void State::bLevelUp(int n)
{
    if(bLevel + n <= 9)
        bLevel += n;
}

void State::bLevelDown(int n)
{
    if(bLevel - n >= 0)
        bLevel -= n;
}
