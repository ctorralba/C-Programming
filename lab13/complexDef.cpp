/*Programmer: Christopher Torralba      Date:11/18/15
Section: F
Lab: 13
Purpose: Implementation file for complex class.
*/

#include "complex.h"
#include <iostream>
using namespace std;

Complex::Complex(const int real, const int imagine)
{  //parametrized constructor
  m_real = real;
  m_imaginary = imagine;
}

ostream& operator<< (ostream&outs, const Complex& c)
{
  if (c.m_real != 0)// check for 0
  {
    outs << c.m_real;
    if (c.m_imaginary > 0)
    { //negative doesn't have a sign to display
      outs << "+";
    }
  }
    
  if (c.m_imaginary != 0)// check for 0
  {
    outs << c.m_imaginary;
    outs << "i";
  }
  return (outs);
}

Complex operator +(const Complex &c1, const Complex &c2)
{
  Complex temp;
  temp.m_real = c1.m_real + c2.m_real;
  temp.m_imaginary = c1.m_imaginary + c2.m_imaginary;
  return (temp);
}

Complex operator - (const Complex &c1, const Complex &c2)
{
  Complex temp;
  temp.m_real = c1.m_real - c2.m_real;
  temp.m_imaginary = c1.m_imaginary - c2.m_imaginary;
  return (temp);
}
    
Complex operator * (const Complex &c1, const Complex &c2)
{
  Complex temp;
  short real, imagine;
  real = c1.m_real * c2.m_real;
  real = real + ((c1.m_imaginary * c2.m_imaginary)*-1);
  temp.m_real = real;
  
  imagine = c1.m_real * c2.m_imaginary;
  imagine = imagine + (c1.m_imaginary * c2.m_real);
  
  temp.m_real = real;
  temp.m_imaginary = imagine;
  
  return (temp);  
}
