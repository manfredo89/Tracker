//
//  SunPos.hpp
//  Tracker
//
//  Created by Manfredo di Porcia on 08/04/2021.
//

#include <time.h>
#include <math.h>
#include <iostream>
#define PI 3.1415926535897932384626433832795

struct ObsCoord_t
{
    float lat = 0;
    float lon = 0;
    unsigned int year = 0;
    unsigned int month = 0;
    unsigned int day = 0;
    unsigned int hour = 0;
    unsigned int min = 0;
    unsigned int sec = 0;
};

class SunPos
{
  private:
    
    float siderealTime;
    double declination;
    double rightAscension;
    float azimuth;
    float elevation;
    float JD; // Julian Date
            
    float eclipticLongitude (float m);
    void dateCalc ();
    void sunCoords();
    double getDeclination (float, float);
    double getRightAscension (float, float);
    float getSiderealTime (float);
    float getElevation (float, float);
    float getAzimuth (float, float);
        
public:
    
    void init(const float, const float, const int, const int, const int, const int, const int, const int);
    void calc();
    void print();
    ObsCoord_t ObsPos;

};
