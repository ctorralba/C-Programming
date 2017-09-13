/*Programmer: Christopher Torralba      Date:11/19/2015
Instructor: Leopold
Section: J
Purpose:  This file contains the prototypes and global constants
          of the Car class.
*/

#include <iostream>
#include "road.h"
#ifndef CAR_H
#define CAR_H
using namespace std;

const short STARTWIDTH = 4;     //starting width for car
const short STARTDAMAGE = 0;    //starting damage for car
const short BATTERYRANGE = 26;  //range values for % rand gen
const short BATTERYSTART = 50;  //starting values for rand gen
const char STARTSYMBOL = 'c';   //starting symbol for char
const short HALFOBSWEIGHT = 2;  //half the obstacle weight (kg)
const short TENTHOBSWEIGHT = 10;//tenth of the obstacle weight (kg)
const short OVER100 = 100;   //used to check if values are over 100.
const short OBSWEIGHTCHECK = 0; // used to check if obs is pos.
const short BATTCHECK = 0;  //used to check if battery is below 0.
const short BATTERYTIME = 1; //used to lower the battery by 1.
const short STARTESCORE = 0; //used to initialize eScore
const short LOWESTDAMAGE = 0; //used to calculate damage for mutator function.
const short FULLDAMAGE = 100; //used to calculate damage from obs.
const short DAMAGERATE = 100; //used to divide damage

class Car
{
  private:
    int   m_width, //# of sectors a car occupies
          m_carLeftPos, //the position of the car
          m_eScore; //the weight of all animals hit
    float m_damage,  //accumulated percentage of how damaged the car is.
          m_battery;  //% of battery power remaining
    char  m_symbol;  //symbol used to represent the car
    
  public:
    /* Default constructor for Fraction
       Pre: None
       Post: width set to 4, damage set to 0, battery set to some random #
       between 90 & 100, symbol is set to c. Sets position in sector to 1.
    */ 
    Car();
     
    /* Accessor for width of the car.
       Pre: None
       Post: Value of width is returned
    */
    int getWidth() const { return m_width; } 
    
    /* Accessor for damage to the car.
       Pre: None.
       Post: Value of damage is returned.
    */
    float getDamage() const { return m_damage; }
    
    /* Accessor for the car's remaining battery power.
       Pre: None.
       Post: Value of battery is returned.
    */
    float getBattery() const { return m_battery; }

    /* Accessor for the car's position in the sector.
       Pre: None.
       Post: Car's left position is returned.
    */
    int getCarPos() const { return m_carLeftPos; }
                              
    /* Takes a value representing road obstacle and increases damage
       by 1/10 of it's weight. damage is to not exceed 100.
       Pre: None.
       Post: Damage is increased by a 1/10 of the obstacle's value.
    */
    void incrBattery(int obstacleWeight);
    
    /* Takes a value representing road obstacle and increases damage
         by 1/10 of it's weight. damage is to not exceed 100.
       Pre: None.
       Post: Damage is increased by a 1/10 of the obstacle's value.
    */
    void incrDamage(int obstacleWeight);
      
    /* Establishes a car on the road based on the width of the car.
       The car character, and the the starting left pos of the car.
       Pre: place car()
       Post: a passing has been placed across the scene.
    */     
    void enter_a_road(Road& r, const int mostLeftPos);
    
    /* Displays the state of the car
       Pre: None
       Post: Car's member variable values will
             be output to outs, modifying ostream outs.
    */
    friend ostream& operator <<(ostream&outs, const Car& c);
    
    /* Adds 1 to the battery
       Pre: None
       Post: m_battery is added 1, but can not be over 100.
    */
    void batteryOverTime();
    
    /* Mutator function for car damage.
       Pre: none.
       Post: Sets m_damage = damage. If damage is below 0 or greater than
       100. It is set to 0 and 100 respectively.
    */
    void setDamage(const int damage);
    
    /* Mutator function for eScore.
       Pre: None
       Post: Adds weight to m_eScore.
    */
    void incrEScore(const int weight);
    
    /* Accessor function for eScore
       Pre: None
       Post: returns m_eScore
    */
    int getEScore() const { return m_eScore; }

};
#endif
    
