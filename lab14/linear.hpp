/*Programmer: Christopher Torralba      Date: 12/2/15
Section: F
Lab: 13
Purpose: The implementation file for the linear class.
*/

#include <iostream>
using namespace std;

template <class T>
bool Linear <T> :: insert(const T e)
{
  bool success = true;
  //inserts only if full
  if (!isFull())
  {
    m_data[m_numElements] = e;
    m_numElements++;
  }
  else success = false;
  return (success); 
}
 
template <class T>
void Linear<T> :: search(const T key)
{
  cout << "Searching for " << key << "..." << endl;
  for (short i = 0; i < m_numElements; i++)
  {
    if (m_data[i] == key)
    {                                              //array starts at 0
      cout << "Found " << key << " at position " << i+1 << endl;
    }
  }
}

template <class T>
void Linear<T> :: display()
{//displays all data till numElements
  for (short i = 0; i < m_numElements; i++)
  {
    cout << m_data[i] << " ";
  }
  cout << endl;
  return;
}
 
