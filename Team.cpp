#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
#include "Player.h"
#include "Team.h"

using namespace std;

Team::Team(string name,string color)
{
    setName(name);
    setColor(color);

    // Set default capacity and player count
    playerCapacity=1;
    playerCount=0;

    // Create player pointer list
    players=new Player[playerCapacity];
}

Team::~Team()
{
    // Delete player list from memory
    delete[] players;
}

string Team::getName()
{
    return name;
}

void Team::setName(string name)
{
    this->name=name;
}

string Team::getColor()
{
    return color;
}

void Team::setColor(string color)
{
    this->color=color;
}

bool Team::addPlayer(string name,string position)
{
    // Check whether any player with given name exists in the team
    if(searchPlayer(name)!=NULL)
    {
        // If player with given name exists return false
        return false;
    }
    else
    {
        // Set next empty player object information
        players[playerCount].setName(name);
        players[playerCount].setPosition(position);

        // Increase player count
        playerCount++;

        // If capacity is filled increase capacity
        if(playerCount==playerCapacity)
            increasePlayerCapacity();

        return true;
    }
}

bool Team::removePlayer(string playerName)
{
    Player *p;

    // Search for the player with given name
    p=searchPlayer(playerName);

    if(p==NULL)
        // If player with given name does not exist in team return false
        return false;
    else
    {
        // Remove player from the list
        removePlayerPtr(p);

        // Decrease player count
        playerCount--;

        // If player count is less than half of capacity, then decrease player list capacity
        // for memory optimization
        if(playerCount<playerCapacity/2)
            decreasePlayerCapacity();

        return true;
    }
}

Player* Team::searchPlayer(string playerNameQ)
{
    // Variables
    Player *pPtr=NULL; // Set initial value NULL
    string lowPlayerNameQ,lowPlayerName;
    string playerName;

    lowPlayerNameQ=playerNameQ;

    // Make lowercase given search term
    ::transform(lowPlayerNameQ.begin(),lowPlayerNameQ.end(),lowPlayerNameQ.begin(),::tolower);

    for(int i=0; i<playerCount; i++)
    {
        // Get player name in list
        playerName=players[i].getName();

        // Copy player name and make copy lowercase
        lowPlayerName=playerName;

        ::transform(lowPlayerName.begin(),lowPlayerName.end(),lowPlayerName.begin(),::tolower);

        // Compare search term and player name in the list.
        // If there is a match then set current player object as result
        if(lowPlayerName.compare(lowPlayerNameQ)==0)
            pPtr=&players[i];
    }

    // Return result
    return pPtr;
}

void Team::copy(Team *t)
{
    // Set information
    t->setName(name);
    t->setColor(color);

    // Copy players
    copyPlayers(t);
}

void Team::displayDetailed()
{
    // Display information
    display();

    if(playerCount==0)
        cout<<"--EMPTY--"<<endl;
    else
    {
        for(int i=0; i<playerCount; i++)
            players[i].display();

    }

    cout<<"\n\n";
}

void Team::display()
{
    // Display information
    cout<<name<<", "<<color<<endl;
}

void Team::copyPlayers(Team *t)
{
    // Add players in this team to given team
    for(int i=0; i<playerCount; i++)
    {
        t->addPlayer(players[i].getName(),players[i].getPosition());
    }
}

void Team::removePlayerPtr(Player *p)
{
    // Create temporary list
    Player *tmp=new Player[playerCapacity];

    // If a player in the list does not match given object, add it to temporary list
    for(int i=0,j=0; i<playerCapacity; i++)
    {
        if(p!=&players[i])
        {
            tmp[j]=players[i];
            j++;
        }
    }

    // Delete current player list
    delete[] players;

    // Set temporary list to current list
    players=tmp;
}

void Team::increasePlayerCapacity()
{
    Player *tmp;

    playerCapacity*=2; // Increase capacity twice

    tmp=new Player[playerCapacity]; // Create temporary list

    // Copy players to temporary list
    for(int i=0; i<playerCount; i++)
    {
        tmp[i]=players[i];
    }

    // Delete current player list
    delete[] players;

    // Set temporary list to player list
    players=tmp;
}

void Team::decreasePlayerCapacity()
{
    Player* tmp;

    playerCapacity/=2; // Decrease capacity twice

    tmp=new Player[playerCapacity]; // Create temporary list

    // Copy players to temporary list
    for(int i=0; i<playerCount; i++)
        tmp[i]=players[i];


    // Delete current player list
    delete[] players;

    // Set temporary list to player list
    players=tmp;
}


