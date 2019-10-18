#include <string>
#include <sstream>
#include <fstream>
#include <math.h>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
#include "game.h"

int game :: randomNumbers(int min, int max)
{
    // rand() % (max-min+1) + min
    return (rand() % (max-min+)) + min;
}

void game :: raidAttack()
{
    int raidChoice;
    cout << "Raiders ahead! They look hostile! "<< endl;
    cout << "You can either (1) Run, (2) Attack, or (3) Surrender. What will you do?" << endl;
    cin >> raidChoice;
        while(raidChoice != 1 && raidChoice != 2 && raidChoice != 3)
        {
            cout << "Invalid input! Please enter a valid choice beteween 1 and 3. " << endl;
            cin >> raidChoice;
        }
        
        if(raidChoice == 1)
        {
            cout << "You escape but you lose 1 ox, 10lbs of food, and 1 wagon part." << endl;
            inventory.setOxen(inventory.getOxen() - 1);
            inventory.setFood(inventory.getFood() - 10);
            inventory.setWagon_parts(inventory.getWagon_parts() - 1);
            
        }
        else if(raidChoice == 2)
        {
            bool raiderResponse = puzzles();
            if(raiderResponse == true)
            {
                cout << "You won the raid and won 50lbs of food and 50 bullets." << endl;
                inventory.setFood(inventory.getFood() + 50);
                inventory.setBullets(inventory.getBullets() + 50);
            }
            else
            {
                cout << "You lost the raid and lost 50lbs of food and 50 bullets." << endl;
                inventory.setFood(inventory.getFood() - 50);
                inventory.setBullets(inventory.getBullets() - 50);
            }
        }
        else if(raidChoice == 3)
        {
            cout << "You surrender and lose a quarter of your case reserves." << endl;
            inventory.setMoney(inventory.getMoney() - (inventory.getMoney()/4));
        }
}

void game :: misfortunes()
{
    int possibleMisfortune = randomNumbers(1, 5);
    if(possibleMisfortune == 1)
    {
        int i;
        int possibleDisease = randomNumbers(1,6);
        int randomVictim = randomNumbers(1,5);
        string victimName;
        string disease;
        
    //-------------------------------------RandomVictim
        if(randomVictim == 1)
        {
            victimName = players[0].getName();  
            players[0].setHealth(players[0].getHealth() -50);
            i = 0;
        }
        else if(randomVictim == 2)
        {
            victimName = players[1].getName();
            players[1].setHealth(players[1].getHealth() -50);
            i =1;
        }
        else if(randomVictim == 3)
        {
            victimName = players[2].getName();
            players[2].setHealth(players[2].getHealth() -50);
            i=2;
        }
        else if(randomVictim == 4)
        {
            victimName = players[3].getName();
            players[3].setHealth(players[3].getHealth() -50);
            i=3;
        }
        else if(randomVictim == 5)
        {
            victimName = players[4].getName(); 
            players[4].setHealth(players[4].getHealth() -50);
            i=4;
        }
    //----------------------------------------RandomDisease
        if(possibleDisease == 1)
        {
            disease = "typhoid";   
        }
        else if(possibleDisease == 2)
        {
            disease = "cholera";
        }
        else if(possibleDisease == 3)
        {
            disease = "diarrhea";
        }
        else if(possibleDisease == 4)
        {
            disease = "measles";
        }
        else if(possibleDisease == 5)
        {
            disease = "dysentery";
        }
        else if(possibleDisease == 6)
        {
            disease = "fever";
        }
        
        if(players[i].getHealth() > 0)
        {
            cout << "Oh no! " << victimName << " has " << disease << "!" << endl;
            
        }
        else if(players[i].getHealth() < 1)
        {
            cout << "Oh no! " << victimName << " has died of" << disease <<"!" << endl;
            aliveCount = aliveCount -1;
            players[i].setName("");
        }
            
    }
    else if(possibleMisfortune == 2)
    {
        inventory.setOxen(inventory.getOxen() -1);
        cout << "Oh no! One of the oxen has died! You have " << inventory.getOxen() <<" oxen left." << endl;
    }
    else if(possibleMisfortune == 3)
    {
        int foodStolen = randomNumbers(10,35);
        inventory.setFood(inventory.getFood() - foodStolen);
        cout << "Oh no! Last night you were attacked by a thief! You lost some food!" << endl;
    }
    else if(possibleMisfortune == 4)
    {
        cout << "Oh no! One of your wheels is broken!" << endl;
        inventory.setWagon_parts(inventory.getWagon_parts() -1);
    }
    else if(possibleMisfortune == 5)
    {
        int randStorm = randomNumbers(1,3);
        string storm;
        if(randStorm == 1)
        {
            storm = "heavy rain and hail";
            incrementDay(1);
        }
        if(randStorm == 2)
        {
            storm = "storm and blizzard";
            incrementDay(3);
        }
        if(randStorm == 3)
        {
            incrementDay(7);
            storm = "hurricane";
        }
        cout << "Oh no! The weather is rotten! There is " << storm << endl;
    }
}

