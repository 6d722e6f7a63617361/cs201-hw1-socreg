#include<iostream>
#include<iomanip>
#include<algorithm>
#include<string>
#include "SocReg.h"

using namespace std;

SocReg::SocReg()
{
    // Set default capacity and team count
    capacity=1;
    teamCount=0;

    // Create team list
    teams=new Team[capacity];
}

SocReg::~SocReg()
{
    // Delete team list from memory
    delete[] teams;
}

void SocReg::addTeam(string teamName,string teamColor)
{
    // Search for a team with given name
    if(searchTeam(teamName)!=NULL)
    {
        // If the team exists then print failure message
        cout<<"The team \'"<<teamName<<"\' does exist..."<<endl;
    }
    else
    {
        // Set next empty team object information
        teams[teamCount].setName(teamName);
        teams[teamCount].setColor(teamColor);

        // Increase team count
        teamCount++;

        // If capacity is full then increase capacity
        if(teamCount==capacity)
            increaseTeamCapacity();

        // Print success message
        cout<<"The team \'"<<teamName<<"\' has been added..."<<endl;
    }
}

void SocReg::removeTeam(string teamName)
{
    Team *t;

    // Search for team
    t=searchTeam(teamName);

    if(t==NULL)
    {
        // If the team with given name does not exist, then print failure message
        cout<<"The team \'"<<teamName<<"\' does not exist..."<<endl;
    }
    else
    {
        // Remove team from list
        removeTeamPtr(t);

        // Decrease team count
        teamCount--;

        // If team count is less than half of capacity, then decrease team list capacity
        // for memory optimization
        if(teamCount<capacity/2)
            decreaseTeamCapacity();

        // print success message
        cout<<"The team \'"<<teamName<<"\' has been deleted..."<<endl;
    }
}

void SocReg::addPlayer(string teamName,string playerName,string playerPosition)
{
    Team *tPtr=NULL;

    // Search for the team with given name
    tPtr=searchTeam(teamName);

    if(tPtr==NULL)
    {
        // If the team with given name does not exist, print failure message
        cout<<"The team \'"<<teamName<<"\' does not exist..."<<endl;
    }
    else
    {
        // Try to add player and print the result
        if(!tPtr->addPlayer(playerName,playerPosition))
            cout<<"The player \'"<<playerName<<"\' does exist..."<<endl;
        else
            cout<<"The player \'"<<playerName<<"\' has been added to team \'"<<teamName<<"\'..."<<endl;
    }
}

void SocReg::removePlayer(string teamName,string playerName)
{
    Team *tPtr;

    // Search for team with given name
    tPtr=searchTeam(teamName);

    if(tPtr==NULL)
        // If team with given name does not exits, print failure message
        cout<<"The team \'"<<teamName<<"\' does not exist..."<<endl;
    else
    {
        // Try to remove player and print result
        if(!tPtr->removePlayer(playerName))
            cout<<"The player \'"<<playerName<<"\' does not exist in team \'"<<teamName<<"\'..."<<endl;
        else
            cout<<"The player \'"<<playerName<<"\' has been removed from team \'"<<teamName<<"\'..."<<endl;
    }

}

void SocReg::displayAllTeams()
{
    // Display teams
    if(teamCount==0)
        cout<<"--EMPTY--";
    else
    {
        for(int i=0;i<teamCount;i++)
        {
            teams[i].display();
        }
    }
}

void SocReg::displayPlayer(string playerName)
{
    Player *pPtr;
    int playerCount;

    playerCount=0;

    cout<<playerName<<endl;

    // Search for a player with given name in every team and print result
    for(int i=0;i<teamCount;i++)
    {
        pPtr=teams[i].searchPlayer(playerName);

        if(pPtr!=NULL)
        {
            cout<<pPtr->getPosition()<<", "<<teams[i].getName()<<", "<<teams[i].getColor()<<endl;

            playerCount++;
        }
    }

    // If there is no player with given player than print empty message
    if(playerCount==0)
        cout<<"--EMPTY--"<<endl;
}
void SocReg::displayTeam(string teamName)
{
    Team *tPtr;

    // Search for the team with given name
    tPtr=searchTeam(teamName);

    // If any team with given name does not exist, print failure message
    // otherwise print detailed team information
    if(tPtr==NULL)
        cout<<"The team does not exist"<<endl;
    else
        tPtr->displayDetailed();
}

Team* SocReg::searchTeam(string teamNameQ)
{
    string lowTeamNameQ,lowTeamName;

    lowTeamNameQ=teamNameQ;

    // Make lowercase given search term
    transform(lowTeamNameQ.begin(),lowTeamNameQ.end(),lowTeamNameQ.begin(),::tolower);

    for(int i=0;i<teamCount;i++)
    {
        // Get team name in list
        lowTeamName=teams[i].getName();

        // Make team name lowercase
        transform(lowTeamName.begin(),lowTeamName.end(),lowTeamName.begin(),::tolower);

        // Compare search term and team name in the list.
        // If there is a match then return current team object's address
        if(lowTeamName.compare(lowTeamNameQ)==0)
            return &teams[i];
    }

    // If there is no team matching given name then return null
    return NULL;
}

void SocReg::increaseTeamCapacity()
{
    Team *tmp;

    capacity*=2; // Increase capacity twice

    tmp=new Team[capacity]; // Create temporary list

    // Copy teams to temporary list
    for(int i=0;i<teamCount;i++)
    {
        teams[i].copy(&tmp[i]);
    }

    // Delete current team list
    delete[] teams;

    // Set temporary list to team list
    teams=tmp;
}

void SocReg::decreaseTeamCapacity()
{
    Team *tmp;

    capacity/=2; // Decrease capacity twice

    tmp=new Team[capacity]; // Create temporary list

    // Copy teams to temporary list
    for(int i=0;i<capacity;i++)
    {
        teams[i].copy(&tmp[i]);
    }

    // Delete current team list
    delete[] teams;

    // Set temporary list to team list
    teams=tmp;
}

void SocReg::removeTeamPtr(Team *tPtr)
{
    Team *tmp;

    // Create temporary list
    tmp=new Team[capacity];

    // If a team in the list does not match given object, add it to temporary list
    for(int i=0,j=0;i<capacity;i++)
    {
        if(tPtr!=&teams[i])
        {
            teams[i].copy(&tmp[i]);

            j++;
        }
    }

    // Delete current team list
    delete[] teams;

    // Set temporary list to team list
    teams=tmp;
}

