/*
Programmer: Christopher Torralba Date: 10/7/15
File: def.cpp
Purpose: Holds the function definitions for the ATM.
Section: F
*/

#include <iostream>
#include "header.h"
using namespace std;

//Deposit function
void deposit(int cash, int &balance)
{
  balance = balance + cash;
  cout << "$" << cash << " deposited successfully." << endl;
  return;
//Withdraw Function
}
void withdraw (int cash, int &balance)
{
  balance = balance - cash;
  cout << "$" << cash << " has been dispensed. Please collect your cash." << endl;
  return;
}