bool game :: puzzles()
{
    int number = randomNumbers(1, 10);
    int guess1 = 0;
    int guess2 = 0;
    int guess3 = 0;
    cout << "Guess a number between 1 and 10. You have three chances to guess the right number. If you guess correctly you have a successful hunt." << endl;
    cout << "If you cant guess the correct number, you are not successful." << endl;
    cin >> guess1;
        if(guess1 == number)
        {
            cout << "You have guessed the number. Congrats! " << endl;
            return true;
        }
        else
        {
            cout << "You did not guess correctly. Try again. (You have 2 attempts left)" << endl;
            cin >> guess2;
        }
    //--------------------------------------------------------------------------------------------------    
        if(guess2 == number)
        {
            cout << "You have guessed the number. Congrats! " << endl;
            return true;
        }
        else
        {
            cout << "You did not guess correctly. Try again. (You have 1 attempt left)" << endl;
            cin >> guess3;
        }
    //---------------------------------------------------------------------------------------------------
        if(guess3 == number)
        {
            cout << "You have guessed the number. Congrats! " << endl;
            return true;
        }
        else
        {
            cout << "You did not guess correctly!" << endl;
            return false;
        }
    
}

// returns true if str is only made up of numbers
bool isAllNumbers(string str)
{
    if(str.empty())
        return false;
    
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] < '0' || str[i] > '9')
        {
            return false;
        }
    }
    return true;
}

