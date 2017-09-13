/*Programmer: Christopher Torralba      Date:11/18/15
Section: F
Lab: 13
Purpose: To use overloaded operators with complex numbers.
*/

#include "complex.h"
#include <iostream>
using namespace std;

int main ()
{
  Complex c1(5, 4), c2(5, -4), c3;
  
  //testing output
  cout << "Your complex terms are ";
  cout << c1;
  cout << " ";
  cout << c2;
  cout << endl;
  
  //sum
  c3 = c1+c2;
  cout << "Sum = " << c3;
  cout << endl;

  //difference
  c3 = c1-c2;
  cout << "Difference = " << c3;
  cout << endl;
  
  //multiplication
  c3 = c1*c2;
  cout << "Product = " << c3;
  cout << endl;
  return 0;
}
