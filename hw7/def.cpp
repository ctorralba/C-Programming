/*
Programmer: Christopher Torralba	Date: 10/23/15
Section: J
Instructor: Leopold
File: def.cpp
Purpose: Holds the definitions for the functions used in carDatabase.cpp
*/

#include "header.h"

short scoreLicenseDigit(const char licInput, const char licDataEntry)
{
  short score;
  switch(licInput)
  {
    case '*':
    score = SOMESCORE;
    break;
    case 'A':
    case 'B':
    case 'C':
    score = ((licInput == licDataEntry)? ALLSCORE:NOSCORE);
    break;
    default:
    score = ((licInput == licDataEntry)? ALLSCORE:NOSCORE);
  }
  return (score);
}
                                                   
short colConverter(const string anyColor)
{
  short numColor;
  if (anyColor == "black")
  {
    numColor = 1;
  }
  if (anyColor == "dark blue")
  {
    numColor = 2;
  }
  if (anyColor == "blue")
  {
    numColor = 3;
  }
  if (anyColor == "grey")
  {
    numColor = 4;
  }
  if (anyColor == "silver")
  {
    numColor = 5;
  }
  if (anyColor == "white")
  {
    numColor = 6;
  }
  return (numColor);
}

short scoreColor(const short colInput, const short colDataEntry)
{
  short colorDiff, colScore;
  colorDiff = colInput - colDataEntry;
  switch (colorDiff)
  {
    case 0:
    colScore = ALLSCORE;
    break;
    case 1:
    case (0-1):
    colScore = SOMESCORE;
    break;
    default:
	colScore = NOSCORE;
  }
return (colScore);
}
