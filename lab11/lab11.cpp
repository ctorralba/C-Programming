/*
Programmer: Christopher Torralba	Date: 11/4/15
File Name: lab11.cpp
Section: F
Purpose: Create a Pirate Name Generator using Files I/O.
*/

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
short dd, mm, yy;
ifstream fin;
ofstream fout;
short counter;
string firstname, lastname, title;
string next;

cout << "Enter your birth date: ";
cin >> dd;
cout << "Enter your birt month (1-12): ";
cin >> mm;
cout << "Enter your birth year: ";
cin >> yy;

fin.open ("first.txt");
//Declaring first name
while (fin>>next)
{
  counter++;
  if (counter == dd)
  {
    firstname = next;
  }
}
fin.close();
fin.open("last.txt");
counter = 0;
//Declaring last name
while (fin >> next)
{
  counter ++;
  if (counter == mm)
  {
    lastname = next;
  }
}
fin.close();
fin.open("title.txt");
//Declaring Title
counter = 0;
yy = (yy % 10);
while (getline(fin, next, '\n'))
{
  counter++;
  if ((counter-1) == yy)
  {
    title = next;
  }
}
fin.close();
cout << firstname << " " << lastname << ", " << title;
cout << endl;

return 0;
}
