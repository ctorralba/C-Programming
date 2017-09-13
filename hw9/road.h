/*Programmer: Christopher Torralba	Date:11/9/2015
Instructor: Leopold
Section: J
Purpose: This file contains the prototypes and global constants
         of the Road class.
*/

#ifndef ROAD_H
#define ROAD_H

#include <iostream>
using namespace std;

const short MAX_WIDTH = 15;     //the max # of sectors
const short STARTSECTORWIDTH = 10;    //the starting # of sectors
const short NEGCHECK = 0;       //to check if values are positive
const short POSITIONCHECK = 1;  //starting position for a sector
const short POSITIONOFFSET = 1; //since the first sector is 1. not 0.
const short STARTSECTOR = 0;    //used to display sector array from pos 0.
class Road
{
  private:
    int m_width;		//the # of road sections
    char m_sectors[MAX_WIDTH];	//the sectors and their labels
  public:
    /* Default constructor for Road
       Pre: None
       Post: Initializes sectors to be empty. Sets the width to 10.
    */
    Road();

    /* Accessor for the width of the road.
       Pre: None
       Post: Value of the width of road is returned  
    */
    int getWidth() const {return m_width;}
    
    /* Adds a car to the road
       Pre: None
       Post: An appropiate sector is "marked" indicating a car is occupying
       space
    */
    void place_car(const int widthCar, const int leftPosCar,
                   const char carChar);
    
    /* Displays the state of the road
       Pre: None
       Post: Road's member variable values will
       be output to outs, modifying ostream outs.
    */
    friend ostream& operator<<(ostream&outs, const Road& r);
};
#endif
