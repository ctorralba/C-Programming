//Programmer: Christopher Torralba
//Section: F
//Date: 9/9/2015
//Description: Calculate Body Mass Index (BMI) with the use of mass and height

#include <iostream>
using namespace std;
int main()
{
  int   mass,    //declaring variables
        height;
  float bodyMassIndex;
  const float CONVERTION_FACTOR = 703;
  
  cout << "Welcome to the BMI Calculator \n" <<endl; //Introduction
  cout << "Enter your weight(in pounds): " <<endl; //Input weight
  cin >> mass;
  cout << "Enter the height (in inches): " <<endl; //Input height
  cin >> height;
  
//Calculations
  bodyMassIndex = static_cast<float>((mass*CONVERTION_FACTOR)/(height*height));
//Output
  cout << "The BMI value for " << height << " inches and " << mass 
       << " pounds is " << bodyMassIndex;
  return 0;
}
