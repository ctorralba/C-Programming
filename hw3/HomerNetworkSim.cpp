//Programmer: Christopher Torralba	Date: 9/16/15
//Section: J
//File: HomerNetworkSim.cpp
//Professor: Leopold
//Purpose: To create a program that will simulate commnication traffic on
//	   homer's network to identify security vulnerabilities

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()

{
const short BEGINSOURCEADDRESS = 1;	//min integer for source address
const short ENDSOURCEADDRESS = 4;	//max integer for source address
const short BEGINDESTINATIONADDRESS = 1;//min integer for destination add.
const short ENDDESTINATIONADDRESS = 4;	//max integer for destination add.
const short BEGINMESSAGECODE = 0;	//min integer for message code
const short ENDMESSAGECODE = 99;	//max integer for message code
const short ENDPING = 84;		//highest value for a ping
const short ENDRC = 98;		//highest value for a real communication
const short HOMERNETBAND = 50;	//homer's network bandwidth
const short MAXPACKETS = 100;	//max packets for termination
short homerAddress;		//input for Homer's Address
short sourceAddress;		//source address variable
short destinationAddress;	//destination address random variable
short messageCode;		//message code random variable
short smurfAttackNum;		//track potential smurf attacks
short packetCount;		//track packets

//Random Number Generator
srand(time(NULL));

  cout << "Welcome! Initializing your network... " << endl;
//Checking if input is valid
  cout << "What is your network address? " << endl;
  cin >> homerAddress;
  //check if input is between 1 and 4 (inclusive)
    if ((homerAddress > 0) && (homerAddress <= 4)) 		
        cout << "Loading...Please Wait..." << endl;
    //Otherwise stuck in while loop if input is invalid
    else
       while(!((homerAddress > 0) && (homerAddress <= 4)))
       {
       cout << "Please input a valid network address!" << endl;
       cin >> homerAddress;
       }
//Processing Packets
  //initializing variables
  smurfAttackNum = 0;
  packetCount = 0;
  do
  {
  //Generating Random Data
  sourceAddress = (rand() % (ENDSOURCEADDRESS-BEGINSOURCEADDRESS + 1)
                + BEGINSOURCEADDRESS);
  destinationAddress = (rand () % (ENDDESTINATIONADDRESS - 
                     BEGINDESTINATIONADDRESS + 1) + BEGINDESTINATIONADDRESS);
  messageCode = rand() % (ENDMESSAGECODE - BEGINMESSAGECODE + 1);
  
  //Repeating Message
  cout << "Recieved message code " << messageCode << " sent from source "
       << sourceAddress << " to destination " << destinationAddress << "."
       << endl;
  //Ping     
  if ((homerAddress == sourceAddress) && (messageCode <= ENDPING))
    {
    smurfAttackNum++;
    packetCount++;
    cout << "Possible smurf attack (detected " << smurfAttackNum << " times)"
         << endl;
    }
  else
    {
      if ((messageCode > ENDPING) && (messageCode <= ENDRC))
       {//Real Communication
        packetCount++;
        cout << "Got any doughnuts or beer? " << endl;
       }
      else            
       {//Malformed Ping
         if (messageCode > ENDRC)
           cout << "Ping of DEAT-" << endl;
         else
         {
           packetCount++;
           cout << "I am available source " << sourceAddress << "." << endl;
         }
       }
    }   
  //end loop
  }
   while ((smurfAttackNum <= (HOMERNETBAND/3)) && (messageCode <= ENDRC)
          && (packetCount < MAXPACKETS));
  //Output
 if (packetCount == MAXPACKETS)
   { //Successful Output
   cout << "The simulation was a success, you have processed 100 packets"
        << endl;
   }
   else
   { //Smurf Attack Output
     if (smurfAttackNum > (HOMERNETBAND/3))
       {
       cout << "Network has crashed due to excessive smurf attacks!" << endl;
       cout << "Homer's network stopped after processing " << packetCount
            << " messages. System Crashed." << endl;
       }
     else
       { //Ping of Death output
       if (messageCode > ENDRC)
           cout << "System Crashing. Shutting Down... Processed "
                << packetCount << " messages." << endl;
       }
   }
return 0;
}
