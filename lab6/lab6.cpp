//Christopher Torralba
//Section F
//Date: 9/30/15
//Purpose: Creating two functions that spits out a factorial and a
// 	   fibonacci series.
//Student ID: 12522141

#include <iostream>
using namespace std;

//function prototypes
long factorial (int x);
void fibinacci ();

//main function
int main()
{
  short n;
  short factorial_out;
  cout << "Welcome!" << endl;
  cout << "Enter a number:  " << endl;
  cin >> n;
  factorial_out = factorial(n);
  cout << "Factorial of " << n << " = " << factorial_out << endl;
  cout << "First 10 terms of Fibonacci series are:" << endl;
  fibinacci ();
  cout << "Goodbye!" << endl;

return 0;
}
//factorial function definition
long factorial (int x)
{
  short next = 1;
  for (short i=1; i<=x; i++)
   {
   next = i*(next);
   }
   return (next);
}  
//fibinacci function definition
void fibinacci ()
{
  short first = 0;
  short second = 1;
  cout << "0 " << "1 ";
  for (short i=1; i <= 8; i++)
    {
      short next = first + second;
      first = second;
      second = next;
      cout << next << " ";
    }
  cout << endl;
return;
}                           
