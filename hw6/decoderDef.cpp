/*
Programmer: Christopher Torralba		Date: 10/10/15
Section: J
File Name: decoderDef.cpp
Purpose: Contains the function definitions for the optimizedDecoder.cpp
*/

#include<iostream>
#include "header.h"
using namespace std;

void greeting()
{
  cout << "Welcome to the decoder" << endl;
  cout << "...Decrypting your message..." << endl;
  return;
}

short diskNumCheck(short rotor)
{
  do
  {//Loops if its not greater than 1 and less than 5
    if (!((rotor >= LEAST_NUM_DISK) && (rotor <= GREAT_NUM_DISK)))
    {
      cout << "Invalid Number... ";
      cout << "Please put a number between 1 and 5: " << endl;
      cin >> rotor;
    }
  }while (!((rotor >= LEAST_NUM_DISK) && (rotor <= GREAT_NUM_DISK)));
  return (rotor);
}

short diskInputLeft()
{
  short first_rotor;
  cout << "Please input your first rotor number (1,2,3,4,5):" << endl;
  cin >> first_rotor;
  first_rotor = diskNumCheck(first_rotor);
  return (first_rotor);
}

short diskInputMid(short first_rotor)
{  
  short second_rotor;
  cout << "Please input your second rotor number:" << endl;
  cin >> second_rotor;
  while (second_rotor == first_rotor)
  {//loops if the first rotor is = to the second rotor
    cout << "Please use another number than your first rotor number:  ";
    cin >> second_rotor;
    second_rotor = diskNumCheck(second_rotor);
  }
  return (second_rotor);
}

short diskInputRight(short first_rotor, short second_rotor)
{  
  short third_rotor;
  cout << "Please input your third rotor number:" << endl;
  cin >> third_rotor;
  while ((third_rotor == first_rotor) || (third_rotor == second_rotor))
  {// loops if third rotor is = either first or second rotor
    cout << "Please use another number:  ";
    cin >> third_rotor;
    third_rotor = diskNumCheck(third_rotor);
  }
  return (third_rotor);
}

char charCheck()
{
  char charInput;
  do
  {//loops if not a char between 'A'-'Z' or '_' or '.'
    cout << "Enter a character from 'A-Z', '_' , or a '.':  ";
    cin >> charInput;
    if ((!((charInput >= 'A') && (charInput <= 'Z'))) && (charInput != '_')
     && (charInput != '.'))
    cout << "Invalid character...";
  }while ((!((charInput >='A') && (charInput <= 'Z'))) && (charInput != '_')
           && (charInput != '.'));
  return(charInput);
}

char rotor_Input (const short rotor, const char charInput)
{
  char charOutput;
  switch (rotor)
  {//function sorter based on order
    case 1:
    charOutput = disc_1(charInput);
    break;
    case 2:
    charOutput = disc_2(charInput);
    break;
    case 3:
    charOutput = disc_3(charInput);
    break;
    case 4:
    charOutput = disc_4(charInput);
    break;
    case 5:
    charOutput = disc_5(charInput);
    break;
  }
  return(charOutput);
}
char charShift(const char inputChar, char prevInput)
{
  char outputChar;
  outputChar = (inputChar + (prevInput - NOT_ASCII));
  if (outputChar > 'Z')
  {
  	outputChar -= CYCLE_BACK_NUM;
  }
  return(outputChar);
}

char disc_1(const char input)
{
  static char prevInput = 65;
  char output_rotor_1;
  char shiftedChar;
  
  shiftedChar = charShift (input, prevInput);
  output_rotor_1 =  ((shiftedChar + D1_ADD) % D12_MOD) + D12_FINAL_ADD;
  prevInput = input;
  return (output_rotor_1);
}

char disc_2(const char input)
{
  static char prevInput = 65;
  char output_rotor_2;
  char shiftedChar;
  
  shiftedChar = charShift (input, prevInput);
  output_rotor_2 = (((shiftedChar) + D2_ADD) % D12_MOD) + D12_FINAL_ADD;
  prevInput = input;
  return (output_rotor_2);
}

char disc_3(const char input)
{
  static char prevInput = 65;
  char output_rotor_3;
  char shiftedChar;
  
  shiftedChar = charShift(input, prevInput);
  switch (shiftedChar)
  {
    case 'A':
    output_rotor_3 = 'H';
    break;
    case 'B':
    output_rotor_3 = 'U';
    break;
    case 'C':
    output_rotor_3 = 'I';
    break;
    case 'D':
    output_rotor_3 = 'P';
    break;
    case 'E':
    output_rotor_3 = 'N';
    break;
    case 'F':
    output_rotor_3 = 'W';
    break;
    case 'G':
    output_rotor_3 = 'C';
    break;
    case 'H':
    output_rotor_3 = 'K';
    break;
    case 'I':
    output_rotor_3 = 'E';
    break;
    case 'J':
    output_rotor_3 = 'X';
    break;
    case 'K':
    output_rotor_3 = 'Q';
    break;
    case 'L':
    output_rotor_3 = 'Z';
    break;
    case 'M':
    output_rotor_3 = 'O';
    break;
    case 'N':
    output_rotor_3 = 'V';
    break;
    case 'O':
    output_rotor_3 = 'S';
    break;
    case 'P':
    output_rotor_3 = 'B';
    break;
    case 'Q':
    output_rotor_3 = 'L';
    break;
    case 'R':
    output_rotor_3 = 'J';
    break;
    case 'S':
    output_rotor_3 = 'D';
    break;
    case 'T':
    output_rotor_3 = 'Y';
    break;
    case 'U':
    output_rotor_3 = 'F';
    break;
    case 'V':
    output_rotor_3 = 'R';
    break;
    case 'W':
    output_rotor_3 = 'A';
    break;
    case 'X':
    output_rotor_3 = 'G';
    break;
    case 'Y':
    output_rotor_3 = 'T';
    break;
    case 'Z':
    output_rotor_3 = 'M';
    break;
  }
  prevInput = input;
  return (output_rotor_3);
}

char disc_4(const char input)
{
  static char prevInput = 65;
  char output_rotor_4;
  char shiftedChar;
  
  shiftedChar = charShift(input, prevInput);
  //if ascii value is even subtract 1 to ascii
  //if ascii value is odd add 1 to ascii
  output_rotor_4 = ((shiftedChar % D45_EVENCHECK == D4_ISEVEN)?
                   (shiftedChar - D45_MODIFIER):
        	   (shiftedChar + D45_MODIFIER));
  prevInput = input;
  return (output_rotor_4);
}

char disc_5(const char input)
{
  static char prevInput = 65;
  char output_rotor_5;
  char shiftedChar;
  
  shiftedChar = charShift(input, prevInput);
  if ((shiftedChar) % D5_MULTIPLE3 == 0)
  {//if multiple of 3 checks to see if its Z then either converts it to B
    // or add 3
    output_rotor_5 = ((shiftedChar == 'Z')? 'B':(shiftedChar + D5_MULTIPLE3));
  }
  else if (shiftedChar == 'A')
  {//if its 'A' set it to 'A'
    output_rotor_5 = shiftedChar;
  }
  else
  {//if modding by 3 gets you a 2 then subtract 1 from character
    //otherwise add 3
    output_rotor_5 = (((shiftedChar % D5_MULTIPLE3) == D45_EVENCHECK)?
		 (shiftedChar - D45_MODIFIER) : (shiftedChar + D45_MODIFIER));
  }
  prevInput = input;
  return (output_rotor_5);
}

void signoff()
{
	cout << "Reached end of message... Terminating..." << endl;
	return;
}
