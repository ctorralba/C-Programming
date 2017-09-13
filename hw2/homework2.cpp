//Programmer: Christopher Torralba	Date: 9/9/15
//
//File: homework2.cpp
//
//Purpose: This file contains the function for the program that will
//	   compute a 4-letter password using several information from 
//	   the user.

#include <iostream>
using namespace std;

int main()
{
  //Variables
  short age,
        brainweight,
        firstPassNum,
        secondPassNum,
        thirdPassNum,
        fourthPassNum;
  int   homerConstants;
  bool  regularGlueEater = false;
  char  firstPassLetter,
        secondPassLetter,
        thirdPassLetter,
        fourthPassLetter;
 
  //Welcome message
  cout << "Hello and welcome to the password generator!\n";
  
  //User prompts
  cout << "Enter your age: ";
  cin >> age;
  
  cout << "Enter your brain's weight (lbs): ";
  cin >> brainweight;
  
  cout << "Are you a regular glue eater? (0=No, 1=Yes) ";
  cin >> regularGlueEater;
  
  //Confirming input
  cout << endl
       << "This is what we have:" << endl
       << "  Age = " << age << endl
       << "  Brain's Weight = " << brainweight << endl
       << "  Glue Eater? = " << regularGlueEater << endl;
  
  //Calculations
  homerConstants = 26 * 65  * 32;
  firstPassNum = (static_cast<short>((static_cast<float>(brainweight)
                        /age) * homerConstants) % 26) + 65 + 
                        (regularGlueEater * 32);
  secondPassNum = (static_cast<short>((static_cast<float>
                        (brainweight)/age) * (homerConstants+100)) % 26) + 65 +
                        (regularGlueEater * 32);
  thirdPassNum = (static_cast<short>((static_cast<float>
                        (brainweight)/age) * (homerConstants+200)) % 26) + 65 +
                        (regularGlueEater * 32);
  fourthPassNum = (static_cast<short>((static_cast<float>
                        (brainweight)/age) * (homerConstants+300)) % 26) + 65 +
                        (regularGlueEater * 32);

  //number to letter converter
  firstPassLetter = firstPassNum;
  secondPassLetter = secondPassNum;
  thirdPassLetter = thirdPassNum;
  fourthPassLetter = fourthPassNum;

  //Output
  cout << "Your password is " << firstPassLetter <<secondPassLetter
       << thirdPassLetter << fourthPassLetter << endl;
  cout << "Goodbye!" << endl;
  
return 0;
}
