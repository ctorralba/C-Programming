/*
Programmer: Christopher Torralba      Date: 11/9/2015
Instructor: Leopold
Section: J
Purpose: Main file demonstrating the uses of the animal, car, and road classes
*/

#include <iostream>
#include "road.h"
#include "animal.h"
#include "car.h"
using namespace std;

int main ()
{
  Road r1;
  Animal a1;
  Animal a2("Bee", 5, 5, 75);
  Car c1;
  short aWidth, aWeight, cWidth, cDamage, rWidth;
  
  bool runs;
//Animal Testing
  cout << "Animal Class:" << endl;
  //Constructor and paramter check
  cout << "Default: ";
  cout << a1 << endl;
  cout << "Parameter: ";
  cout << a2 << endl;
  //Accessor check
  aWidth = a1.getWidth();
  cout << aWidth << " = width accessor function check." << endl;
  aWeight = a1.getWeight();
  cout << aWeight << " = weight accessor function check." << endl;
  //choose_to_run check
  runs = a1.choose_to_run(90);
  cout << runs << " = bool value deciding to run for default" << endl;
  runs = a2.choose_to_run(90);
  cout << runs << " = bool value deciding to run for parameter" << endl;

//Car Testing
  cout << endl;
  cout << "Car Class: " << endl;
//constructor check
  cout << "Default: " << endl;
  cout << c1 << endl;
//accessor check
  cWidth = c1.getWidth();
  cout << cWidth << " = width accessor function check." << endl;
  cDamage = c1.getDamage();
  cout << cDamage << " = damage accessor function check." << endl;
//battery check
  cout << "Battery Check:" << endl;
  c1.incrBattery(10);
  cout << c1 << endl;
  c1.incrBattery(10);
  cout << c1 << endl;
  c1.incrBattery(10);
  cout << c1 << endl;
//damage check
  cout << "Damage Check:" << endl;
  c1.incrDamage (200);
  cout << c1 << endl;
  c1.incrDamage (1000);
  cout << c1 << endl;
  c1.incrDamage (1000);
  cout << c1 << endl;
//enter a road check at the bottom
  
//Road Testing
  cout << endl;
  cout << "Road Class: " << endl;
//Constructor Check
  cout << "Default: " << endl;
  cout << r1 << endl;
//Accessor Check  
  rWidth = r1.getWidth();
  cout << rWidth << " = accessor for the width of road." << endl;
//Place Car check
  r1.place_car(2, 2, 'a');
  cout << "Place Car Check: " << endl;
  cout << r1 << endl;
//road check
  cout << endl;
  cout << "Enter a road check: (From car class)" << endl;
  c1.enter_a_road(r1);
  cout << r1 << endl;

  return 0;
}
