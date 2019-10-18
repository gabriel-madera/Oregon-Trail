#include <sstream>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#ifndef PLAYER_H
#define PLAYER_H
#include <math.h>

class player{
  public:
    player();
    player(string);
    string getName();
    void setName(string);
    int getHealth();
    void setHealth(int);
  
  private:
    string name;
    int health;
    float money;
    
};
#endif