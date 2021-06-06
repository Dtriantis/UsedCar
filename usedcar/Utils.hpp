//
//  Utils.hpp
//  usedcar
//
//  Created by Dimitris Triantis on 04/06/2021.
//

#ifndef Utils_hpp
#define Utils_hpp

#include <stdio.h>
#include <string>
#include <chrono>

#include "carShop.hpp"

namespace CarUtils{

std::string currentPrice(double car_price,std::chrono::system_clock::time_point car_reg_time);

void addUsedCar( UsedCarshop::CarShop & carShop );
void sellUsedCar( UsedCarshop::CarShop & carShop );
void displayCars( UsedCarshop::CarShop & carShop );


}
#endif /* Utils_hpp */
