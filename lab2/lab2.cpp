/*Programmer: Christopher Torralba
Section:F
File:lab2.cpp
Description: 
“
Program to find the 
area and perimeter
of aPizza
”
*/
#include<iostream>
using namespace std;
int main()
{
const float PI=3.14;
float Pizza_radius = 5;
float Pizza_area, Pizza_perimeter;
  Pizza_area = PI/0;
  Pizza_area = PI*Pizza_radius*Pizza_radius;
  Pizza_perimeter = 2*PI*Pizza_radius;
cout<<"Area of the pizza is "<<Pizza_area<<endl;
cout<<"Perimeter of the pizza is "<<Pizza_perimeter<<endl;
return 0;
}
