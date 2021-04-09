//
//  SunPos.cpp
//  Tracker
//
//  Created by Manfredo di Porcia on 08/04/2021.
//

#include "SunPos.hpp"

// Constructor
void SunPos::init(const float Lat, const float Lon, const int Year, const int Month, const int Day, int const Hour, const int Min, const int Sec){
    ObsPos.lat = Lat;
    ObsPos.lon = Lon;
    ObsPos.year = Year;
    ObsPos.month = Month;
    ObsPos.day = Day;
    ObsPos.hour = Hour;
    ObsPos.min = Min;
    ObsPos.sec = Sec;
}

void SunPos::calc(){
    
    float lw  = (PI / 180) * -ObsPos.lon;
    float phi = (PI / 180) * ObsPos.lat;

    dateCalc();
    sunCoords();
    
    float hm = getSiderealTime(lw) - this->rightAscension;
    
    this->elevation = getElevation(hm, phi);
    this->azimuth = PI + getAzimuth(hm, phi);
}


void SunPos::dateCalc(){
    
    unsigned int y = ObsPos.year;
    unsigned int m = ObsPos.month;
    unsigned int d = ObsPos.day;
    float hour = (float) ObsPos.hour;
    float min = (float) ObsPos.min;
    float sec = (float) ObsPos.sec;
    
    if (m <= 2) {
        y--;
        m += 12;
    }
    int A = y / 100;
    int B = A / 4;
    int C = 2 - A + B;
    int E = 365.25 * (y + 4716);
    int F = 30.6001 * (m + 1);
    this->JD = C + d + E + F - 1524 - 2451545 + (hour - 12) / 24 + min / 1440 + sec / 86400;
}

void SunPos::sunCoords (){
  
    float solarMeanAnomaly = (PI / 180) * (357.5291 + 0.98560028 * this->JD);
    float l = eclipticLongitude(solarMeanAnomaly);
    this->declination = getDeclination(l, 0);
    this->rightAscension = getRightAscension (l,0);
}

float SunPos::eclipticLongitude (float m) {
  
    //equation of center
    float C = (PI / 180) * (1.9148 * sin(m) + 0.02 * sin(2 * m) + 0.0003 * sin(3 * m));
    //perihelion of the Earth
    float P = (PI / 180) * 102.9372;
  
    return(m + C + P + PI);
}


double SunPos::getRightAscension (float l, float b) {
    float e = (PI / 180) * 23.4397;
    return atan2(sin(l) * cos(e) - tan(b) * sin(e), cos(l));
}


double SunPos::getDeclination (float l, float b) {
    float e = (PI / 180) * 23.4397;
    return asin(sin(b) * cos(e) + cos(b) * sin(e) * sin(l));
}

float SunPos::getSiderealTime (float lw) {
    return (PI / 180) * (280.16 + 360.9856235 * this->JD) - lw;
}

float SunPos::getAzimuth (float hm, float phi) {
    return atan2(sin(hm), cos(hm) * sin(phi) - tan(this->declination) * cos(phi));
}


float SunPos::getElevation (float hm, float phi) {
    
    return asin(sin(phi) * sin(this->declination) + cos(phi) * cos(this->declination) * cos(hm));
}

void SunPos::print(){
    std::cout << "Azimuth = " << this->azimuth * 180 / PI << std::endl;
    std::cout << "Elevation = " << this->elevation * 180 / PI << std::endl;
}
