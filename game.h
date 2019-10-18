#include <string>
#include <math.h>
#include <iostream>
#include <string>
using namespace std;
#include "player.h"
#include "journey.h"
#include "supplies.h"
#ifndef GAME_H
#define GAME_H

class game
{
  public:
    void intro();
    void store();
    void statusUpdate();
    int nextLandmarkIndex();
    int nextLandmark(int);
    void incrementDay(int);
    void decrementFood(int);
    bool isSick(int);
    int randomNumbers(int, int);
    bool puzzles();
    void Rest();
    void Continue();
    void takeTurn();
    void Hunt();
    void Quit();
    void misfortunes();
    void Win();
    void raidAttack();
    void Lose();
    void river_cross();
    void writeFile();
    
  private:
    player players[5];
    supplies inventory;
    journey trail;
    int aliveCount;
    int index;
};
#endif
