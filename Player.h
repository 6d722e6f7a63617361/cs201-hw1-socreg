#include<string>

using std::string;

#ifndef PLAYER_H
#define PLAYER_H

/**
    This class represents a player with a name and a position
    @author Oktay AYAR
*/
class Player
{
public:
    /**
        Constructs a new player with given name and position
        @param name player name (Default: Unknown)
        @param position player position (Default: Unknown)
    */
    Player(string name="Unknown",string position="Unknown");

    /**
        Sets name of player
        @param name Name of player
    */
    void setName(string name);

    /**
        Sets position of player
        @param position position of player
    */
    void setPosition(string position);

    /**
        Gets name of player
        @return name of player
    */
    string getName();

    /**
        Gets position of player
        @return position of player
    */
    string getPosition();

    /**
        Displays player information
    */
    void display();
private:
    // Properties
    string name;
    string position;
};

#endif // PLAYER_H
