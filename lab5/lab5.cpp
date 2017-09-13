//Programmer: Christopher Torralba      Date: 9/23/15
//Section: F
//Program: Lab5.cpp
//Purpose: Creating a menu with 4 choices - even numbers, odd numbers,
//	   prime numbers, or exit.

#include <iostream>
using namespace std;

int main ()
{
short choice;		//choice in switch case
short evenNum;		//even num value
short oddNum;		//odd num value
short firstRangeNum;	//user input min range
short lastRangeNum;	//user input max range
short primeNumPlaceHold;//placeholder for for loop
//Welcome Message
cout << "Welcome! " << endl;
do
{
cout << endl;
cout << "1. Even numbers in the given range" << endl;
cout << "2. Odd numbers in the given range" << endl;
cout << "3. Prime numbers in the given range" << endl;
cout << "4. Exit" << endl;		//Given Choices
cout << "Enter your choice: " << endl;
cin >> choice;
//Validating Input
if ((choice >= 1) && (choice < 4))
  {
  cout << "Enter the range (min): " << endl;
  cin >> firstRangeNum;
  cout << "Enter the range (max): " << endl;
  cin >> lastRangeNum;
  }
else if (choice != 4)
{
 cout << "Please input a valid number!" << endl;
}
//Switch Case
switch (choice)
 {
 case 1: for (evenNum = firstRangeNum;evenNum <= lastRangeNum; evenNum++)
         {
         if ((evenNum % 2) == 0)
          cout << evenNum << " ";
         }
         break;
 case 2: for (oddNum=firstRangeNum;oddNum<=lastRangeNum;oddNum++)
         {
          if (!((oddNum % 2) == 0))
          cout << oddNum << " " ;
         }
         break;
 case 3: for(int i=firstRangeNum;i <= lastRangeNum;i++)
          {
            primeNumPlaceHold = 0;
            for (int j = 1;j <= i;j++)
               {
                 if ((i % j) == 0)
                 primeNumPlaceHold++;
               }
                 if (primeNumPlaceHold <= 2)
                 cout << i << " ";
          }
          break;
 case 4: cout << "Goodbye! " << endl;
          break;
 } 
}while (choice != 4);	//end while loop
return 0;
}
