/*
 -------------------------------------------------------------------------------
 NMEAGPS.cpp
 NMEAGPS Project
 
 Initially created by Rowland O'Flaherty (___WEBSITE___) on 5/28/12.
 
 Version 1.0
 -------------------------------------------------------------------------------
 */

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "NMEAGPS.h"

//------------------------------------------------------------------------------
// Friends
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Friend Overloaded Operators
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Lifecycle
//------------------------------------------------------------------------------
// Constructors
NMEAGPS::NMEAGPS()
:
_prop1(0),
_prop2 {
    
}


// Destructor
NMEAGPS::~NMEAGPS() {
    
}

// Copy constructor
NMEAGPS::NMEAGPS(const NMEAGPS& srcObj) {
    copyHelper(srcObj);
}

// Assignment operator
const NMEAGPS& NMEAGPS::operator=(const NMEAGPS& rhsObj) {
	// Self-assignment check
    if (this == &rhsObj) {
        return (*this);
    }
    
    // Free old memory
    
    // Copy new memory
    copyHelper(rhsObj);
    
    return (*this);
}

// Copy helper function
void NMEAGPS::copyHelper(const NMEAGPS& srcObj) {
    
}

//------------------------------------------------------------------------------
// Overloaded Operators
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Public Member Functions
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Protected Member Functions
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Private Member Functions
//------------------------------------------------------------------------------

