//
//  car.h
//  usedcar
//
//  Created by Dimitris Triantis on 01/06/2021.
//

#ifndef car_h
#define car_h

#include <string>
#include <iostream>

struct Car {
    std::string _model;
    unsigned int _year;
    double _price;
    std::chrono::system_clock::time_point _registrationDateTime;
};

bool operator==( const Car& first, const Car& other );
// std::ostream& operator<<( std::ostream& out, const Car& car );

#endif /* car_h */