void game :: store()
{
    char storeMenu;
    float totalBill = 0;
    cout << "You can buy whatever you need at Matt's General Store." << endl;
    cout << "Enter <s> to go to the store, or enter <q> to leave the store." << endl;
    cin >> storeMenu;
    if(storeMenu != 's')
    {
        if(storeMenu != 'q')
        {
            cout << "Please enter a valid input!" << endl;
            cin >> storeMenu;
        }
            
    }
    
    int yokesPurchased = 0;
    int yokesPurchased1 = 0;
    int lbsOfFood = 0;
    int bulletsPurchased = 0;
    int totalyokesPurchased = 0;
    int sparePartsPurchased = 0;
    int medKitsPurchased = 0;
    int store_counter = 0;
    string storeAnswer;
    int storeSelection;
    while(storeMenu != 'q')
    {
        cout << "You can buy:" << endl;
        cout << "1.Oxen " << endl << "2.Food " << endl << "3.Ammunition" << endl << "4.Spare Parts & Med Kits" << endl << "5.Leave the store" << endl << "What would you like?"<< endl;
        cin >> storeAnswer;
        while(isAllNumbers(storeAnswer) == false || (isAllNumbers(storeAnswer) == true && (stoi(storeAnswer) < 1 || stoi(storeAnswer) > 5)))
        {
            cout << "Invalid input! Please enter a number 1-5." << endl;
            cin >> storeAnswer;
        }
        storeSelection = stoi(storeAnswer);
        
        if(storeSelection == 5)
        {
            storeMenu = 'q';
            break;
        }

        
        while(storeSelection > 0 && storeSelection < 6)
        {
        //-------------------------------Oxen--------------------------------------------------------------------------------------------
            if(storeSelection == 1)
            {
                //cout<<"\n\nCounter "<<store_counter;
                
                if(store_counter == 0)
                {
                    cout << "You must spend between $100 and $200 in oxen. There are two oxen in a yoke. The price of a yoke is $40. How many yokes would you like to purchase?" << endl;
                    cin >> yokesPurchased;

                    while(yokesPurchased < 3 || yokesPurchased > 5)
                    {
                        cout << "Please choose again. Buy between $100 and $200 worth of yokes (between 3 and 5 yokes)." << endl;
                        cin >> yokesPurchased;
                    }
                    totalyokesPurchased = totalyokesPurchased + yokesPurchased;
                    totalBill = totalBill + (totalyokesPurchased*40);
                        
                    if(totalBill > 1000)
                    {
                        cout << "You don't have enough money! Please enter a new value. " << endl;
                        cin >> yokesPurchased;
                        totalBill = totalBill + (yokesPurchased*40);
                    }
                    cout << "Your current bill is $" << totalBill << endl;
                    store_counter++;
                    break;
                }
    //---------------------                
                if(store_counter == 1)
                {
                    cout << "You must spend between $100 and $200 in oxen only. There are two oxen in a yoke. The price of a yoke is $40. How many yokes would you like to purchase?" << endl;
                    cin >> yokesPurchased1;
                    totalyokesPurchased = totalyokesPurchased + yokesPurchased1;
                    while(totalyokesPurchased > 5|| totalyokesPurchased < 3)
                    {
                         cout << "Please choose again. Only buy between $100 and $200 worth of oxen." << endl;
                         cin >> yokesPurchased1;
                         totalyokesPurchased = yokesPurchased + yokesPurchased1;
                    }
                    totalBill = totalBill + (yokesPurchased1*40);
                        
                            if(totalBill > 1000)
                            {
                                cout << "You don't have enough money! Please enter a new value. " << endl;
                                cin >> yokesPurchased1;
                                totalBill = totalBill + (yokesPurchased1*40);
                            }
                        cout << "Your current bill is $" << totalBill << endl;
                        break;
                }
            }
            //------------------------------------------------------Food-----------------------------------------------------------------
            else if(storeSelection == 2)
            {
                cout << "It is recommended you purchase 200lbs of food for each person on the journey. The food costs $0.50 per pound." << endl << "How many pounds of food would you like to purchase?" << endl;
                cin >> lbsOfFood;
                totalBill = totalBill + (lbsOfFood*.50);
                    if(totalBill > 1000)
                    {
                        cout << "You don't have enough money! Please enter a new value. " << endl;
                        cin >> lbsOfFood;
                        totalBill = totalBill + (lbsOfFood*.50);
                    }
                cout << "Your current bill is $" << totalBill << endl;
                break;
            }
            //-----------------------------------------------Bullets-----------------------------------------------------------------
            else if(storeSelection == 3)
            {
                cout << "One bullet costs $0.10(10cents). How many bullets would you like to buy?" << endl;
                cin >> bulletsPurchased;
                totalBill = totalBill + (bulletsPurchased*.10);
                    if(totalBill > 1000)
                        {
                            cout << "You don't have enough money! Please enter a new value. " << endl;
                            cin >> bulletsPurchased;
                            totalBill = totalBill + (bulletsPurchased*.10);
                        }
                    cout << "Your current bill is $" << totalBill << endl;
                    break;
            }
            //---------------------------------------------------------Miscellanous-----------------------------------------------------
            else if(storeSelection == 4)
            {
                cout << "Spare wagon parts cost $20 each. How many wagon parts would you like to buy?" << endl;
                cin >> sparePartsPurchased;
                totalBill = totalBill +(sparePartsPurchased*20);
                    if(totalBill > 1000)
                        {
                            cout << "You don't have enough money! Please enter a new value. " << endl;
                            cin >> sparePartsPurchased;
                            totalBill = totalBill + (sparePartsPurchased*20);
                        }
                cout << "A Med kit costs $25 each. How many Med Kits would you like to buy? " << endl;
                cin >> medKitsPurchased;
                totalBill = totalBill + (medKitsPurchased*25);
                    if(totalBill > 1000)
                        {
                            cout << "You don't have enough money! Please enter a new value. " << endl;
                            cin >> medKitsPurchased;
                            totalBill = totalBill + (medKitsPurchased*25);
                        }
                    cout << "Your current bill is $" << totalBill << endl;
                    break;
            }
        }
    }
    if(storeMenu == 'q')
    {
        cout << "Your total bill is $" << totalBill << endl;
        cout << trail.miles[0];
        inventory.setMoney(inventory.getMoney() - totalBill);
        inventory.setBullets(inventory.getBullets() + bulletsPurchased);
        inventory.setFood(inventory.getFood() + lbsOfFood);
        inventory.setOxen(inventory.getOxen() + totalyokesPurchased*3);
        inventory.setWagon_parts(inventory.getWagon_parts() + sparePartsPurchased);
        inventory.setMedKits(inventory.getMedKits() + medKitsPurchased);
        
        
    }


}

