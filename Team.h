#include<string>
#include "Player.h"

using std::string;

#ifndef TEAM_H
#define TEAM_H

/**
    This class represent a team with a name, a color and its players
    @author Oktay AYAR
*/
class Team
{
public:

    /**
        Constructs a new team object with given name, color and empty player list
        @param name team name (Default: Unknown)
        @param color team color (Default: Unknown)
    */
    Team(string name="Unknown",string color="Unknown");
    /**
        Destructs team object
    */
    ~Team();

    /**
        Gets name of team
        @return name of team
    */
    string getName();

    /**
        Sets name of team
        @param name team name
    */
    void setName(string name);

    /**
        Gets color of team
        @return color of team
    */
    string getColor();

    /**
        Sets name of team
        @param color team color
    */
    void setColor(string color);

    /**
        Adds a new player to team if the player with given name does not exist in team
        @param name player name
        @param position player position
        @return false if the player with given name does exist in team, otherwise true
    */
    bool addPlayer(string name,string position);

    /**
        Removes the player with given name from the team if the player with given name exists in team
        @param name player name
        @return false if the player with given name does not exist in team, otherwise true
    */
    bool removePlayer(string);

    /**
        Searches for a player with given name
        @param name player's name
        @return Player object for the player if player exist in team, otherwise NULL
    */
    Player* searchPlayer(string name);

    /**
        Displays team's name and color
    */
    void display();

    /**
        Displays detailed team information
    */
    void displayDetailed();

    /**
        Copies team information and its players to given Team object
        @param dest Team object that this team's information will be copied to
    */
    void copy(Team * dest);
private:
    // Properties
    Player *players;
    string name;
    string color;
    int playerCount;
    int playerCapacity;

    /**
        Copies team's players to given Team object
        @param dest Team object that this team's players will be copied to
    */
    void copyPlayers(Team * dest);

    /**
        Removes given player pointer from the player pointer list
        @param player Pointer of player object that will be removed from the list
    */
    void removePlayerPtr(Player * player);

    /**
        Increases player list capacity twice
    */
    void increasePlayerCapacity();

    /**
        Decreases player list capacity twice
    */
    void decreasePlayerCapacity();
};

#endif // TEAM_H

