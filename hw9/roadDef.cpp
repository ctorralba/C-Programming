/*Programmer: Christopher Torralba      Date:11/9/2015
Instructor: Leopold
Section: J
Purpose: Holds the definitions for the class for road.
*/
#include "road.h"
#include <iostream>
#include <string.h>
using namespace std;

Road::Road()
{
  m_width = STARTSECTORWIDTH;
  strcpy(m_sectors,"             ");
}

void Road :: place_car(int widthCar, int leftPosCar,
                       const char carChar)
{
  //check for proper car width
  do
  {
    if (widthCar <= NEGCHECK)
    {
      cout << "Input a proper width for the car (positive values)" << endl;
      cin >> widthCar;
    }
  }while (widthCar <= NEGCHECK);
  //check for proper car position
  do
  {
    if (!((leftPosCar >= POSITIONCHECK) && (leftPosCar <= MAX_WIDTH)))
    {
      cout << "Input a proper position for the car:" << endl;
      cin >> leftPosCar;
    }
  }while(!((leftPosCar >= POSITIONCHECK) && (leftPosCar <= MAX_WIDTH)));
  for (short i = leftPosCar-1; i < (leftPosCar-1 + widthCar); i++)
  {
    m_sectors[i] = carChar;
  }  
}

ostream& operator<< (ostream&outs, const Road& r)
{
  //used to display the sectors with the dividers
  outs << "|";
  for (short i = STARTSECTOR; i < r.m_width; i++)
  {
    outs << r.m_sectors[i] << "|";
  }
  return (outs);
}
