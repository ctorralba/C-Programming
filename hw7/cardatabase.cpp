/*
Programmer: Christopher Torralba Date: 10/19/15
Section: J
Instructor: Leopold
File: cardatabase.cpp
Purpose: To create a database containing a car's license plate, the color of the
car and the names with each car. A user then enters data that relates to the
database and is shown a score based on how related their input is to the 
database.
*/
#include "header.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <string.h>
#include <cctype>
using namespace std;
suspects s[SUSPECTSIZE];
int main ()
{
  srand(10);
  short minScore;	  //user input on the minimum data seen.
  short maxValueShown = 0;//The max value that is shown on display
  short licScoreAdd;	  //used to add the score together for each
                              // independent letter & digit.
  short user_color_digit; //user color input converted into a digit
  short data_color_digit; //database color input converted into a digit
  short totalScoreColor;  //score from comparing the difference in color-digit
  string newQuery;	  //used to repeat another database search.
  char chLicense [6];	  //contains the alphanumeric license values
  char licenseSeen[6];	  //contains the userinput alphanumeric license values
  string colorSeen;	  //user color input for query
  bool licRepeated = false;	//used if license if repeated
  bool wrongLicenseInput = true;//used if user inputs license entry
  bool wrongColorInput = true;	//used if user inputs wrong color entry

  cout << "\tCar Database: " << endl;
  cout << "License\t\tColor\t\tOwner" << endl;
  cout << "---------------------------------------" << endl;

  for (short i = SUSPECTSTART; i < SUSPECTSIZE; i++)
  {
    do
    { //license creator
      for (short j = LICENSESTART; j < LICENSE; j++)
      {
        chLicense[j]= (j < ALPHAEND)?(rand() % RAND_A_C + 'A'):
	              (rand() % RAND_0_9 +'0');
      }
    //license repeat check
      for (short j = SUSPECTSTART; j < SUSPECTSIZE; j++)
      {
        if (strcmp(chLicense, s[j].license) == noDiff)
        {
          licRepeated = true;
        }
      }
    }while (licRepeated);
    //if not repeated sets struct license as license created
    strcpy (s[i].license, chLicense);
    cout << s[i].license << "\t\t";
    s[i].carColor =  colors[rand() % COLORNUM];
    cout << s[i].carColor;
    s[i].carColor == "dark blue"? cout << "\t" : cout << "\t\t";
    s[i].name = names[rand() % NAMENUM];
    cout << s[i].name << endl;
  }
  /******Car Search**************************/
  cout << endl;
  do
  {
    do
    {	//license query
      cout << "What was the license plate of the car?" << endl;
      cin >> licenseSeen;
      for (short i = LICENSESTART; i < LICENSE; i++)
      {
        if ((i >= LICENSESTART) &&(i < ALPHAEND))
        {
	  if (!(licenseSeen[i] != 65 && licenseSeen[i] != 66 &&
	      licenseSeen[i] != 67 && licenseSeen[i] != '*'))
	  {
	    wrongLicenseInput = false;
	  }
	  else
	  {
	    wrongLicenseInput = true;
	  }
        }
        else
	{
	  if (((licenseSeen[i] >= 48) && (licenseSeen[i] <= 57)) || 
	       licenseSeen[i] == '*')
	  {
	    wrongLicenseInput = false;
	  }
	  else
	  {
	    wrongLicenseInput = true;
	  }
	}
      }
      if (wrongLicenseInput == true)
      {
        cout << "WRONG! ...";
      }
    }while (wrongLicenseInput);
    cin.ignore(1000,'\n');
    do//color query
    {
      cout << "What was the color of the car?" << endl;
      getline(cin, colorSeen);
      for (short m = COLORNUMSTART; m < COLORNUM; m++)
      {
        if (colorSeen == colors[m])
	{
	  wrongColorInput = false;
	}
      }
      if (wrongColorInput == true)
      {
        cout << "Color not in database! ...";
      }
    }while (wrongColorInput);		
    //minimum query
    do
    {
      cout << "What is the minimum score you want to see? " << endl;
      cin >> minScore;
      if (!(minScore >= 0 && minScore <=14))
      {
      	//validating minimum query
      	cout << "Minimum Score is out of range ...";
      }
    }while (!(minScore >= 0 && minScore <=14));
    //Getting the scores for licenses
    for (short i = SUSPECTSTART; i < SUSPECTSIZE; i++)
    {
      for (short j = LICENSESTART; j < LICENSE; j++)
      {
        licScoreAdd = scoreLicenseDigit(licenseSeen[j], s[i].license[j]);
       	s[i].score += licScoreAdd;
      }
      user_color_digit = colConverter (colorSeen);
      data_color_digit = colConverter (s[i].carColor);
      totalScoreColor = scoreColor(user_color_digit, data_color_digit);
      s[i].score += totalScoreColor;
    }
  //***********The Display******************
  cout << endl;
  //Max value to be displayed
    for (short i = SUSPECTSTART; i<SUSPECTSIZE; i++)
    {
      if(s[i].score > maxValueShown)
      maxValueShown = s[i].score;
    }
  //Database Display
    for (short i = maxValueShown; i >= minScore; i--)
    {
      cout << "Score " << i << ":" << endl;
      for (short j=SUSPECTSTART; j<SUSPECTSIZE; j++)
      {
        if (s[j].score == i)
        {
          cout <<"\t" << s[j].license << "\t\t" << s[j].carColor;
	  if (s[j].carColor == "dark blue")
	  {
	    cout << "\t";
	  }
	  else
	  {
	    cout << "\t\t";
	  }
	  cout << s[j].name << endl;
        }
      }
    }
    cout << endl;
    cout << "Do you want anymore inputs? (quit = end) (yes = continue)";
    cout << endl;
    cin >> newQuery;
    if (newQuery != "quit")
    {
      for (short i=SUSPECTSTART; i<SUSPECTSIZE; i++)
      {  //reset scores and max value shown if repeated
        s[i].score = RESETQUERY;
        maxValueShown = RESETQUERY;
      }
    }
  }while (newQuery != "quit");
return 0;
}

