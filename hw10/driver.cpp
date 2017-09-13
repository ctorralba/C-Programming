/*
Programmer: Christopher Torralba      Date: 11/9/2015
Instructor: Leopold
Section: J
Purpose: Main file demonstrating the uses of the animal, car, and road classes
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <fstream>

#include "driver.h"
#include "road.h"
#include "animal.h"
#include "car.h"
#include "pedestrian.h"
using namespace std;

int main ()
{
  srand(time(NULL));
  for (short j = 1; j <= 3; j++)
  {
    Road r1;
    animal a[10];
    Car c1;
    short km = 0,carMove, event, pedEnters, animalNum, loserStarNum,
          loserStarCount = 0, animalStart;
    string announce;
    ifstream fin;
    ofstream fout;
    bool catHit = false, possumHit = false, deerHit = false, slugHit = false,
         pengHit = false, armadHit = false, chickenHit = false,
         giraffeHit = false, dolphinHit = false, whaleHit = false;
                  
//Setting animals into an array
    fin.open("animals.dat");
    for (short i = 0; i < 10; i++)
    {
      fin >> a[i].animalName;
      fin >> a[i].width;
      fin >> a[i].weight;
      fin >> a[i].stupidity;
    }
                      
    fin.close();
  //Starting message
    if (j != 1)
    {
      cout << endl;
    }
    cout << "~~~~~~~~~~Simulation " << j << "~~~~~~~~~~~~" << endl;
    cout << "The car with battery life " << c1.getBattery()
         << " now begins its trip..." << endl;
    c1.enter_a_road(r1,(STARTSECTORWIDTH/2)-1);
    do
    {
      carMove = ((rand() % 3)-1);
         //uses -1 0 1 representing left, none, or right
      c1.enter_a_road(r1, c1.getCarPos()+carMove);
      //road display               
      cout << r1 << "   Distance: " << km << "km, Battery: "
           << c1.getBattery()<<"%, Damage: " << c1.getDamage()
           << "% "<< endl; 
    //1 mi has elapsed mark
      km++;
      c1.batteryOverTime();
      event = (rand() % 95);
    //~~~~~~Event check~~~~~~~~~~
      if (event < 5)
      {
        pedEnters = (rand () % 2);
     //~~~~~~Pedestrian check~~~~~~~~~
        if (pedEnters == 0)
        {
          Pedestrian p1;
          cout << endl;
          cout << "Pedestrian " << p1.getName() << " (blood alcohol content "
               << p1.getBAC() << ") entering road..." << endl;
          p1.walk(r1, c1);
        }
        else
        //~~~~~~~Animal check~~~~~~~~~
        {
          c1.batteryOverTime();
          animalNum = (rand() % 10); //random animal selection
          animalStart = (rand() % r1.getWidth()); //where animal pops up
          r1.place_obj(a[animalNum].width, animalStart, Animal::m_Symbol);
          if (!(isHit(r1))) //if not hit by the car displays normal
          {
            cout << r1 << "   Distance: " << km << "km, Battery: " 
                 << c1.getBattery() <<"%, Damage: " << c1.getDamage()
                 << "% "<< endl;
          }
          else //if it is hit by a car displays different
          {
            c1.incrBattery(a[animalNum].weight);
            c1.incrDamage(a[animalNum].weight);
            cout << endl;
            cout << r1 << "   Distance: " << km << "km, Battery: " 
                 << c1.getBattery()<<"%, Damage: " << c1.getDamage()
                 << "% "<< endl;
            fin.clear();
            fin.open("announcements.dat");
            loserStarNum = (rand() % 10);
            loserStarCount = 0;
            //announcements
            while (getline(fin, announce, '\n'))
            {
              if (loserStarCount == loserStarNum)
              {
                cout << announce << endl;
              }
              loserStarCount++;
            }
            fin.close();
            cout << "You've hit a " << a[animalNum].animalName << "!!!"
                 << " Can I be of assistance?" << endl;
              
            switch (animalNum)
            {
              case 0:
                catHit = true;
              break;
              case 1:
                possumHit = true;
              break;
              case 2:
                deerHit = true;
              break;
              case 3:
                slugHit = true;
              break;
              case 4:
                pengHit = true;
              break;
              case 5:
                armadHit = true;
              break;
              case 6:
                chickenHit = true;
              break;
              case 7:
                giraffeHit = true;
              break;
              case 8:
                dolphinHit = true;
              break;
              case 9:
                whaleHit = true;
              break;
            }
            c1.incrEScore(a[animalNum].weight);
            cout << endl;
          }
          r1.place_obj(1, r1.getWidth(), Animal::m_Symbol);
          km++;
        }
      }
    //~~~~~~~Terminatiion~~~~~~~~~
    }while ((c1.getBattery() > 0) && (km <= 100) && (c1.getDamage () < 100));
    cout << endl;
    //~~~~~~~~The ending message~~~~~~~~
    cout << "Simulation terminated with: " << endl;
    cout << " - Remaining car battery life: " << c1.getBattery() << "%";
    if (c1.getBattery() <= 0)
    {
      cout << "  (reason for simulation termination) ";
    }
    cout << endl;
    cout << " - Car damage: " << c1.getDamage() << "%";
    if (c1.getDamage() >= 100)
    {
      cout << "  (reason for simulation termination) ";
    }   
    cout << endl;
    cout << " - Car's e-score: " << c1.getEScore() << endl;
    cout << " - Distance traveled: " << km-1 << " km";
    if (km >= 100)
    {
      cout << "  (reason for simulation termination) ";
    }
    cout << endl;
    cout << " - Animals hit: " << endl;
    if (catHit)
    {
      cout << a[0].animalName << ", " << a[0].weight << " kg, occupies "
           << a[0].width << " road sector(s), stupidity " << a[0].stupidity
           << endl;
    }  
    if (possumHit)
    {
      cout << a[1].animalName << ", " << a[1].weight << " kg, occupies "
           << a[1].width << " road sector(s), stupidity " << a[1].stupidity
           << endl;
    }
    if (deerHit)
    { 
      cout << a[2].animalName << ", " << a[2].weight << " kg, occupies "
           << a[2].width << " road sector(s), stupidity " << a[2].stupidity
           << endl;
    }
    if (slugHit)
    {
      cout << a[3].animalName << ", " << a[3].weight << " kg, occupies "
           << a[3].width << " road sector(s), stupidity " << a[3].stupidity
           << endl;
    }
    if (pengHit)
    {
      cout << a[4].animalName << ", " << a[4].weight << " kg, occupies "
           << a[4].width << " road sector(s), stupidity " << a[4].stupidity
           << endl;
    }                                                           
    if (armadHit)
    {
      cout << a[5].animalName << ", " << a[5].weight << " kg, occupies "
           << a[5].width << " road sector(s), stupidity " << a[5].stupidity
           << endl;
    }
    if (chickenHit)
    {
      cout << a[6].animalName << ", " << a[6].weight << " kg, occupies "
           << a[6].width << " road sector(s), stupidity " << a[6].stupidity
           << endl;
    }
    if (giraffeHit)
    {
      cout << a[7].animalName << ", " << a[7].weight << " kg, occupies "
           << a[7].width << " road sector(s), stupidity " << a[7].stupidity
           << endl;
    }
    if (dolphinHit)
    {
      cout << a[8].animalName << ", " << a[8].weight << " kg, occupies "
           << a[8].width << " road sector(s), stupidity " << a[8].stupidity
           << endl;
    }                            
    if (whaleHit)
    {
      cout << a[9].animalName << ", " << a[9].weight << " kg, occupies "
           << a[9].width << " road sector(s), stupidity " << a[9].stupidity
           << endl;
    }
  }
    return 0;
}
