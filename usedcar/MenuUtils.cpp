//
//  MenuUtils.cpp
//  usedcar
//
//  Created by Dimitris Triantis on 06/06/2021.
//

#include "MenuUtils.hpp"
#include "Utils.hpp"

using namespace menuUtils;
using namespace CarUtils;

void menuUtils::displayMenu() {
    std::cout << "***************************************\n";
    std::cout << "***************************************\n";
    std::cout << menu_option::add_car << ": Add a Car\n";
    std::cout << menu_option::sell_car << ": Sell a Car\n";
    std::cout << menu_option::display_all_cars << ": Display all listings\n";
    std::cout << menu_option::display_end_of_the_day << ": Display End of Day\n";
    std::cout << menu_option::display_menu << ": Display menu options\n";
    std::cout << menu_option::quit << ": Exit the application and quit\n";
    std::cout << "***************************************\n";
    std::cout << "***************************************\n";
}
    
auto menuUtils::get_menu()
{
    while (true)
    {
        std::cout << "Choose an option from the menu ";

        auto option = 0;
        if (std::cin >> option)
        {
            switch (option)
            {
            case 1: return menu_option::add_car;
            case 2: return menu_option::sell_car;
            case 3: return menu_option::display_all_cars;
            case 4: return menu_option::display_end_of_the_day;
            case 5: return menu_option::display_menu;
            case 6: return menu_option::quit;
            default:
                std::cout << "Invalid selection please try again.\n";
            }
        }
        else
        {
            std::cout << "Please enter a number from 1 to 6 \n";
            std::cin.clear();
            std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
        }

    }
}

bool menuUtils::menuSelection( int option, UsedCarshop::CarShop & carShop ) {

    switch( static_cast<unsigned int>(option) ) {
        case 1: {
            addUsedCar( carShop );
            std::cout << "\nYou have entered a car into the Shop.\n";
            menuUtils::displayMenu();
            break;
        }
        case 2: {
            if( carShop.numberOfCars() > 0 ) {
                sellUsedCar( carShop );
                std::cout << "\nYou have sell a car.\n";
                menuUtils::displayMenu();
            } else {
                std::cout << "\nThere are no cars in the Shop.\n";
            }
            break;
        }
        case 3: {
            std::size_t numberOfCars = carShop.numberOfCars();
            if( numberOfCars > 0 ) {
                carShop.displayCars();
            } else {
                std::cout << "\nThere is no car in the shop.\n";
            }
            break;
        }
        case 4: {
            std::size_t numberOfCars = carShop.numberOfCars();
            std::size_t numberOfCarsSold = carShop.numberOfCarsSold();
            if( numberOfCars > 0 && numberOfCarsSold > 0) {
                carShop.displayCars();
                carShop.displayCarsSold();
            } else {
                std::cout << "\nThere are no cars sold today.\n";
            }
            break;
        }
        case 5: {
            menuUtils::displayMenu();
            break;
        }
        case 6: {
            return false;
        }
        default: {
            std::cout << "\nInvalid selection please try again.\n";
            break;
        }
    }
    return true;
}
