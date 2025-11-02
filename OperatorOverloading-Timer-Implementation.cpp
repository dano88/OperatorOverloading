//==========================================================
//
// Title: Operator overloading - Timer - Implementation
// Description:
//   This C++ implementation defines the functions for
// prototypes in OperatorOverloading-Timer-Header.h.
//
//==========================================================
#include <cstdlib>  // For several general-purpose functions
#include <fstream>  // For file handling
#include <iomanip>  // For formatted output
#include <iostream>  // For cin, cout, and system
#include <string>  // For string data type
#include <vector>  // For vectors
#include "OperatorOverloading-Timer-Header.h"
using namespace std;  // So "std::cout" may be abbreviated to "cout", for example.

//----------------------------------------------------------
// Function implementations
//----------------------------------------------------------

//----------------------------------------------------------
// Constructors and destructor
//----------------------------------------------------------

// Zero-parameter constructor
Timer::Timer()
{
  //cout << "\nZero-parameter Timer constructor called." << endl;
  secondsLeft = 5;
}

// One-parameter constructor
Timer::Timer(int secondsLeft)
{
  //cout << "\nOne-parameter Timer constructor called." << endl;
  setSecondsLeft(secondsLeft);
}

// Destructor
Timer::~Timer()
{
  //cout << "\nTimer destructor called for timer [" 
  //  << getSecondsLeft() << "]." << endl;
}

//--------------------------------------------------------
// Getters
//--------------------------------------------------------

// getSecondsLeft
int Timer::getSecondsLeft() const
{
  return secondsLeft;
}

//--------------------------------------------------------
// Setters
//--------------------------------------------------------

// setSecondsLeft
void Timer::setSecondsLeft(int secondsLeft)
{
  if (secondsLeft < 0 || secondsLeft > 100)
    cout << "Error: seconds left must be between 0 and 100."
      << "  Seconds left not set." << endl;
  else
    this->secondsLeft = secondsLeft;
}

//--------------------------------------------------------
// Operator overloads
//--------------------------------------------------------

// Operator overload for +
Timer Timer::operator + (Timer other)
{
  secondsLeft = secondsLeft + other.getSecondsLeft();
  return Timer(secondsLeft);
}

// Operator overload for +
Timer Timer::operator + (int add)
{
  secondsLeft = secondsLeft + add;
  return Timer(secondsLeft);
}

// Operator overload for -
Timer Timer::operator - (int subtract)
{
  secondsLeft = secondsLeft - subtract;
  return Timer(secondsLeft);
}

// Operator overload for pre-fix ++
Timer Timer::operator ++ ()
{
  secondsLeft = secondsLeft + 1;
  return Timer(secondsLeft);
}

// Operator overload for post-fix --
Timer Timer::operator -- (int i)
{
  secondsLeft = secondsLeft - 1;
  return Timer(secondsLeft);
}

// Operator overload for << (output operator)
ostream& operator << (ostream &os, Timer t)
{
  //os << "\nOverloaded operator << called." << endl;
  os << t.secondsLeft << " seconds";
  return os;
}
