#include "player.h"
#include <string>
#include <math.h>
#include <iostream>
#include <string>
using namespace std;

player :: player()
{
    name = "";
    health = 100;
}
player :: player(string name2)
{
    name = name2;
    health = 100;
}

string player :: getName()
{
    return name;
}
void player :: setName(string name2)
{
    name = name2;
}
int player :: getHealth()
{
    return health;
}
void player :: setHealth(int health2)
{
    health = health2;
}