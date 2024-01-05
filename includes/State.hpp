#ifndef STATE_H
#define STATE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <array>
#include <memory>
#include <map>

enum class GameType: int
{
    A,
    B
};

enum class MusicChoice: int
{
    ONE,
    TWO,
    THREE,
    OFF
};

// TODO: move the shared data between state into a GameData object
class State
{
    static GameType gameType;
    static MusicChoice musicChoice;
    static int aLevel;
    static int bLevel;

    protected:
        static std::array<sf::Music,10> musics;
        static std::map<std::string,sf::SoundBuffer> soundsBuff;
        static std::map<std::string,sf::Sound> sounds;

    public:
        static void initGame();

    public:
        State();
        virtual ~State();

        virtual void init(sf::RenderWindow &);
        virtual void update(sf::RenderWindow &, State**, float fElapsedTime);
        virtual void draw(sf::RenderWindow&) const;

        GameType getGameType() const;
        MusicChoice getMusicChoice() const;
        int getALevel() const;
        int getBLevel() const;

        void gameTypeUp();
        void gameTypeDown();
        void musicChoiceUp();
        void musicChoiceDown();
        void aLevelUp(int n);
        void aLevelDown(int n);
        void bLevelUp(int n);
        void bLevelDown(int n);
};

#endif
