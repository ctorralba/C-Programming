/*Programmer: Christopher Torralba	Date: 11/20/15
Section: J
Instructor: Leopold
Purpose: Hold the implementation file for the pedestrian class.
*/

#include "pedestrian.h"
#include "road.h"
#include "car.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Pedestrian::Pedestrian()
{
  short randNameNum;
  
  m_symbol = 'P';
  m_BAC = (static_cast<float>((rand() % 21))/100);
  randNameNum = rand() % 25;
  m_pName = PED_NAMES[randNameNum];
  return;  
}

void Pedestrian::walk(Road& r, Car& c)
{
  Pedestrian p1;
  short walkCounter = 0;
  short position = 0;
  short drunkMove;
  do
  {
    if (m_BAC < NOTDRUNK)
    {
      r.place_obj(PEDSTART, position + walkCounter, m_symbol);
      for (short i = 0; i <= r.getWidth(); i++)
      {
        if ((r.getSectorCar(i) == 'c') && (r.getSectorPerson(i) == 'P'))
        {
          c.setDamage(c.getDamage()-FIXORDAMAGE);
        }
      }
      cout << r << endl;
      walkCounter++;
    }  
    else
    {
      r.place_obj(PEDSTART, position + walkCounter, m_symbol);
      for (short i = 0; i <= r.getWidth(); i++)
      {
        if ((r.getSectorCar(i) == 'c') && (r.getSectorPerson(i) == 'P'))
        {
          c.setDamage(c.getDamage()+FIXORDAMAGE);
        }
      }
      drunkMove = rand() % MOVERATE;
      if (drunkMove == BACKWARDMOVE)
      {
        walkCounter--;
        if ((position + walkCounter) < BACKWARDMOVE)
        {
          walkCounter = BACKWARDMOVE;
        }
      }
      else
      {
        walkCounter ++;
      }
      cout << r << endl;               
    }
  }while ((position + walkCounter) != r.getWidth());
  r.place_obj(PEDSTART, r.getWidth(), m_symbol);
  cout << endl;
  return;
}
