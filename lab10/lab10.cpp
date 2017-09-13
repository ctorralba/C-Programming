//Programmer: Christopher Torralba	Date: 10/28/15
//Section: F
//Purpose: To make me familiar with Files I/O

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main ()
{
  ifstream fin;
  ofstream fout;
  char palindrome[20];
  char temp [20];
  char palindromeword[20];
  short length;
  do
  {
    fin.clear();  // reset connection
    //getting a file  
    cout << "Enter name of file to open: ";       
    cin.getline(palindrome, 20);
    fin.open(palindrome);
                 
  }while (!fin);
  fin >> palindromeword;
  cout << "Word in the file is " << palindromeword << endl;
   
  length = strlen(palindromeword);
  cout << length << endl;
  //Switching into temporary
  short j = 0;
  for (short i = length-1; i >= 0; i--)
  {
    temp [i] = palindromeword[j];
    j++;
  }
  cout << temp << endl;;
  
  if (strcmp(palindromeword,temp) == 0)
  {
    cout << palindromeword << " is a palindrome" << endl;
    fout.open("output.txt");
    fout << palindromeword << " is a palindrome" << endl;
  }
  else
  {
    cout << palindromeword << " is not a palindrome" << endl;
    fout.open ("output.txt");
    fout << palindromeword << " is not a palindrome" << endl;
  }
return 0;
}
