//
//  car.cpp
//  usedcar
//
//  Created by Dimitris Triantis on 02/06/2021.
//

#include <stdio.h>
#include "car.h"

bool operator==( const Car& first, const Car& other ) {
    return std::tie(first._model, first._price, first._year) ==
           std::tie(other._model, other._price, other._year);
}

