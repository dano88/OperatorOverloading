//==========================================================
//
// Title: Operator overloading - Timer - Header
// Description:
//   This C++ header defines the function prototypes 
// implemented in file 
// OperatorOverloading-Timer-Implementation.cpp.
// This is developer 2 making a change ...
//
//==========================================================
#ifndef TimerFlag
#define TimerFlag
#include <cstdlib>  // For several general-purpose functions
#include <fstream>  // For file handling
#include <iomanip>  // For formatted output
#include <iostream>  // For cin, cout, and system
#include <string>  // For string data type
#include <vector>  // For vectors
using namespace std;  // So "std::cout" may be abbreviated to "cout", for example.

//----------------------------------------------------------
// Timer class
//----------------------------------------------------------
class Timer
{

  //--------------------------------------------------------
  // Private members
  //--------------------------------------------------------
  private:

    //------------------------------------------------------
    // Fields
    //------------------------------------------------------
    int secondsLeft = 10;
    
  //--------------------------------------------------------
  // Public members
  //--------------------------------------------------------
  public:

    //------------------------------------------------------
    // Constructor and destructor prototypes
    //------------------------------------------------------

    Timer();
    Timer(int secondsLeft);
    ~Timer();

    //------------------------------------------------------
    // Getter prototypes
    //------------------------------------------------------
    int getSecondsLeft() const;

    //------------------------------------------------------
    // Setter prototypes
    //------------------------------------------------------
    void setSecondsLeft(int secondsLeft);

    //--------------------------------------------------------
    // Operator overload prototypes
    //--------------------------------------------------------

    Timer operator + (Timer other);
    Timer operator + (int add);
    Timer operator - (int subtract);
    Timer operator ++ ();  // Prefix operator
    Timer operator -- (int i);  // Postfix operator
    friend ostream& operator <<
      (ostream &outStream, Timer t);

};

#endif
