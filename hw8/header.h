/*
Programmer: Christopher Torralba	Date: 10/29/15
Instructor: Leopold
Section: J
Purpose: Contains the constants, function protoypes and function documentation
for encryption.
*/
#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream>
#include <string.h>
#include <ctime>
#include <cstdlib>
using namespace std;

const short MAX_WORD_LENGTH = 20;  // max length of a word
const short MAX_WORDS = 256;    // max # words in sentence
const int SENTENCE_LEN = MAX_WORD_LENGTH * MAX_WORDS + 100;//max sentence len
const short LASTLETTER = 1; //used to get last letter of a word
const short SECONDLASTLETTER = 2; // used to get the 2nd to last letter
const short HALFTHETIME = 2; //used for randomly generating a 50% chance
const short INITIALIZER = 0; //used to reset values and initialize values to 0.
const short HOMERISMCHOICE = 9; //used to select 0-8 from rand gen.
const short OFFSETNUM1 = 1; //used to for "ion" to check if 'i', 'o', & 'n'
                            //are next to each other
const short OFFSETNUM2 = 2; //used to for "ion" to check if 'i', 'o', & 'n'
			    //are next to each other
const short ALPHACHECK = 4; //checks to see if a word after "ion" contains
			    //alpha values
const short APPENDEND = 1; //used to check if homerism is appended at end.

/*
Detects whether a last character is a 'u' or a 'y'
Pre: values in word has to be characters and has to be a ntca.
Post: returns a positive if ends in u or y.
*/
bool uY_End(const char word[]);

/*
Detects whether a last character ends in a 'a/A', 'i/I', or'o/O' and appends
an "st" to the char array if it is.
Pre: word has to be filled with characters and has to be a ntca.
Post: Does nothing if doesn't end in 'a/A', 'i/I', or 'o/O', but appends an
"st" if it does end in those vowels.
*/
void vowelEnd(char word[]);

/*
checks to see if the word contains "ion" in any part of it.
Pre: word has to be filled with characters and has to be a ntca.
Post: Does nothing if doesn't end contain a "ion", but if it does, it would
convert that "ion" into an "or".
*/
void ionCheck(char word[]);

/*
Detects and changes "The" and "the" characters.
Pre: word has to be filled with characters and has to be a ntca.
Post: Does nothing if not "The" or "the", but if it does, it would convert
the "The" and "the" to their respective "Da" and "da"
*/
void theCheck(char word[]);

/*
Reverses the characters so it is read from right to left.
Pre: word has to be filled with characters and has to be a ntca.
Post: The word outputed would be reversed.
*/
void reverse(char word[]);

/*
Inserts a random homerism based off when it was called and outputs it out a 
file stream.
Pre: NONE
Post: a random homerism is put out into the filestream.
*/
void insertHomerism(ofstream &fout);
#endif
