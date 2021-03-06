/*
 -------------------------------------------------------------------------------
 NMEAGPS.h
 NMEAGPS Project
 
 CLASS NAME:
    NMEAGPS
 
 DESCRIPTION:
    This class is used to read and parse NMEA GPS data streams.
 
 FILES:
    NMEAGPS.h
    NMEAGPS.cpp

 DEPENDENCIES:
    Arudino.h
    SoftwareSerial.h
 
 CONSTRUCTORS:
    NMEAGPS();    
 
 PUBLIC PROPERTIES:
    prop1 - description... .

    prop2 - description... .
 
 PUBLIC METHODS:
    type method1(type arg1);
        Description... .
            arg1 - description... .
 
 NOTES:
 
 
 EXAMPLES:
    Example 1: description
    ----------------------------------------------------------------------------
    code...
    ----------------------------------------------------------------------------
 
 
 VERSIONS:
    1.0 - 5/28/12 - Rowland O'Flaherty (rowlandoflaherty.com)
 
 -------------------------------------------------------------------------------
 */

#ifndef _NMEAGPS_h_
#define _NMEAGPS_h_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <Arduino.h>
#include <SoftwareSerial.h>
#include <math.h>


class NMEAGPS {

    
public:
    //--------------------------------------------------------------------------
    // Constants, Enums, and Types
    //--------------------------------------------------------------------------
	
    
    //--------------------------------------------------------------------------
    // Lifecycle
    //--------------------------------------------------------------------------
    // Constructors
    NMEAGPS(byte rxPin = 2, byte txPin = 3, long baud = 9600); // Arduino Rx (GPS Tx), Arduino Tx (GPS Rx)
    NMEAGPS(const SoftwareSerial& gpsSerial);
    
    // Destructor
    virtual ~NMEAGPS();
    
    // Copy constructor
    NMEAGPS(const NMEAGPS& srcObj);
    
    // Assignment operator
    const NMEAGPS& operator=(const NMEAGPS& rhsObj);
    
    
    //--------------------------------------------------------------------------
    // Overloaded Operators
    //--------------------------------------------------------------------------
    
    
    //--------------------------------------------------------------------------
    // Public Member Functions
    //--------------------------------------------------------------------------
    void initialize();
    bool update();
    bool isListening();
    void listen();
    int available();
    bool overflow();
    
    // Getters
    bool valid() {return _valid;};
    int year() {return _year;}
    int month() {return _month;}
    int day() {return _day;}
    int hour() {return _hour;}
    int minute() {return _min;}
    float second() {return _sec;}
    float latitude() {return _lat;}
    float longitude() {return _lon;}
    float altitude() {return _alt;}
    char altUnits() {return _altUnits;}
    float speed() {return _speed;}
    float course() {return _course;}
    float geoid() {return _geoid;}
    char geoidUnits() {return _geoidUnits;}
    int numberOfSats() {return _nSats;}
    float PDOP() {return _PDOP;}
    float HDOP() {return _HDOP;}
    float VDOP() {return _VDOP;}
    
    // Static
    static float distanceBetween(float lat1, float lon1, float lat2, float lon2, float unitsPerMeter = 0.001);
    
private:
    //--------------------------------------------------------------------------
    // Constants, Enums, and Types
    //--------------------------------------------------------------------------
    
    
    //--------------------------------------------------------------------------
    // Lifecycle
    //--------------------------------------------------------------------------
    void copyHelper(const NMEAGPS& srcObj);
    
    //--------------------------------------------------------------------------
    // Private Member Functions
    //--------------------------------------------------------------------------
    bool readGPSStream();
    void parseBuffer();
    bool parseMsg(String &msg, String msgParts[], int nParts);
    int stoi(const String &str);
    float stof(const String &str);
    void parseGPGGA(String &msg);
    // void parseGPGSA(String &msg); // Still need to implement
    // void parseGPGSV(String &msg); // Still need to implement
    void parseGPRMC(String &msg);
    
    //--------------------------------------------------------------------------
    // Private Member Variables
    //--------------------------------------------------------------------------
    byte _rxPin; // Receive pin
    byte _txPin; // Transmit pin
    long _baud; // BAUD rate
    
    SoftwareSerial _gpsSerial; // Softserial object for GPS 
    String _buffer; // Receive data buffer
    
    bool _valid; // Valid message flag
    
    // GPS Data
    int _year;
    byte _month;
    byte _day;
    byte _hour; // UTC time hour (0 to 23)
    byte _min; // UTC time min (0 to 59)
    float _sec; // UTC time sec (0 to 59)
    
    float _lat; // Latitude in deg (-90 to 90)
    float _lon; // Latitude in deg (-180 to 180)
    
    float _alt; // MSL altitute
    char _altUnits; // Units for altitute measurement
    float _geoid; // Geoid separation
    char _geoidUnits; // Units for geoid
    
    float _speed; // Ground speed in knots
    float _course; // Course over ground in degree from true north
    
    char _magVar; // Magnetic variation E or W
    
    byte _nSats; // Number of satellites used (0 to 12)
    
    float _PDOP; // Position dilution of precision
    float _HDOP; // Horizontal dilution of precision 
    float _VDOP; // Horizontal dilution of precision
    
    bool _status; // Valid data flag
    char _mode; // Mode of operation
    
    
};

#endif