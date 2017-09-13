/*Programmer: Christopher Torralba      Date: 12/2/15
Section: F
Lab: 13
Purpose: The header file for the linear class.
*/

#ifndef LINEAR_H
#define LINEAR_H

const int MAX = 100;

template <class T>
class Linear
{
  public:
    //set m_numElements to 0
    //Pre: None
    //Post: m_numElements have been set to 0
    Linear() : m_numElements(0){}
    
    //insert element e into the array
    //Pre: The array has to not be full
    //Post: e is inserted in the array
    bool insert(const T e);
    
    //search for the element key
    //Pre: T has to be used with the == operator
    //Post: a search for the key and and the position is displayed
    void search(const T key);
    
    //displays the array
    //Pre: T has to be usable with the << operator
    //Post: m_data is displayed from 0 to m_numElements
    void display(); //display the elements in the array
    
    //check if the array is full
    //Pre: m_data has to be filled from 0 to m_numElements
    //Post: returns Max if full
    bool isFull() const { return (m_numElements == MAX); }
    
    //check if the array is empty
    //Pre: m_data has to be filled from 0 to m_numElements
    //Post: returns true if empty
    bool isEmpty()const { return (m_numElements == 0); };
    
  private:
    T m_data[MAX]; //create an array of size MAX
    int m_numElements; //denotes the number of elements in the array
};

#include "linear.hpp"

#endif
