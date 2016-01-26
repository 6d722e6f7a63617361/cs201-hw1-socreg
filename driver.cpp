#include<iostream>
#include "SocReg.h"

using namespace std;

void printMenu();
void handleMenuChoice(SocReg*,int);

/*int main()
{
    SocReg *sreg=new SocReg();
    int menuChoice;

    do
    {
        printMenu();

        cin>>menuChoice;

        handleMenuChoice(sreg,menuChoice);

        cout<<endl<<endl;

    }while(menuChoice!=8);

    cout<<"You've been exited from the SocReg...";

    delete sreg;
}
*/
void printMenu()
{
    cout<<"Welcome to SocReg please make a choice...\n\n";
    cout<<"1. Add a team"<<endl;
    cout<<"2. Remove a team"<<endl;
    cout<<"3. Add a player to the team"<<endl;
    cout<<"4. Remove a player from the team"<<endl;
    cout<<"5. Display all teams"<<endl;
    cout<<"6. Display a team"<<endl;
    cout<<"7. Find a player"<<endl;
    cout<<"8. Exit"<<endl<<endl;
    cout<<"Please enter the choice: ";
}

void handleMenuChoice(SocReg *sreg,int menuChoice)
{
    string teamName,teamColor;
    string playerName,playerPosition;

    if(menuChoice==1)
    {
        cout<<"Please enter team name: ";
        cin>>teamName;
        cout<<"Please enter team color: ";
        cin>>teamColor;

        sreg->addTeam(teamName,teamColor);
    }
    else if(menuChoice==2)
    {
        cout<<"Please enter team name: ";
        cin>>teamName;

        sreg->removeTeam(teamName);
    }
    else if(menuChoice==3)
    {
        cout<<"Please enter player name: ";
        cin>>playerName;

        cout<<"Please enter player position: ";
        cin>>playerPosition;

        cout<<"Please enter team name: ";
        cin>>teamName;

        sreg->addPlayer(teamName,playerName,playerPosition);
    }
    else if(menuChoice==4)
    {
        cout<<"Please enter player name: ";
        cin>>playerName;

        cout<<"Please enter team name: ";
        cin>>teamName;

        sreg->removePlayer(teamName,playerName);
    }
    else if(menuChoice==5)
    {
        sreg->displayAllTeams();
    }
    else if(menuChoice==6)
    {
        cout<<"Please enter team name: ";
        cin>>teamName;

        sreg->displayTeam(teamName);
    }
    else if(menuChoice==7)
    {
        cout<<"Please enter player name: ";
        cin>>playerName;

        sreg->displayPlayer(playerName);
    }
    else if(menuChoice!=8)
    {
        cout<<"You've entered invalid choice...."<<endl;
    }

}
