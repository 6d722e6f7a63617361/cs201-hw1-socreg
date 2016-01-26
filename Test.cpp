#include<string>
#include<iostream>
#include "SocReg.h"

using std::string;
using std::cout;
using std::endl;

int main()
{
    SocReg *sReg=new SocReg();

    // Add team and player
    sReg->addTeam("Galatasaray","Yellow-Red"); // Add Team
    sReg->addPlayer("Galatasaray","aRDa","FW");

    sReg->addPlayer("Galatasaray","arDa","FW");
    /*sReg->addTeam("Fenerbahce","Yellow-Blue");

    sReg->addPlayer("Fenerbahce","Luis Nani","LWF"); // Add Player
    sReg->addPlayer("Fenerbahce","RVP","SS"); // Add Player
    sReg->addPlayer("Galatasaray","LuCAS PoDOLski","FW");*/

    /*sReg->displayAllTeams();

    sReg->displayPlayer("veli");
    sReg->displayPlayer("RVP");

    sReg->displayTeam("fenerbahce");
    sReg->displayTeam("galatasaray");
    sReg->displayTeam("besiktas");

    sReg->removePlayer("galatasaray","Lucas Podolski");
    sReg->removeTeam("Fenerbahce");

    sReg->displayPlayer("Luis");*/


    delete sReg;
}

