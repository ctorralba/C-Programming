/* Programmer: Christopher Torralba	Date: 12/9/15
   Section: F
   Purpose: Create a Hang Man game.
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string.h>

using namespace std;

bool inWord (const char chosenWord[], const char guess);
int main ()
{
  const short COLORNUM = 10;
  const short COLORLENGTH = 20;
  short counter = 0;
  char myGuess, letterFound;
  short tries = 5, colorIndex;
  const string colors [COLORNUM] = {"black", "green", "blue", "grey",
                                    "silver", "white", "red", "yellow",
                                    "purple", "orange"};
  char chosenWord[20];
  char playArea[20] = {"-"};
  srand(time(NULL));
  cout << "Hangman" << endl;
  cout << "Guess this color:" << endl;
  colorIndex = rand() % COLORNUM;
  strcpy(chosenWord, colors[colorIndex].c_str());
  do
  {
    cout << "-";
    counter++;
  }while (counter != strlen(chosenWord));
  cout << endl;  
  do
  {
    cout << "You have " << tries << " tries left " << endl;
    cout << "Misses: " << endl;
    cout << "Guess: ";
    cin >> myGuess;
    cout << endl;
   
    if (!(inWord (chosenWord, myGuess)))
    {
      cout << "That letter isn't there" << endl;
      tries--;
    }
    else
    {
      cout << "Found: " << endl;
      for (short i = 0; i < strlen(chosenWord); i++)
      {
        if (myGuess != chosenWord[i])
        {
          playArea[i] = '-';
        }
        else
        {
          playArea[i] = myGuess;
        }
      }
      cout << playArea;
      cout << endl;
    }
  }while (tries != 0);
  return 0;  
}

bool inWord (const char chosenWord[], const char guess)
{
  bool found = false;
  for (short i = 0; i < 20; i++)
  {
    if (chosenWord[i] == guess)
    {
      found = true;
    }
  }
  return (found);
}
