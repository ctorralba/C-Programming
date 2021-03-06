/* Programmer: Christopher Torralba	Date: 11/11/15
Section: F
File Name: lab12
Purpose: Make a clock that displays both standard and military time
using classes.
*/
#include "clock.h"
#include <iostream>
using namespace std;

int main()
{
  Clock c1;
  Clock c2(4, 30, 0, "PM");
  c1.displayStandard();
  cout << endl;
  c1.displayMilitary();
  cout << endl;
  c2.displayStandard();
  cout << endl;
  c2.displayMilitary();
  cout << endl;
return 0;
}

