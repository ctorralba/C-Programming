/*Programmer: Christopher Torralba	Date:11/18/15
Section: F
Lab: 13
Purpose: class file for complex numbers.
*/

#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
using namespace std;

class Complex
{
  private:
    int m_real;
    int m_imaginary;
    
  public:
    //Default constructor for complex number
    //Pre: None
    //Post: m_real set to 0. m_imaginary set to 0.
    Complex(): m_real(0), m_imaginary (0) {}
    
    //Constructor for complex numbers
    //Pre: real has an int num. imagine has an int num.
    //Post: m_real is set to real. m_imaginary is set to imagine.
    Complex(const int real, const int imagine);
    
    //Overloaded op for the <<
    //Pre: None
    //Post: Complex member variable values will be output to outs, modifying
    // the ostream outs.
    friend ostream& operator << (ostream& outs, const Complex& c);
    
    //overloaded op for the +
    //Pre: None
    //Post: Complex member variables will be added together respectively
    friend Complex operator +(const Complex &c1, const Complex &c2);
                                   
    //overloaded op for the - 
    //Pre: None
    //Post: Complex member variables will be subtracted together
    //      respectively
    friend Complex operator - (const Complex &c1, const Complex &c2);
    
    //overloaded op for the *
    //Pre: None
    //Post: Complex member variables will be multiplied together
    //      respectively
    friend Complex operator *(const Complex &c1, const Complex &c2);
};

#endif
