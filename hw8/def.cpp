/*
Programmer: Christopher Torralba	Date: 10/29/15
Instructor: Leopold
Section: J
Purpose: Contains the function definitions need for encryption.
*/
#include "header.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <ctime>
#include <cstdlib>
using namespace std;

bool uY_End(const char word[])
{
  bool uY_End = false;
  if ((word[strlen(word)-LASTLETTER] == 'u') || (word[strlen(word)-LASTLETTER]
	     == 'y'))
  {
    uY_End = true;
  }
  if (word[strlen(word)-LASTLETTER] == ',')
  {
    if ((word[strlen(word)-SECONDLASTLETTER] == 'u') || (word[strlen(word)
         -SECONDLASTLETTER] == 'y'))
    {
      uY_End = true;
    }
  }
  return (uY_End);
}

void vowelEnd(char word[])
{
  if ((word[strlen(word)-LASTLETTER] == 'a') ||
      (word[strlen(word)-LASTLETTER] == 'i') ||
      (word[strlen(word)-LASTLETTER] == 'o') ||
      (word[strlen(word)-LASTLETTER] == 'A') ||
      (word[strlen(word)-LASTLETTER] == 'I') ||
      (word[strlen(word)-LASTLETTER] == 'O'))
  {
    strcat(word, "st");
  }
  return;
}

void ionCheck (char word[])
{
  short length;
  length = strlen(word);
  for (short i=INITIALIZER; i<length; i++)
  {
    if ((word[i]=='i') && (word[i+1]=='o') && (word[i+2]=='n'))
    {
      word[i]='o';
      word[i+OFFSETNUM1]='r';
      if (isalpha(word[i+ALPHACHECK]))
      {
        for (short j = (i+OFFSETNUM2); j < length; j++)
        {
          word[j] = word[j+OFFSETNUM1];
        }
      }
      else
      {
        word[i+OFFSETNUM2] = '\0';
      }
    }
  }
  return;
}

void theCheck (char word[])
{
  const char the[] = "the";
  const char capthe[] = "The";
  if (strcmp(word, the) == 0)
  {
    strcpy(word,"da");
  }
  if (strcmp(word,capthe) == 0)
  {
    strcpy(word,"Da");
  }
  return;
}

void reverse(char word[])
{
  short length;
  char temp[MAX_WORD_LENGTH]="\0";
  length = strlen(word);
  short j = INITIALIZER;
  for (short i = length-LASTLETTER; i >= 0; i--)
  {
    temp[j] = word[i];
    j++;
  }
  strcpy(word, temp);
  return;
}

void insertHomerism(ofstream &fout)
{
  short homerismRow;
  homerismRow = rand () % HOMERISMCHOICE;
  switch (homerismRow)
  {
    case 1:
    fout << "shut up Flanders ";
    break;
    case 2:
    fout << "D'OH! ";
    break;
    case 3:
    fout << "woo hoo! ";
    break;
    case 4:
    fout << "why, you little... ";
    break;
    case 5:
    fout << "mmmmmm, doughnuttttt ";
    break;
    case 6:
    fout << "stupid Flanders ";
    break;
    case 7:
    fout << "BART! ";
    break;
    case 8:
    fout << "borrrring ";
    break;
  }
  return;
}
