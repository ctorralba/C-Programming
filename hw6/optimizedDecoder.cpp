//Programmer: Christopher Torralba      Date 9/24/15
//Section: J
//Instructor: Leopold
//File Name: decoder.cpp
//Purpose: To decode an encrypted message that is 
          //optimized using functions

#include <iostream>
#include "header.h"
using namespace std;

int main ()
{
  short left;		//the input for what disk the left rotor is using
  short middle;		//the input for what disk the middle rotor is using
  short right;		//the input for what disk the right rotor is using
  short validChar;	//the character after being validated by the check
			//function.
  char leftRotorOut;	//the output character from the left rotor
  char middleRotorOut;	//the output character from the middle rotor
  char finalOutput;	//the output character from the right rotor
  //welcome message
  greeting();
  //disk input for each rotor
  left = diskInputLeft();
  middle = diskInputMid(left);
  right = diskInputRight(left, middle);
  do
  {//character validation
    validChar = charCheck();
    switch (validChar)
    {
      case '_':
      finalOutput = '_';
      break;
      case '.':
      finalOutput = '.';
      break;
      default://character encryption char shift occurs in each rotor
              //before decoding
      leftRotorOut = rotor_Input(left, validChar);
      middleRotorOut = rotor_Input(middle, leftRotorOut);
      finalOutput = rotor_Input(right, middleRotorOut);
    }
    cout << finalOutput << endl;
  }while (validChar != '.');
return 0;
}
