//Programmer: Christopher Torralba      Date 9/24/15
//Section: J
//Instructor: Leopold
//File Name: decoder.cpp
//Purpose: To decode an encrypted message

#include <iostream>
using namespace std;

int main ()
{
  const short ROTO1_ADD = 3;     //The inital addition for Rotor 1
  const short ROTO2_ADD = 17;	 //The initial addition for Rotor 2
  const short ROTO_MOD = 26;     //The # used for modding
  const short ROTO_ADD = 65;     //The # added after modding
  short first_rotor,	   //"First Rotor"
        second_rotor,     //"Middle Rotor"
        third_rotor;	   //"Last Rotor"
  char  first_change,     //Character after going through the first rotor
        second_change,	   //Character after going through the second rotor
        third_change,     //Character after going through the third rotor
        charInput; 	   //Initial Character input
   
   //Welcome Message
  cout << "Decrypting your message..." << endl;
  //First Rotor Verification
  do
  {
    cout << "Please input your first rotor number (1,2,3):" << endl;
    cin >> first_rotor;
    if (!((first_rotor >= 1) && (first_rotor <= 3)))
    {
      cout << "Invalid Number... ";
    }
  }while (!((first_rotor >= 1) && (first_rotor <= 3)));
  //Second Rotor Verification for right numbers
  do
  {
    cout << "Please input your second rotor number:" << endl;
    cin >> second_rotor;
    while (second_rotor == first_rotor)
    {
      cout << "Please use another number than your first rotor number:  ";
      cin >> second_rotor;
    }
    if (!((second_rotor >= 1) && (second_rotor <= 3)))
    {
      cout << "Invalid Number... ";
    }
  }while (!((second_rotor >= 1) && (second_rotor <= 3)));
  //Third Verification for right numbers
  do
  {
    cout << "Please input your third rotor number:" << endl;
    cin >> third_rotor;
    while ((third_rotor == first_rotor) || (third_rotor == second_rotor))
    {
      cout << "Please use another number that you haven't used yet:  ";
      cin >> third_rotor;
    }
    if (!((third_rotor >= 1) && (third_rotor <= 3)))
    {
      cout << "Invalid Number... ";
    }
  }while (!((third_rotor >= 1) && (third_rotor <= 3)));
  do
  {
    do
    {
    //Validating Correct Characters
      cout << "Enter a character from 'A-Z', '_' , or a '.':  ";
      cin >> charInput;
      if ((!((charInput >=65) && (charInput <= 90))) && (charInput != 46)
         && (charInput != 95))
      cout << "Invalid character...";
    }while ((!((charInput >=65) && (charInput <= 90))) && (charInput != 46)
           && (charInput != 95));
   //Check if underscore or not
    if (charInput == '_')
    {
      third_change = '_';
    }
    else
    {
     //first rotor filter (1,2, or 3) depending on user input
      switch (first_rotor)
      {
        case 1:
        first_change = ((charInput + ROTO1_ADD) % ROTO_MOD) + ROTO_ADD;
        break;
        case 2:
        first_change = ((charInput + ROTO2_ADD) % ROTO_MOD) + ROTO_ADD;
        break;
        case 3:
        switch (charInput)
        {
          case 'A':
          first_change = 'H';
          break;
          case 'B':
          first_change = 'U';
          break;
          case 'C':
          first_change = 'I';
          break;
          case 'D':
          first_change = 'P';
          break;
          case 'E':
          first_change = 'N';
          break;
          case 'F':
          first_change = 'W';
          break;
          case 'G':
          first_change = 'C';
          break;
          case 'H':
          first_change = 'K';
          break;
          case 'I':
          first_change = 'E';
          break;
          case 'J':
          first_change = 'X';
          break;
          case 'K':
          first_change = 'Q';
          break;
          case 'L':
          first_change = 'Z';
          break;
          case 'M':
          first_change = 'O';
          break;
          case 'N':
          first_change = 'V';
          break;
          case 'O':
          first_change = 'S';
          break;
          case 'P':
          first_change = 'B';
          break;
          case 'Q':
          first_change = 'L';
          break;
          case 'R':
          first_change = 'J';
          break;
          case 'S':
          first_change = 'D';
          break;
          case 'T':
          first_change = 'Y';
          break;
          case 'U':
          first_change = 'F';
          break;
          case 'V':
          first_change = 'R';
          break;
          case 'W':
          first_change = 'A';
          break;
          case 'X':
          first_change = 'G';
          break;
          case 'Y':
          first_change = 'T';
          break;
          case 'Z':
          first_change = 'M';
          break;
        }
        break;
      }
      switch (second_rotor)
      {
     //second rotor filter 1,2,3 depending on first input and user
        case 1:
        second_change = ((first_change + ROTO1_ADD) % ROTO_MOD) + ROTO_ADD;
        break;
        case 2:
        second_change = ((first_change + ROTO2_ADD) % ROTO_MOD) + ROTO_ADD;
        break;
        case 3:
        switch (first_change)
        {
          case 'A':
          second_change = 'H';
          break;
          case 'B':
          second_change = 'U';
          break;
          case 'C':
          second_change = 'I';
          break;
          case 'D':
          second_change = 'P';
          break;
          case 'E':
          second_change = 'N';
          break;
          case 'F':
          second_change = 'W';
          break;
          case 'G':
          second_change = 'C';
          break;
          case 'H':
          second_change = 'K';
          break;
          case 'I':
          second_change = 'E';
          break;
          case 'J':
          second_change = 'X';
          break;
          case 'K':
          second_change = 'Q';
          break;
          case 'L':
          second_change = 'Z';
          break;
          case 'M':
          second_change = 'O';
          break;
          case 'N':
          second_change = 'V';
          break;
          case 'O':
          second_change = 'S';
          break;
          case 'P':
          second_change = 'B';
          break;
          case 'Q':
          second_change = 'L';
          break;
          case 'R':
          second_change = 'J';
          break;
          case 'S':
          second_change = 'D';
          break;
          case 'T':
          second_change = 'Y';
          break;
          case 'U':
          second_change = 'F';
          break;
          case 'V':
          second_change = 'R';
          break;
          case 'W':
          second_change = 'A';
          break;
          case 'X':
          second_change = 'G';
          break;
          case 'Y':
          second_change = 'T';
          break;
          case 'Z':
          second_change = 'M';
          break;
        }
        break;
      }
      switch (third_rotor)
      {
       //third rotor filter depending on previous choices and user input
        case 1:
        third_change = ((second_change + ROTO1_ADD) % ROTO_MOD) + ROTO_ADD;
        break;
        case 2:
        third_change = ((second_change + ROTO2_ADD) % ROTO_MOD) + ROTO_ADD;
        break;
        case 3:
        switch (second_change)
        {
          case 'A':
          third_change = 'H';
          break;
          case 'B':
          third_change = 'U';
          break;
          case 'C':
          third_change = 'I';
          break;
          case 'D':
          third_change = 'P';
          break;
          case 'E':
          third_change = 'N';
          break;
          case 'F':
          third_change = 'W';
          break;
          case 'G':
          third_change = 'C';
          break;
          case 'H':
          third_change = 'K';
          break;
          case 'I':
          third_change = 'E';
          break;
          case 'J':
          third_change = 'X';
          break;
          case 'K':
          third_change = 'Q';
          break;
          case 'L':
          third_change = 'Z';
          break;
          case 'M':
          third_change = 'O';
          break;
          case 'N':
          third_change = 'V';
          break;
          case 'O':
          third_change = 'S';
          break;
          case 'P':
          third_change = 'B';
          break;
          case 'Q':
          third_change = 'L';
          break;
          case 'R':
          third_change = 'J';
          break;
          case 'S':
          third_change = 'D';
          break;
          case 'T':
          third_change = 'Y';
          break;
          case 'U':
          third_change = 'F';
          break;
          case 'V':
          third_change = 'R';
          break;
          case 'W':
          third_change = 'A';
          break;
          case 'X':
          third_change = 'G';
          break;
          case 'Y':
          third_change = 'T';
          break;
          case 'Z':
          third_change = 'M';
          break;
        }
        break;
      }
    }
   // period to check to not decode the period at the end
    if (charInput != '.')
   //Output message
    cout << third_change << endl;
    else
    cout << "Found termination...ending the message..." << endl;
  }while (charInput != '.');
return 0;
}
