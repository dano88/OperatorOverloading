//==========================================================
//
// Title: Operator overloading
// Description:
//   This C++ console application demonstrates operator 
// overloading.  This application requires three files:
//   -This file
//   -OperatorOverloading-Timer-Header.h
//   -OperatorOverloading-Timer-Implementation.cpp
// Overloaded operators are +, -, and <<.
// Here's a change ...
//
//==========================================================
#include <cstdlib>  // For several general-purpose functions
#include <fstream>  // For file handling
#include <iomanip>  // For formatted output
#include <iostream>  // For cin, cout, and system
#include <string>  // For string data type
#include <vector>  // For vectors
#include <thread>  // For threads
#include "OperatorOverloading-Timer-Header.h"
using namespace std;  // So "std::cout" may be abbreviated to "cout"

//----------------------------------------------------------
// Globals
//----------------------------------------------------------

// Declare constants
const int MAX_TIME = 100;  // seconds
const int TIMER_DEFAULT = 5;  // seconds
const int THREAD_PAUSE = 1;  // seconds

// "\033" is the escape "character"
// "[2J" is the command to clear the screen.
// "[10;1H" is the command to position the cursor in row 10,
//   col 1
const string CLEAR_AND_MIDDLE = "\033[2J\033[12;42H";
const string CLEAR_AND_TOP = "\033[2J\033[1;1H";
const string LOWER_MIDDLE = "\033[16;26H";

//----------------------------------------------------------
// addTime
//----------------------------------------------------------
void addTime(Timer& timer)
{

  // Declare variables
  int add;

  // Get seconds to add
  cout << "\nEnter number of seconds to add (<="
    << (MAX_TIME - timer.getSecondsLeft()) << "): ";
  cin >> add;

  // Add time
  //timer = timer + Timer(add);
  timer = timer + add;

}

//----------------------------------------------------------
// decrementTimer
//----------------------------------------------------------
void decrementTimer(Timer& timer)
{
  timer--;
}

//----------------------------------------------------------
// incrementTimer
//----------------------------------------------------------
void incrementTimer(Timer& timer)
{
  ++timer;
}

//----------------------------------------------------------
// menuOption
//----------------------------------------------------------
int menuOption(Timer timer)
{

  // Declare variables
  int option;

  // Show menu
  cout << "\nOperator Overloading Menu" << endl;
  cout << "Timer is currently set at " << timer << endl;
  cout << "1 - Add time to timer" << endl;
  cout << "2 - Remove time from timer" << endl;
  cout << "3 - Increment timer" << endl;
  cout << "4 - Decrement timer" << endl;
  cout << "5 - Reset timer" << endl;
  cout << "6 - Run timer" << endl;
  cout << "9 - Exit" << endl;
  cout << "Enter an option: ";
  cin >> option;
  return option;

}

//----------------------------------------------------------
// resetTimer
//----------------------------------------------------------
void resetTimer(Timer& timer)
{
  timer = Timer(TIMER_DEFAULT);
}

//----------------------------------------------------------
// runTimer
//----------------------------------------------------------
void runTimer(Timer timer)
{

  // Declare variables
  int start;
  string option;

  // Loop to run timer
  start = timer.getSecondsLeft();
  for (int i = start; i >= 0; i--)
  {

    // Clear screen
    this_thread::sleep_for(chrono::seconds(THREAD_PAUSE));
    cout << CLEAR_AND_MIDDLE;

    // Show timer
    cout << i << endl;

  }

  // Show close
  cout << LOWER_MIDDLE;
  cout << "DONE! Press ENTER to continue ...";
  cin.ignore(1000, '\n');
  getline(cin, option);
  cout << CLEAR_AND_TOP;

}

//----------------------------------------------------------
// subtractTime
//----------------------------------------------------------
void subtractTime(Timer& timer)
{

  // Declare variables
  int subtract;

  // Get seconds to subtract
  cout << "\nEnter number of seconds to subtract (<" 
    << timer.getSecondsLeft() << "): ";
  cin >> subtract;

  // Subtract time
  timer = timer - subtract;

}

//----------------------------------------------------------
// main
//----------------------------------------------------------
int main()
{

  // Declare variables
  int option;
  
  // Show application header
  cout << "Welcome to Operator Overloading" << endl;
  cout << "-------------------------------" << endl;

  // Create timer
  Timer timer = Timer();

  // Loop to process menu options
  option = menuOption(timer);
  while (option != 9)
  {

    // Test which option selected
    switch (option)
    {

      case 1:
        addTime(timer);
        break;

      case 2:
        subtractTime(timer);
        break;

      case 3:
        incrementTimer(timer);
        break;

      case 4:
        decrementTimer(timer);
        break;
      
      case 5:
        resetTimer(timer);
        break;

      case 6:
        runTimer(timer);
        break;

      default:
        cout << "Error: unknown option of " << option
          << "." << endl;

    }

    // Get next option
    option = menuOption(timer);

  }

  // Show application close
  cout << "\nEnd of Operator Overloading" << endl;

}
