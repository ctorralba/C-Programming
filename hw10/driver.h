/*Programmer: Christopher Torralba      Date:11/19/2015
Instructor: Leopold
Section: J
Purpose: This file contains the prototypes, and structs
         of the driver file.
*/
         
#ifndef DRIVER_H
#define DRIVER_H

#include <iostream>
#include "animal.h"
#include "road.h"
using namespace std;

struct animal
{
  string animalName;
  short width;
  int weight;
  short stupidity;
};

/* Used to determine whether an animal has been hit.
   Pre: m_sectors.animal and m_sectors.car has been filled with
        'a' or 'c' respectively otherwise be filled with ' '
        from 0...10.
   Post: returns true if a and c are occupying the same space.
*/
bool isHit(const Road& r);
#endif
