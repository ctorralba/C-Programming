//Programmer: Christopher Torralba	Date: 9/16/15
//
//Purpose: Finding the greatest number from 3 randomly generated numbers.
//	  
//Section: F

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
int main ()
{
//seeding random number
srand (time(NULL));

short a;
short b;
short c;

//random number
a = rand() % (100-0);
b = rand() % (100-0);
c = rand() % (100-0);
//validating numbers and Output
cout << "Welcome! " << endl;
cout << "The numbers are: " << a << ", " << b << ", " << c << endl;

//checking if a,b,c is greater
if (a >= b && a >= c)
  {
  cout << a << " is the greatest" << endl;
  }
  else
  { if (b >= c && b >= a)
    {cout << b << " is the greatest" << endl;
    }
    else
     {cout << c << " is the greatest" << endl;
     }
  }   

return 0;
}
