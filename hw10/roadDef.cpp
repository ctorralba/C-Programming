/*Programmer: Christopher Torralba      Date:11/19/2015
Instructor: Leopold
Section: J
Purpose: The implementation file for the road class.
*/

#include "road.h"
#include <iostream>
#include <string.h>
using namespace std;

Road::Road()
{
  m_width = STARTSECTORWIDTH;
  for (int i = 0; i < MAX_WIDTH; i++)
  {
    m_sectors[i].car = EMPTY;
  }
}

void Road :: place_obj(const int width, const int leftPos, //0 being start
                       const char charObj)
{
  int endPos;
  if ((width < 0) || (width >= MAX_WIDTH))
  {
    endPos = 0;
  }
  else endPos = leftPos + width - 1;
  
  for (short i = 0; i <  MAX_WIDTH; i++)
  {
    if ((i >= leftPos) && (i <= endPos))
    {
      if (charObj == 'c')
      {
        m_sectors[i].car = charObj;
      }
      if (charObj == 'a')
      {
        m_sectors[i].animal = charObj;
      }
      if (charObj == 'P')
      {
        m_sectors[i].person = charObj;
      }
    }
    else
    {
      if (charObj == 'c')
      {
      m_sectors[i].car = EMPTY;
      }
      if (charObj == 'a')
      {
        m_sectors[i].animal = EMPTY;
      }
      if (charObj == 'P')
      {
        m_sectors[i].person = EMPTY;
      }
    }
  }  
}

ostream& operator<< (ostream&outs, const Road& r)
{
  //used to display the sectors with the dividers
  outs << "|";
  for (short i = STARTSECTOR; i < r.m_width; i++)
  {
    if (!((r.m_sectors[i].person == 'P') || (r.m_sectors[i].animal == 'a')))
    {
      outs << r.m_sectors[i].car << "|";
    }
    else
    {
      if (r.m_sectors[i].animal == 'a')
      {
        outs << r.m_sectors[i].animal << "|";
      }
      if (r.m_sectors[i].person == 'P')
      {
        outs << r.m_sectors[i].person << "|";
      }
    }
  }
  return (outs);
}
