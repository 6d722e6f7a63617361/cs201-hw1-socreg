#include<string>
#include<iostream>
#include<iomanip>
#include "Player.h"

using namespace std;

Player::Player(string name,string position)
{
    // Set name and position
    setName(name);
    setPosition(position);
}

void Player::setName(string name)
{
    this->name=name;
}

void Player::setPosition(string position)
{
    this->position=position;
}

string Player::getName()
{
    return name;
}

string Player::getPosition()
{
    return position;
}

void Player::display()
{
    // Display position
    cout<<name<<", "<<position<<endl;
}
