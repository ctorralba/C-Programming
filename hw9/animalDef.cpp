/*Programmer: Christopher Torralba      Date:11/9/2015
Instructor: Leopold
Section: J
Purpose: Holds the definitions for the class for animal.
*/

#include "animal.h"
#include <iostream>
using namespace std;
 
Animal::Animal(const string species, int weight,
        int width, int stupidity)
{
  m_species = species;
  //check for proper weight
  do
  {
    if (weight <= POSCHECK)
    {
      cout << "Input a proper weight for animal (positive values)" << endl;
      cin >> weight;
    }
  }while (weight <= POSCHECK);
  m_weight = weight;
  
  //check for proper width
  do
  {
    if (width <= POSCHECK)
    {
      cout << "Input a proper width for animal (positive values)" << endl;
      cin >> width;
    }
  }while (width <= POSCHECK);
  m_width = width;
  //check for stupidity
  
  do
  {
    if (!((stupidity >= POSCHECK) && (stupidity <= OVERSTUPID)))
    {
      cout << "Input a proper stupidity value for animal (0-100)" << endl;
      cin >> stupidity;
    }
  }while (!((stupidity >= POSCHECK) && (stupidity <= OVERSTUPID)));
  m_stupidity = stupidity;
}
 
bool Animal::choose_to_run(const int runStupidity)
{
  bool runs;
  //if stupidity is greater than parameter than animal runs (returns true)
  if (m_stupidity > runStupidity)
  {
    runs = true;
  }
  else
  {
    runs = false;
  }
  return (runs);
}

ostream& operator<< (ostream&outs, const Animal& a)
{
  outs << a.m_species << " species. " << a.m_weight << " kg. "
       << a.m_width << " wide. " << a.m_stupidity << "% stupid. ";
  return (outs);
}
