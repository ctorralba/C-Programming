/*Programmer: Christopher Torralba	Date:11/19/2015
Instructor: Leopold
Section: J
Purpose: This file contains the prototypes and global constants
         of the Road class.
*/

#ifndef ROAD_H
#define ROAD_H

#include <iostream>
using namespace std;

static const short MAX_WIDTH = 15;     //the max # of sectors
static const short STARTSECTORWIDTH = 10;    //the starting # of sectors
const short NEGCHECK = 0;       //to check if values are positive
const short POSITIONCHECK = 1;  //starting position for a sector
const short POSITIONOFFSET = 1; //since the first sector is 1. not 0.
const short STARTSECTOR = 0;    //used to display sector array from pos 0.

struct sectorInfo
{
  char car,
       animal,
       person;
};

class Road
{
  private:
    static const char EMPTY = ' '; //unoccupied sector.
    int m_width;		//the # of road sections
    sectorInfo m_sectors[MAX_WIDTH];	//the sectors and their labels
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
    
    /* Accessor for the sectors containing cars.
       Pre: m_sectors has to be filled with char or ' '.
       Post: char value of the sectorNum of array m_sectors is returned.
    */
    char getSectorCar(const short sectorNum) 
                      const {return (m_sectors[sectorNum].car);}
     
    /* Accessor for the sectors containing animals.
       Pre: m_sectors has to be filled with char or ' '.
       Post: char value of the sectorNum of array m_sectors is returned.
    */
    char getSectorAnimal(const short sectorNum) 
                         const {return (m_sectors[sectorNum].animal);}
    
    /* Accessor for the sectors containing pedestrian.
       Pre: m_sectors has to be filled with char or ' '.
       Post: char value of the sectorNum of array m_sectors is returned.
    */
    char getSectorPerson(const short sectorNum)
                         const {return (m_sectors[sectorNum].person);}      
    
    /* Adds a car to the road
       Pre: None
       Post: An appropiate sector is "marked" indicating a car is occupying
       space
    */
    void place_obj(const int width, const int leftPos,
                   const char charObj);
    
    /* Displays the state of the road
       Pre: None
       Post: Road's member variable values will
       be output to outs, modifying ostream outs.
    */
    friend ostream& operator<<(ostream&outs, const Road& r);
};
#endif
