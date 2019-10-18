#include <sstream>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#ifndef JOURNEY_H
#define JOURNEY_H
#include <math.h>

class journey{
  public:
    journey();
    void setMilesLeft(int);
    int getMilesLeft();
    void setMilesTraveled(int);
    int getMilesTraveled();
    
    void setCurrentMonth(int);
    int getCurrentMonth();
    
    void setCurrentDay(int);
    int getCurrentDay();
    
    //arrays for landmarks
    string landmarks[15];
    int miles[15];
    string type[15];
    int depth[15];

    void readFile(string);
  private:
    int milesLeft;
    int milesTraveled;
    int currentMonth;
    int currentDay;
    
    
};
#endif