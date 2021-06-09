//
//  MenuUtils.hpp
//  usedcar
//
//  Created by Dimitris Triantis on 06/06/2021.
//

#ifndef MenuUtils_hpp
#define MenuUtils_hpp

#include <stdio.h>
#include "carShop.hpp"
#include "CarUtils.hpp"

namespace MenuUtils {

enum menu_option {
    add_car = 1,
    sell_car,
    display_all_cars,
    display_end_of_the_day,
    display_menu,
    quit
};

void displayMenu();
bool menuSelection( int option, UsedCarshop::CarShop & carShop );
}

#endif /* MenuUtils_hpp */
