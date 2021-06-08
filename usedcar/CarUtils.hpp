//
//  CarUtils.hpp
//  usedcar
//
//  Created by Dimitris Triantis on 08/06/2021.
//

#ifndef CarUtils_hpp
#define CarUtils_hpp

#include <stdio.h>
#include <string>
#include <chrono>

#include "carShop.hpp"

namespace CarUtils{

const std::string currentPrice(double car_price,std::chrono::system_clock::time_point car_reg_time);

void addUsedCar( UsedCarshop::CarShop & carShop );
void sellUsedCar( UsedCarshop::CarShop & carShop );
const unsigned int getCurrentYear();

}
#endif /* CarUtils_hpp */
