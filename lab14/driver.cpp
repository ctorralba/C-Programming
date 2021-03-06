/*Programmer: Christopher Torralba      Date: 12/2/15
Section: F
Lab: 13
Purpose: Create a template class to add any type of data to an array, display
the elements and search the array to find the position of an element.
*/

#include "linear.h"
#include <iostream>
using namespace std;

int main()
{
 
  //int search
  Linear<int> intSearch;
  
  intSearch.insert(1);
  intSearch.insert(2);
  intSearch.insert(5);
  intSearch.display();
  intSearch.search(2);
  
  //char search
  Linear<char> charSearch;
  
  charSearch.insert('a');
  charSearch.insert('c');
  charSearch.insert('b');
  charSearch.display();
  charSearch.search('b');

return (0);
}