void game ::incrementDay(int nDays)
{
       int tempday = trail.getCurrentDay()+ nDays;
       if(trail.getCurrentMonth() == 1 || trail.getCurrentMonth() == 3 || trail.getCurrentMonth() == 5 || trail.getCurrentMonth() == 7 || trail.getCurrentMonth() == 9 || trail.getCurrentMonth() == 11 )
       {
           if(tempday > 31)
           {
               trail.setCurrentMonth(trail.getCurrentMonth()+1);
               trail.setCurrentDay(tempday - 31);
           }
           else
           {
                trail.setCurrentDay(tempday);
           }
       }
       else if(trail.getCurrentMonth() == 2 || trail.getCurrentMonth() == 4 || trail.getCurrentMonth() == 6 || trail.getCurrentMonth() == 8 || trail.getCurrentMonth() == 10 || trail.getCurrentMonth() == 12)
       {
           if(tempday > 30)
           {
               trail.setCurrentMonth(trail.getCurrentMonth()+1);
               trail.setCurrentDay(tempday - 30);
           }
           else
           {
               trail.setCurrentDay(tempday);
           }
       }
}

bool game :: isSick(int i)
{
        int x = players[i].getHealth();
        if(x < 100)
        {
            return true;
        }
        else
        {
            return false;
        }
}

void game :: decrementFood(int nFood)
{
    inventory.setFood(inventory.getFood() - nFood);
}

void game :: intro()
{
//------------------------------------------------Asks for Names----------------------------------------------------------------
    
    //player player1;
    string names[5];
    int storeSelection =0;
    
    cout << "Enter your name and four other people who will join you:" << endl;
    for(int i = 0; i < 5; i++)
    {
        cin >> names[i];
        players[i] = player(names[i]);
    }
    cout << endl;
    
    cout << "Thank you " << names[0] << "!" << endl;

//------------------------------------------------------Asks for month-------------------------------------------------------------
    
    char choice;
    int startDay;
    int startMonth;
    
    cout << "You can start your journey at the default date (03/28/1847) or you can choose a custom departure date. Enter either <d> for default or <c> for custom date" << endl;
    cin >> choice;
    if(choice != 'd')
    {
        if(choice != 'c')
        {
            cout << "Invalid input. Please enter either <c> or <d> ." << endl;
            cin >> choice;
        }
    }
        if(choice == 'd')
        {
            cout << "You will start your journey on (03/28/1847)" << endl;
            startDay = 28;
            startMonth = 3;
        }
        else if(choice == 'c')
        {
            cout << "Enter your starting month. You can only leave between March and May. E.g. March should be written as <3>" << endl;
            cin >> startMonth;
            
                while(startMonth < 3 || startMonth > 5)
                {
                    cout << "invalid input! Please enter a month between 3 and 5." << endl;
                    cin >> startMonth;
                }
            
            cout << "Enter your starting day. E.g. The 28th should be written as <28> ." << endl;
            cin >> startDay;

                while(startDay > 31 || startDay < 1)
                {
                    cout << "invalid input! Please enter a day between 1 and 31." << endl;
                    cin >> startDay;
                }
        }
        cout << "You will be leaving on " << startMonth << "/" << startDay << "/1847." << endl;
        trail.setCurrentMonth(startMonth);
        trail.setCurrentDay(startDay);

        store();

        aliveCount = 5;
        trail.setMilesLeft(2040);
        trail.setMilesTraveled(0);
        index = 0;
}

int game :: nextLandmarkIndex()
{
    int x = trail.getMilesTraveled();
    for(int i = 0; i < 15; i++)
    {
        if(trail.miles[i] >= x)
        {
            return i;
        }
    }
}

