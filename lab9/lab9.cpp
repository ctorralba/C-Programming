/*
Programmer: Christopher Torralba	Date: 10/21/15
Section: F
File Name: lab9.cpp
Purpose: To create a database of student scores
*/
struct students
{
  int score;
  float deviation;
};
#include <iostream>
using namespace std;
int main ()
{
  const short SIZE = 100;
  short numStudents;
  float mean = 0;
  //greeting
  cout << "Welcome!" << endl;
  //asking # students
  cout << "Enter the number of students: ";
  cin >> numStudents;
  students s[SIZE];
  //Entering Scores
  for (short i=0; i < numStudents; i++)
  {
    cout << "Enter the score for student " << i+1 << ": ";
    cin >> s[i].score;
    mean += s[i].score;
  }
  mean = mean/numStudents;
  //Declaring Mean
  cout << "Mean = " << mean;
  //Deviation
  for (short i=0; i < numStudents; i++)
  {
  s[i].deviation = s[i].score - mean;
  }
  //Display
  cout << endl;
  cout << "Score\tDeviation" << endl;
  for (short j=0; j < numStudents; j++)
  {
  cout << s[j].score << "\t" << s[j].deviation << endl;
  }
  //bye
  cout << "Goodbye!";
  return 0;
}
