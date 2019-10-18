#include "supplies.h"
#include <string>
#include <math.h>
#include <iostream>
#include <string>
using namespace std;

supplies :: supplies()
{
    oxen = 0;
    wagon = 1;
    wagon_parts = 0;
    clothing = 0;
    bullets = 0;
    money = 1000.00;
    food = 0;
    medKits =0;
}

supplies :: supplies(int o, int wp, int c, int b, int f, float m, int w, int me)
{
    oxen = o;
    wagon_parts = wp;
    clothing =c;
    bullets = b;
    money = m;
    food = f;
    wagon = w;
    medKits = me;
}
void supplies :: setMoney(float new_money)
{
    money = new_money;
}

float supplies :: getMoney()
{
    return money;
}
void supplies :: setclothing(int new_clothing)
{
    clothing = new_clothing;   
}

int supplies :: getclothing()
{
    return clothing;
}
void supplies :: setBullets(int new_bullets)
{
    bullets = new_bullets;
}

int supplies :: getBullets()
{
    return bullets;
}
void supplies :: setOxen(int new_oxen)
{
    oxen = new_oxen;   
}

int supplies :: getOxen()
{
    return oxen;
}
void supplies :: setFood(int new_food)
{
    food = new_food;
}

int supplies :: getFood()
{
    return food;   
}
void supplies :: setWagon_parts(int wagon_parts2)
{
    wagon_parts = wagon_parts2;
}

int supplies :: getWagon_parts()
{
    return wagon_parts;
}
void supplies :: setWagon(int w)
{
    wagon = w;
}

int supplies :: getWagon()
{
    return wagon;
}
//--
void supplies :: setMedKits(int med)
{
    wagon = med;
}

int supplies :: getMedKits()
{
    return medKits;
}