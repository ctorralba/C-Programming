// Programmer: Christopher Torralba     Date: October 2, 2015
// File: optimizedPassGen.cpp
// Section: J
// Instructor: Leopold
// Purpose: To generate a 9-letter password containing alphanumeric values
// 	    with the use of functions.

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

//~~~~~Function Prototypes~~~~~~~

// Display a greeting to the user.
// Preconditions: None
// Postconditions: A message has been output to the screen.
void welcome();

// Validates the input for any prompt given
// Preconditions: Depending on given prompt using a string, validates the 
//                input for the prompt using min and max values
// Postconditions: Validated 'Input' is returned
short valid_Input(const string prompt, const short min, const short max);

// Calculates the letter based off given input
// Preconditions: Parameter age has to be a value between 1-100
//		  Parameter brainWeight has to be a value between 0-10
//                Parameter regularlyEatsGlue has to be either 0 or 1
char calculateChar(const short age, const short brainWeight,
                   const short regularlyEatsGlue);
                   
// Display a sign-off message to the user
// Preconditions: None
// Postconditions: A message has been output to the screen.
void signOff();

//CONSTANTS
const short MIN_AGE = 1;		//Minimum Age for a user
const short MAX_AGE = 100;		//Maximum Age for a user
const short MIN_BRAIN = 0;		//Minimum weight for a brain
const short MAX_BRAIN = 10;		//Max weight for a brain
const short NO_GLUE = 0;		  //User doesn't eat glue
const short YES_GLUE = 1;		  //User does eat glue
const short K_FACTOR_INCREMENT = 100;	  // Amount to increment kFactor
const short HOMER_IQ = 26;                // Homer's IQ
const short HOMER_DONUT_CONSUMPTION = 65; // Homer's daily donut consumption
const short AVG_GLUE_EATER_IQ = 32;       // Avg IQ of regular glue eaters

int main()
{
  //Variables
  char letter;		//letter used to get char from function
  short digit;		//digit used to grab rand # 
  short age;		//grabs validated age from function
  short brainWeight;	//grabs validated brain weight from function
  bool eatGlue;		//grabs validated input for eating glue
  const short EVEN = 2;	//used for random # generator to produce a 0 or 1.
  const short CALC_CHAR = 1; // used to check if rand # is a 1 or not.
  const short DIGIT_SIZE = 10; //Used to make rand # between 0 and 9
  // Greeting
  welcome();
                       
  // Get user inputs
  age = valid_Input("Enter your age: ", MIN_AGE, MAX_AGE);
  brainWeight = valid_Input( "Enter the weight of your brain (lbs): ",
                MIN_BRAIN, MAX_BRAIN);
  eatGlue = valid_Input( "Do you eat glue regularly? (1 = yes, 0 = no) ",
                NO_GLUE, YES_GLUE);
              
  //seed for random # generator
  srand(5);   
  // Calculate and output each of the 4 letters of user's password
  cout << "Your password is ";
  for (short i=1; i<=9; i++)
  {
    if ((rand() % EVEN) == CALC_CHAR)
      {
      letter =  calculateChar(age, brainWeight, eatGlue);
      cout << letter;
      }
    else
      {
      digit = (rand() % DIGIT_SIZE);
      cout << digit;
      }
  }
  // Sign-off Message
  signOff();
  return 0;
}
  
//Function Definitions
void welcome()
{
  cout <<"Welcome to the password generator!\n";
  cout << endl;
  return;
}

short valid_Input(const string prompt, const short min, const short max)
{
  short input;
  static int invalidmsg = 1;
  do 
  { 
    cout << prompt;
    cin >> input;
    if (!(input <= max && input >= min))
    {
      cout << "Invalid...";
      switch (invalidmsg)
      {
        case 1: cout << "Age has to be between 1-100..." << endl;
        break;
        case 2: cout << "Brain Weight has to be between 0-10... "<< endl;
        break;
        case 3: cout << "Please put in a 0 or 1...";
        break;
      }
    }
  }while (!(input <= max && input >= min));    
  invalidmsg++;
  return (input);
}  
char calculateChar(const short age, const short brainWeight,
                   const short regularlyEatsGlue)
{
  short asciiValue;
  char letter;
  
  static int kFactor = HOMER_IQ * HOMER_DONUT_CONSUMPTION * 
                       AVG_GLUE_EATER_IQ;
                       
  asciiValue = (static_cast<int>
          (static_cast<float>(brainWeight) / age * kFactor) %  HOMER_IQ) +
          HOMER_DONUT_CONSUMPTION + (regularlyEatsGlue * AVG_GLUE_EATER_IQ);
  
  letter = static_cast<char>(asciiValue);
  
  kFactor += K_FACTOR_INCREMENT;
  
  return (letter);
}
void signOff()
{
   cout << "\n\nHave a nice day "
        << "and don't forget that password!\n";
          
   return;
}
