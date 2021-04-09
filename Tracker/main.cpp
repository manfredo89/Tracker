//
//  main.cpp
//  Tracker
//
//  Created by Manfredo di Porcia on 07/04/2021.
//

#include <iostream>
#include "SunPos.hpp"


int main(int argc, const char * argv[]) {
    // insert code here...
    float Lat, Lon;
    int Year, Month, Day, Hour, Min, Sec;
    std::cout << "Enter observer Lat" << std::endl;
    std::cin >> Lat;
    std::cout << "Enter observer Lon" << std::endl;
    std::cin >> Lon;
    std::cout << "Enter observer Year" << std::endl;
    std::cin >> Year;
    std::cout << "Enter observer Month" << std::endl;
    std::cin >> Month;
    std::cout << "Enter observer Day" << std::endl;
    std::cin >> Day;
    std::cout << "Enter observer Hour (Universal time) " << std::endl;
    std::cin >> Hour;
    std::cout << "Enter observer Min" << std::endl;
    std::cin >> Min;
    std::cout << "Enter observer Sec" << std::endl;
    std::cin >> Sec;
    
    //Lat = 41.5; Lon=12.3; Year=2021; Month=4; Day=9; Hour=10; Min=30; Sec=0;
    
    SunPos mySunPos;
    mySunPos.init(Lat, Lon, Year, Month, Day, Hour, Min, Sec);
    mySunPos.calc();
    mySunPos.print();
    return 0;
}
