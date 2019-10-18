#include "journey.h"
#include <string>
#include <math.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

/*Split
1. Check is string is empty.
2. Adds the seperastor given to the string that is given.
3. Usign a for loop, the function ill check every index in the string
4. It will look for the seperator. If the string at index i is the seperator, then it will create a substring and place that int the array.

int Split(string str, char separator, string fill[], int elements)//Start of Split function. Takes in multiple parameters
{
    int leftside = 0;//Declares and sets leftside to 0
    int loadcount = 0;//Declares and sets loadcount to 0
    
    if(str == "")//This checks if the string is empty
    {
        return 0;//return 0
    }
    
    str = str + separator;//Adds the seperator to string str.
    
    for(int i = 0; i < str.length(); i++)//For loop will run through every index in the string
    {
        if(str[i] == separator)//If the character at str[i] == seperator
        {
            string subs = str.substr(leftside, i - leftside);//
            leftside = i + 1;//sets leftside to index +1
            fill[loadcount] = subs;
            loadcount++;//Add one to loadcount
        }
    }
    
    return loadcount;//returns loadcount
}
*/

journey :: journey()
{
    currentDay = 0;
    currentMonth = 0;
    milesLeft = 2040;
    milesTraveled = 0;
    readFile("milestones.txt");
}
void journey :: setCurrentMonth(int month2)
{
    currentMonth = month2;    
}
int journey :: getCurrentMonth()
{
    return currentMonth;
}
void journey :: setCurrentDay(int day2)
{
    currentDay = day2;
}
int journey :: getCurrentDay()
{
    return currentDay;
}
void journey :: setMilesLeft(int n)
{
    milesLeft = n;
}
int journey :: getMilesLeft()
{
    return milesLeft;
}
void journey :: setMilesTraveled(int t)
{
    milesTraveled = t;
}
int journey:: getMilesTraveled()
{
    return milesTraveled;
}
void journey :: readFile(string filename)
{
    ifstream in_file;
    int counter = 0;
    in_file.open(filename);
     if(in_file.fail())
     {
         cout << "failed." << endl;
     }
     else
     {
         string line, line2;
         int i = 0;
         
         while(getline(in_file, line))
         {
             i =0;
            getline(in_file, line2);
            string parts[20];
            if(line2.front() == '\t')
                line2.erase(line2.begin());
             
            string name = line;
            stringstream ss(line2);
            while(getline(ss, parts[i], ' '))
                i++;
            landmarks[counter] = line;
            if(i == 1)
            {
                //landmark
                parts[0].erase(parts[0].length() -2, 2);
                miles[counter] = stoi(parts[0]);
                type[counter] = "Landmark";
            }
            else
            {
                parts[0].erase(parts[0].length() -2, 2);
                miles[counter] = stoi(parts[0]);
                type[counter] = parts[1];
                if(i == 3)
                {
                    parts[2].erase(parts[2].length() -2, 2);
                    depth[counter] = stoi(parts[2]);
                }
                    
            }
            
            counter++;
         }
             /*
             string words[10];
             
             
             int n  = Split(line, ',', words, 10);
             if(n == 4)
             {
                landmarks[counter] = words[0];
                miles[counter] = stoi(words[1]);
                type[counter] = words[2];
                depth[counter] = stoi(words[3]);
             }
             else if(n == 3)
             {
                landmarks[counter] = words[0];
                miles[counter] = stoi(words[1]);
                type[counter] = words[2];
             }
             else if(n==2)
             {
                landmarks[counter] = words[0];
                miles[counter] = stoi(words[1]);
             }
             cout << words[0] << endl;
             cout << words[1] << endl;
             cout << words[2] << endl;
             cout << words[3] << endl;
            counter++;
            
         }
         */
     }
     in_file.close();
    /*
      for(int i = 0; i < counter; i++)
        cout << depth[i] << endl;
    */
}