int game :: nextLandmark(int i)
{
    i = nextLandmarkIndex();
    int miles_Landmark = trail.miles[i] - trail.getMilesTraveled();
    return miles_Landmark;
}

void game :: statusUpdate()
{
    int land = nextLandmarkIndex();
    
    cout << endl;
    cout << "STATUS UPDATE:" << endl;
    cout << "Current Date: " <<  trail.getCurrentMonth() << "/" << trail.getCurrentDay() << "/1847." << endl;;
    cout << "Miles Traveled: " << trail.getMilesTraveled() << endl;
    cout << "Next Landmark: " << nextLandmark(land) << " miles" << endl;
    cout << "Food Available: " << inventory.getFood() << endl;
    cout << "Number of bullets available: " << inventory.getBullets() << endl;
    cout << "Cash available: " << inventory.getMoney() << endl;
    
}


void game :: takeTurn()
{
    
        string turnChoice;
        while(true)
        {
            // check if leader die
            if(players[0].getHealth() < 1)
            {
                cout << "Your leader has died!" << endl;
                Lose();
            }
            // food done
            if(inventory.getFood() < 1)
            {
                cout << "You ran out of food before reaching a fort!" << endl;   
                Lose();
            }
            // oxen done
            if(inventory.getOxen() < 1)
            {
                cout << "You ran out of oxen!" << endl;
                Lose();
            }
            // days done
            if(trail.getCurrentDay() == 30 && trail.getCurrentMonth() == 11 || trail.getCurrentMonth() > 11)
            {
                cout << "You didn't make it in time!" << endl;
                Lose();
            }
            // distance finished => win
            if(trail.getMilesTraveled() == 2040 || trail.getMilesLeft() == 0)
            {
                cout << "winner, winner, chicken dinner!" << endl;
                Win();
            }
            if(inventory.getWagon_parts() < 0)
            {
                cout << "Your wagon is broken and you dont have any spare parts." << endl;
                Lose();
            }
            else
            {
            
                cout << "What would you like to do next? You can either (r)est for a few days, (c)ontinue the trail, (h)unt for a bit, or (q)uit the game. " << endl;
                cin >> turnChoice;
                while(turnChoice != "r" && turnChoice != "c" && turnChoice != "h" && turnChoice != "q")
                {
                    cout << "Invalid input! Please enter a letter, either <r>, <c>, <h>, or <q>." << endl;
                    cin >> turnChoice;
                }
            
                if(turnChoice == "r")
                {
                    Rest();
                }
                else if(turnChoice == "c")
                {
                    Continue();
                }
                else if(turnChoice == "h")
                {
                    Hunt();   
                }
                else if(turnChoice == "q")
                {
                    Quit();
                }
            }
            int possMis = randomNumbers(1,5);
            if(possMis == 1 || possMis == 2)
            {
                misfortunes();
                
            } 
        
            srand(time(0));
            float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
            float distance = trail.getMilesTraveled() * 1.0;
            float tBob = pow((distance/100)-4, 2);
            float probR = (((tBob + 72)/(tBob+12))-1)/10;
            if (r > probR)
            {
                raidAttack();
            }
        
        
        }
       
}


void game :: Rest()
{
    int restDays;
    int lbsFoodEaten;
    cout << "How many days would you like to rest for? You can rest between 1 and 3 days." << endl;
    cin >> restDays;
        while(restDays < 1 || restDays > 3)
        {
            cout << "Invalid input" << endl;
            cin >> restDays;
        }
   
    if(restDays == 1)
    {
        incrementDay(1);
        lbsFoodEaten = aliveCount*3;
        decrementFood(lbsFoodEaten);
    }
    else if(restDays == 2)
    {
        incrementDay(2);
        lbsFoodEaten = 2*(aliveCount *3);
        decrementFood(lbsFoodEaten);
        
        for(int x = 0; x < 5 ; x++)
        {
            if(isSick(x) == true)
            {
                players[x].setHealth(100);
            }
        }
  
    }
    else if(restDays == 3)
    {
        incrementDay(3);
        lbsFoodEaten = 3*(aliveCount *3);
        decrementFood(lbsFoodEaten);
        
        for(int x = 0; x < 5 ; x++)
        {
            if(isSick(x) == true)
            {
                players[x].setHealth(100);
            }
        }
    }
    statusUpdate();
}

