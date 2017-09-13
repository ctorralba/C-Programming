/*
Programmer: Christopher Torralba	Date: 10/14/15
File: lab8.cpp
Section: F
Purpose: To use overloading functions to display balance, discount,
and a message
*/

#include <iostream>
using namespace std;
/*
Displays the balance
Preconditions: None
Postconditions: A message has been displayed
*/
void printBill(int balance);
/*
Displays the total after the discount
Preconditions: None
Postconditions: A message containing balance and discount is displayed
*/
void printBill(int balance, float discount);
/*
Displays the balance and a message
Preconditions: None
Postconditions: A string message and balance is displayed
*/
void printBill(int balance, string message);
/*
Displays the total after the discount and a string message
Preconditions: None
Postconditions: The balance and the string message is displayed.
*/
void printBill(int balance, float discount, string message);

int main()
{
  //variable decleration
  int balance;
  float discount;
  char repeat;

  do
  {
    //user input
    cout << "Enter balance: ";
    cin >> balance;
    cout << "Enter the discount (in percent): ";
    cin >> discount;
    
    printBill (balance);
    printBill (balance, discount);
    printBill (balance, "Thank you");
    printBill (balance, discount, "Thank you");
    
    cout << "Do you want to repeat? "<< endl;
    cin >> repeat;
  //repeat or not  
  }while ((repeat == 'y') || (repeat == 'Y'));
  
  return 0;
}

void printBill (int balance)
{
  static short order_Num = 1;
  cout << "Order No. " << order_Num << endl;
  cout << "Total: $" << balance << endl;
  order_Num++;
  return;
}
        
void printBill (int balance, float discount)
{
  float discountTotal;
  float result;
  discountTotal = (discount/100);
  result = (balance - (discountTotal * balance));
  cout << "Total after discount: $" << result << endl;
  return;
}
                  
void printBill (int balance, string message)
{
  cout << "Total: $" << balance << endl;
  cout << message << endl;
                
  return;
}
                        
void printBill (int balance, float discount, string message)
{
  float discountTotal;
  float result;
  discountTotal = (discount/100);
  result = (balance - (discountTotal * balance));
  cout << "Total after discount: $" << result << endl;

  cout << message << endl;
  return;
}
