/*
Programmer: Christopher Torralba      Date: 11/9/2015
Instructor: Leopold
Section: J
Purpose: Definition file for the driver file.
*/

#include <iostream>
#include "driver.h"
#include "road.h"
using namespace std;

bool isHit(const Road& r)
{
  bool sameSpace = false;
  for (short i = 0; i < r.getWidth(); i++)
  {
    if ((r.getSectorCar(i) == 'c') && (r.getSectorAnimal(i) == 'a'))
    {
      sameSpace = true;
    }
  }
  return (sameSpace);
}