void game :: Continue()
{
    int landmarkIndex = nextLandmarkIndex();

    int randomDistance = randomNumbers(70,140);
    incrementDay(14);
    int lbs_Food_Eaten = (aliveCount*3)*14;
    decrementFood(lbs_Food_Eaten);
        if(randomDistance >= nextLandmark(landmarkIndex))
        {
            randomDistance = nextLandmark(landmarkIndex);
            trail.setMilesTraveled(trail.getMilesTraveled()+ randomDistance);
            cout << "You stopped at " << trail.landmarks[landmarkIndex] << "." << endl;
            if(trail.type[landmarkIndex] == "Landmark")
            {
                int choice;
                    if(inventory.getFood() < 1)
                    {
                        cout << "You ran out of food before reaching a fort!" << endl;   
                        Lose();
                    }
                cout << "Would you like to (1)Rest or (2)Continue?" << endl;
                cin >> choice;
                if(choice == 1)
                {
                    Rest();
                }
                else if(choice == 2)
                {
                    trail.setMilesTraveled(trail.getMilesTraveled() +1);
                    trail.setMilesLeft(trail.getMilesLeft() -1);
                    Continue();
                }
            }
            else if(trail.type[landmarkIndex] == "Fort")
            {
                int choice;
                    if(inventory.getFood() < 1)
                    {
                        cout << "You ran out of food before reaching a fort!" << endl;   
                        Lose();
                    }
                cout << "Would you like to (1)Rest or (2)Continue, or (3)Visit the store?" << endl;
                cin >> choice;
                while(choice != 1 && choice != 2)
                {
                    if(choice == 3)
                    {
                    statusUpdate();
                    store();
                    }
                }
                    if(choice == 1)
                    {
                        Rest();
                    }
                    else if(choice == 2)
                    {
                        trail.setMilesTraveled(trail.getMilesTraveled() +1);
                        trail.setMilesLeft(trail.getMilesLeft() -1);
                        Continue();//---------------------------------------------------------------
                    }
                
            }
            else if(trail.type[landmarkIndex] == "River")
            {
                river_cross();
            }
            
            
        }
        else
        {
            trail.setMilesTraveled(trail.getMilesTraveled() + randomDistance);
            trail.setMilesLeft(2040 - trail.getMilesTraveled());
        }

    
    for(int i =0; i < 5; i++)
    {
        players[i].setHealth(100);
    }
    
    
    statusUpdate();
}

