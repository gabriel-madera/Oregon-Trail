#include <sstream>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#ifndef SUPPLIES_H
#define SUPPLIES_H
#include <math.h>

class supplies{
  public:
  supplies();
  supplies(int, int, int, int, int, float, int, int);
  
  void setWagon(int);
  int getWagon();
  void setMoney(float);
  float getMoney();
  int getOxen();
  void setOxen(int);
  int getclothing();
  void setclothing(int);
  int getBullets();
  void setBullets(int);
  int getFood();
  void setFood(int);
  int getWagon_parts();
  void setWagon_parts(int);
  int getMedKits();
  void setMedKits(int);
  
  
  private:
    int oxen;
    int wagon_parts;
    int clothing;
    int bullets;
    int food;
    float money;
    int wagon;
    int medKits;
    
    
};
#endif
