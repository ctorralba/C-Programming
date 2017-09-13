//Programmer: Christopher Torralba Date:10/7/15
//Section: F
//File Name: Lab7.cpp
//Purpose: To simulate an ATM

#include <iostream>
#include "header.h"
using namespace std;

int main()
{
  short choice;
  short cash;
  int balance = 5000;
  //choices being made and chosen
  do
  {
    cout << "Welcome to The Best Bank in the World" << endl;
    cout << "1. Deposit " << endl;
    cout << "2. Withdraw" << endl;
    cout << "3. Check your Balance " << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
      case 1:
      {
      cout << "Enter the amount you want to deposit: ";
      cin >> cash;
      deposit(cash, balance);
      }
      break;
      case 2:
      {
        do
        {
          cout << "Enter the amount you want to withdraw: ";
          cin >> cash;
          if (cash > balance)
          {
          cout << "Invalid...Too much is being withdrawn..." << endl;
          }
        }while (cash > balance);
          
        withdraw(cash, balance);
      }
      break;
      case 3:
      {
      cout << "Your balance is $" << balance << endl;
      }
      break;
      case 4:
      cout << "Goodbye!" << endl;
    }
  }while (choice != 4); //repeat
return 0;
}
