//CSCI1300
//Author:Gabriel Madera
//Recitation 204 - Chelsea Chandler
//Cloud9 Workspace Editor Link:https://ide.c9.io/gama9813/csci1300
//HW8

//All the code was run using the terminal below.
// Compile : g++ -std=c++11 oregonTrailDriver.cpp player.cpp journey.cpp supplies.cpp game.cpp -o OregonTrail
// Run : ./OregonTrail

#include <string>
#include <math.h>
#include <iostream>
#include <string>
using namespace std;
#include "player.h"
#include "journey.h"
#include "supplies.h"
#include "game.h"


int main()
{
    game game1;
    game1.intro();
    game1.statusUpdate();
    game1.takeTurn();
    return 0;
}


 