void game :: Hunt()
{
    incrementDay(1);
    bool flag;
    cout << "You decided to hunt for the day." <<endl;
    int r = randomNumbers(1,100);
    if(r <= 50)
    {
        int choiceR;
        cout << "You got lucky! You have encontered a rabbit! Would you like to hunt it? (1) Yes, (2) No. " << endl;
        flag = true;
        cin >> choiceR;
            while(choiceR != 1 && choiceR != 2)
            {
                cout << "Invalid input! Please enter <1> or <2>." << endl;
                cin >> choiceR;
            }
                if(choiceR == 1 && inventory.getBullets() >= 10)
                {
                    cout << "You have decided to hunt the rabbit! So, solve this problem." << endl;
                    bool rResponse = puzzles();
                    if(rResponse == true)
                    {
                        cout << "Your hunt was successful!" << endl;
                        inventory.setFood(inventory.getFood() + 2);
                        inventory.setBullets(inventory.getBullets() - 10);
                    }
                    else
                    {
                        cout << "Your hunt was unsuccessful" << endl;
                    }
                    
                }
                else if(choiceR == 1 && inventory.getBullets() < 10)
                {
                    cout << "Your hunt was unsuccessful" << endl;
                }
                else if(choiceR == 0)
                {
                    cout << "You let the rabbit go." << endl;
                }
    }
    int f = randomNumbers(1,100);
    if(f <= 25)
    {
        int choiceF;
        cout << "You got lucky! You have encountered a fox! Would you like to hunt it? (1) Yes, (2) No. " << endl;
        flag = true;
        cin >> choiceF;
            while(choiceF != 1 && choiceF != 2)
            {
                cout << "Invalid input! Please enter <1> or <2>." << endl;
                cin >> choiceF;
            }
                if(choiceF == 1 && inventory.getBullets() >= 10)
                {
                    cout << "You have decided to hunt the fox! So, solve this problem." << endl;
                        bool fResponse = puzzles();
                        if(fResponse == true)
                        {
                            cout << "Your hunt was successful!" << endl;
                            inventory.setFood(inventory.getFood() + 5);
                            inventory.setBullets(inventory.getBullets() - 8);
                        }
                        else
                        {
                            cout << "Your hunt was unsuccessful" << endl;
                        }
                }
                else if(choiceF == 1 && inventory.getBullets() < 10)
                {
                    cout << "Your hunt was unsuccessful!" << endl;
                    inventory.setFood(inventory.getFood() + 5);
                }
                else if(choiceF == 0)
                {
                    cout << "You let the fox go." << endl;
                }
    }
    int d = randomNumbers(1,100);
    if(d <= 15)
    {
        int choiceD;
        cout << "You got lucky! You have encountered a deer! Would you like to hunt it? (1) Yes, (2) No. " << endl;
        flag = true;
        cin >> choiceD;
            while(choiceD != 1 && choiceD != 2)
            {
                cout << "Invalid input! Please enter <1> or <2>." << endl;
                cin >> choiceD;
            }
                if(choiceD == 1 && inventory.getBullets() >= 10)
                {
                    cout << "You have decided to hunt the deer! So, solve this problem." << endl;
                        bool dResponse = puzzles();
                        if(dResponse == true)
                        {
                            int randomD = randomNumbers(30, 55);
                            cout << "Your hunt was successful!" << endl;
                            inventory.setFood(inventory.getFood() + randomD);
                            inventory.setBullets(inventory.getBullets() - 5);
                        }
                        else
                        {
                            cout << "Your hunt was unsuccessful" << endl;
                        }
                    
                }
                else if(choiceD == 1 && inventory.getBullets() < 10)
                {
                    cout << "Your hunt was unsuccessful!" << endl;

                }
                else if(choiceD == 0)
                {
                    cout << "You let the deer go." << endl;
                }
    }
    int b = randomNumbers(1,100);
    if(b <= 7)
    {
        int choiceB;
        cout << "You got lucky! You have encountered a bear! Would you like to hunt it?  (1) Yes, (2) No. " << endl;
        flag = true;
        cin >> choiceB;
            while(choiceB != 1 && choiceB != 2)
            {
                cout << "Invalid input! Please enter <1> or <2>." << endl;
                cin >> choiceB;
            }
                if(choiceB == 1 && inventory.getBullets() >= 10)
                {
                    cout << "You have decided to hunt the bear! So, solve this problem." << endl;
                        bool bResponse = puzzles();
                        if(bResponse == true)
                        {
                            int randomB = randomNumbers(100, 200);
                            cout << "Your hunt was successful!" << endl;
                            inventory.setFood(inventory.getFood() + randomB);
                            inventory.setBullets(inventory.getBullets() - 10);
                        }
                        else
                        {
                            cout << "Your hunt was unsuccessful" << endl;
                        }
                }
                else if(choiceB == 1 && inventory.getBullets() < 10)
                {
                    cout << "Your hunt was unsuccessful!" << endl;

                }
                else if(choiceB == 0)
                {
                    cout << "You let the bear go." << endl;
                }
    }
    int m = randomNumbers(1,100);
    if(m <= 5)
    {
        int choiceM;
        cout << "You got lucky! You have encountered a moose! Would you like to hunt it?  (1) Yes, (2) No. " << endl;
        cin >> choiceM;
        flag = true;
            while(choiceM != 1 && choiceM != 2)
            {
                cout << "Invalid input! Please enter <1> or <2>." << endl;
                cin >> choiceM;
            }
                if(choiceM == 1 && inventory.getBullets() >= 10)
                {
                    cout << "You have decided to hunt the moose! So, solve this problem." << endl;
                        bool mResponse = puzzles();
                        if(mResponse == true)
                        {
                            int randomM = randomNumbers(300, 600);
                            cout << "Your hunt was successful!" << endl;
                            inventory.setFood(inventory.getFood() + randomM);
                            inventory.setBullets(inventory.getBullets() - 12);
                        }
                        else
                        {
                            cout << "Your hunt was unsuccessful" << endl;
                        }
                    
                }
                else if(choiceM == 1 && inventory.getBullets() < 10)
                {
                    cout << "Your hunt was unsuccessful!" << endl;

                }
                else if(choiceM == 0)
                {
                    cout << "You let the moose go." << endl;
                }
    }
    int meal;
    int lbsEatenH;
        if(flag == false)
        {
            cout <<"Unfortunately, you didn't find anything." <<endl;
        }
    
    cout << "How well do you want to eat? (1) Poorly, (2) Moderately, or (3) Well ." << endl;
    cin >> meal;
        while(meal != 1 && meal != 2 && meal != 3)
        {
            cout << "Invalid input. Please enter a number 1-3." << endl;
            cin >> meal;
        }
    if(meal == 3)
    {
        lbsEatenH = aliveCount*5;
    }
    else if(meal == 2)
    {
        lbsEatenH = aliveCount*3;
    }
    else if(meal == 1)
    {
        lbsEatenH = aliveCount*2;
    }
    inventory.setFood(inventory.getFood() - lbsEatenH);
    if(inventory.getFood() > 1000)
    {
        cout << "Your wagon is full! You had to leave behind some food!" << endl;
        inventory.setFood(1000);
    }
    
    statusUpdate();
    
    for(int i=0; i < 5; i++)
    {
        bool temp = isSick(i);
        if(temp == true && meal == 3)
        {
            players[i].setHealth(100);
        }
    }
}
void game :: Quit()
{
    cout << " I'm sorry that you decided to quit. Better luck next time!" << endl;
    writeFile();
    exit(0);
}

