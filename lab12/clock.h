/* Programmer: Christopher Torralba     Date: 11/11/15
Section: F
File Name: lab12
Purpose: Holds the prototypes and variables for class Clock.
*/

#ifndef CLOCK_H
#define CLOCK_H

#include <iostream>
using namespace std;

class Clock
{
  public:
    //Default constructor for clock.
    //Pre: None
    //Post: Hour is set to 0. Minute is set to 0. Second is set to 0.
    //      meridian is set to AM.
    Clock(): hour(0), minute(0), second(0), meridian("AM"){}
    
    //Second constructor for clock.
    //Pre: None
    //Post: Hour is set to 0. Minute is set to 0. Second is set to 0.
    //      meridian is set to AM.
    Clock(const int h, const int m, const int s, const string mer);
    
    //Displays the time of the clock.
    //Pre: None
    //Post: The clock time is displayed.
    void setclock();
                       
    //Displays the standard time 
    //Pre: None
    //Post: Displays the time for hours, minutes, second, and meridian.
    void displayStandard() const;
    
    //Displays the time to military
    //Pre: None
    //Post: The hour is set to +12 hours if meridian is "PM", otherwise it
    //      stays the same.
    void displayMilitary();
  private:
    int hour, minute, second;
    string meridian;

};
#endif
