//
//  MenuUtils.cpp
//  usedcar
//
//  Created by Dimitris Triantis on 06/06/2021.
//

#include "MenuUtils.hpp"

void MenuUtils::displayMenu() {
    std::cout << "***************************************\n";
    std::cout << menu_option::add_car << ": Add a Car\n";
    std::cout << menu_option::sell_car << ": Sell a Car\n";
    std::cout << menu_option::display_all_cars << ": Display all listings\n";
    std::cout << menu_option::display_end_of_the_day << ": Display End of Day\n";
    std::cout << menu_option::display_menu << ": Display menu options\n";
    std::cout << menu_option::quit << ": Exit the application and quit\n";
    std::cout << "***************************************\n";
}

bool MenuUtils::menuSelection( int option, UsedCarshop::CarShop & carShop ) {
    
    switch( option ) {
        case menu_option::add_car: {
            CarUtils::addUsedCar( carShop );
            MenuUtils::displayMenu();
            break;
        }
        case menu_option::sell_car: {
            if( carShop.numberOfCars() > 0 ) {
                CarUtils::sellUsedCar( carShop );
                MenuUtils::displayMenu();
            } else {
                std::cout << "\nThere are no cars in the Shop.\n";
            }
            break;
        }
        case menu_option::display_all_cars: {
            if( carShop.numberOfCars() > 0 ) {
                carShop.displayCars();
            } else {
                std::cout << "\nThere is no car in the shop.\n";
            }
            break;
        }
        case menu_option::display_end_of_the_day: {
            if( carShop.numberOfCarsSold() > 0) {
                std::cout << "Cars sold today.\n";
                carShop.displayCarsSold();
                std::cout << "Income earned today: \n" << carShop.daysEarning() << "\n";
            } else {
                std::cout << "\nThere are no cars sold today.\n";
            }
            break;
        }
        case menu_option::display_menu: {
            MenuUtils::displayMenu();
            break;
        }
        case menu_option::quit: {
            return false;
        }
        default: {
            std::cout << "\nInvalid selection please try again.\n";
            break;
        }
    }
    return true;
}