void game :: Win()
{
    cout << "Congrats you beat the game! And you made it to Oregon!" <<endl;
    writeFile();
    exit(0);
}

void game :: Lose()
{
    cout << "You lost! Better luck next time! " << endl;
    writeFile();
    exit(0);
}

void game :: river_cross()
{
    int landIndex = nextLandmarkIndex();
    int decis;
    //cout << "value: " << trail.depth[landIndex] << endl;
    //cout << "landINdex : "<< landIndex << endl;
    if(trail.depth[landIndex] > 3)
    {
        cout << "The river is too deep. You will require a ferry to cross it. The ferry costs $10 per person." << endl;
        cout << "Would you like to (1)Cross or (2)Rest." << endl;
        cin >> decis;
        while(decis < 1 || decis > 2)
        {
            cout << "Invalid input. Please enter a number either 1 or 2." << endl;
            cin >> decis;
        }
        if(decis == 1)
        {
            inventory.setMoney(inventory.getMoney() - (10*aliveCount));
            trail.setMilesTraveled(trail.getMilesTraveled() +1);
            trail.setMilesLeft(trail.getMilesLeft() -1);
            statusUpdate();
            takeTurn();
        }
        else if(decis == 2)
        {
            Rest();
        }
    }
    else if(trail.depth[landIndex] < 4)
    {
        if(inventory.getFood() < 1)
            {
                cout << "You ran out of food before reaching a fort!" << endl;   
                Lose();
            }
        cout << "Would you like to (1)Continue or (2)Rest?" << endl;
        cin >> decis;
        while(decis < 1 || decis > 2)
        {
            cout << "Invalid input. Please enter a number either 1 or 2." << endl;
            cin >> decis;
        }
        
        if(decis == 1)
        {
            trail.setMilesTraveled(trail.getMilesTraveled() +1);
            trail.setMilesLeft(trail.getMilesLeft() -1);
            Continue();
            statusUpdate();
            
        }
        else if(decis == 2)
        {
            Rest();
        }
        
    }
}
void game :: writeFile()
{
    if(inventory.getFood() > 1)
    {
        inventory.setFood(0);
    }
    
    if(inventory.getMoney() > 1)
    {
        inventory.setMoney(0);
    }
    
    ofstream outfile;
    outfile.open("results.txt", ios::app);
    
    if(outfile.fail())
    {
        cout << "failed" << endl;
    }
    else
    {
        outfile << "Leader name: " << players[0].getName() << ", Miles Traveled: " << trail.getMilesTraveled() << ", Food Remaining: " << inventory.getFood() << ", Cash remaining: " << inventory.getMoney() << ".";
    }
    
    outfile.close();
}