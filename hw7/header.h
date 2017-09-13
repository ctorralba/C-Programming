/*
Programmer: Christopher Torralba	Date: 10/23/2015
Section: J
Instructor: Leopold
File Name: header.h
Purpose: Contains the function prototypes, constants and structs for the file
	cardatabase.cpp
*/
#ifndef header_h
#define header_h
#include <iostream>
using namespace std;
struct suspects
{
  char license[6];   //license first 3 digits = (A-C) last 3 = (0-9)
  string carColor;   //car color given by colors defined in an array
  string name;	     //name given by colors definined in an array
  short score;	     //total score for each user
};
const short SUSPECTSTART = 0; //The starting number for suspect size.
const short SUSPECTSIZE = 20; //The number of license/color/people displayed
const short LICENSESTART = 0; //starting # in which license data starts/stored
const short LICENSE = 6;   //ending # in which license data ends/stored
const short COLORNUMSTART = 0; //start # in which color data starts/stored
const short COLORNUM = 6;  //end # in which color data end/stored
const short NAMENUM = 25;  //The # of names in an array
const short RAND_A_C = 3;  //# range for rand A to C generation
const short RAND_0_9 = 10; //# range of rand 0 to 9 generation
const short NOSCORE = 0;   //the worst score possible for an entry
const short SOMESCORE = 1; //close score for an entry
const short ALLSCORE = 2;  //best score possible for an entry
const short noDiff = 0;	   //used for strcmp to tell if there's no difference
const short ALPHAEND = 3;  //terminates loops when hit end of alpha value
const short RESETQUERY = 0; //resets the max value and the scores for all data
//holds the car colors
const string colors [COLORNUM] = {"black", "dark blue", "blue", "grey",
                                      "silver", "white"};
//random names used in the struct
const string names [NAMENUM] = {"Paul", "Kimberly", "Belva", "Jess", "China",
                          "Leslie", "Sherice", "Abbey", "Timothy", "Ming",
                          "Charlie", "Sebrina", "Rolando", "Riley", "Sam",
                          "Domingo", "Louis", "Erwin", "Oliver", "Luis",
                          "Chris", "Cristen", "Margret", "Carla", "Hope"};
/*
Description: Calculates the score for only one character of a license.
Preconditions: Both licInput and licDataEntry have to be characters of
		of 'A', 'B', 'C', '1', '2', '3', '*'.
Postconditions: Outputs a score based on whether the two inputs are the same or
		not. If a '*' then outputs a score of 1.
*/                
short scoreLicenseDigit(const char licInput, const char licDataEntry);

/*
Description: Converts krusty's input or a data entry input for color into a num.
Precondition: Both krusty's input and the data entry input has to be a color 
		in the array colors []. (black, dark blue, blue, grey, silver, white).
Postcondtion: outputs a number based on the color input. black = 1,
		dark blue = 2, ... white =6;
*/
short colConverter(const string anyColor);

/*
Description: Calculates the score based on the color.
Precondition: colInput and ColDataEntry has to be a color 
		in the array colors []. (black, dark blue, blue, grey, silver, white).
Postcondition: outputs a score based on the difference in colors (from their 
		converted number).
*/
short scoreColor(const short colInput, const short colDataEntry);
#endif
