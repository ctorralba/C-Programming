/* Programmer: Christopher Torralba     Date: 11/11/15
Section: F
File Name: lab12
Purpose: Holds the function implementation for clock.
*/

#include "clock.h"
#include <iostream>
using namespace std;

Clock::Clock (const int h, const int m, const int s, const string mer)
{
  hour = h;
  minute = m;
  second = s;
  meridian = mer;
}

void Clock::setclock()
{
  cout << "Enter hours: " << endl;
  cin >> hour;
  cout << "Enter minutes: " << endl;
  cin >> minute;
  cout << "Enter seconds: " << endl;
  cin >> second;
  cout << "Enter meridian: " << endl;
  cin >> meridian;
  return;
}

void Clock::displayStandard()const
{
  cout << hour << ":" << minute << ":" << second << " " << meridian;
  return;
}

void Clock::displayMilitary()
{
 if (meridian == "PM")
 {
   hour = hour + 12; //adds 12 if PM
 }
 cout << hour << ":" << minute << ":" << second;
 return;
}