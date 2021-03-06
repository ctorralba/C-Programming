/*Programmer: Christopher Torralba      Date:11/19/2015
Instructor: Leopold
Section: J
Purpose: The implementation file for the animal class.
*/

#include "animal.h"
#include "road.h"
#include <iostream>
using namespace std;
 
ostream& operator<< (ostream&outs, const Animal& a)
{
  outs << a.m_species << " species. " << a.m_weight << " kg. "
       << a.m_width << " wide. " << a.m_stupidity << "% stupid. ";
  return (outs);
}

