#include <string>
#include "Team.h"

using std::string;

#ifndef SOCREG_H
#define SOCREG_H

/**
    This class manages the teams and player that will be participated to tournament
    @author Çiðdem GÜNDÜZ, Oktay AYAR
*/
class SocReg {
public:
    /**
        Constructs new SocReg object
    */
    SocReg();

    /**
        Destructs the SocReg object
    */
    ~SocReg();

    /**
        Adds team to list with given name and color
        @param teamName name of team
        @param color color of team
    */
    void addTeam( string teamName, string color );

    /**
        Removes team from list with given name if the team exists
        @param teamName name of team
    */
    void removeTeam( string teamName );

    /**
        Adds a player with given name and position to the team with given name. If the team exists and the player does not
        exists in that team

        @param teamName name of team
        @param playerName name of player
        @param playerPosition position of player
    */
    void addPlayer( string teamName, string playerName, string playerPosition );

    /**
        Removes the player with given name from the team with given name. If the player exists in that team

        @param teamName name of team
        @param playerName name of player
    */
    void removePlayer( string teamName, string playerName );

    /**
        Displays teams in the list
    */
    void displayAllTeams();

    /**
        Displays player(s) with given name existing in any team(s)
    */
    void displayPlayer( string playerName );

    /**
        Displays player of team with given name if the team exists
    */
    void displayTeam( string teamName );
private:
    // Properties
    Team *teams;
    int teamCount;
    int capacity;

    /**
        Searches for the team with given name in the list

        @param teamName name of team
        @return Pointer for team object that matches to given name, if any team does not match, then returns NULL
    */
    Team* searchTeam(string teamName);

    /**
        Increases team list capacity twice
    */
    void increaseTeamCapacity();

    /**
        Decreases team list capacity twice
    */
    void decreaseTeamCapacity();

    /**
        Removes from given team object from the list
    */
    void removeTeamPtr(Team *t);
};

#endif // SOCREG_H
