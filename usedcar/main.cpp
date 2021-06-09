//
//  main.cpp
//  usedcar
//
//  Created by Dimitris Triantis on 04/06/2021.
//

#include <iostream>
#include "carShop.hpp"
#include "MenuUtils.hpp"
#include "CarUtils.hpp"

using namespace CarUtils;
using namespace UsedCarshop;
using namespace MenuUtils;

int main( int argc, const char * argv[] ) {
    
    UsedCarshop::CarShop carshop;
    std::cout << "Hello, Welcome to Used Cars !\n";
    MenuUtils::displayMenu();
    
    int option = 0;
    do {
        std::cout << "\nChoose an option from the menu ";
        std::cin >> option;
        if( std::cin.fail() ) {
            std::cout << "\nPlease enter an integer\n";
            std::cin.clear();
            std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
        }
        std::cout << '\n';
    } while( menuSelection( option, carshop ) );
    return 0;
}
