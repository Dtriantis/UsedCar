//
//  CarUtils.cpp
//  usedcar
//
//  Created by Dimitris Triantis on 08/06/2021.
//

#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <time.h>

#include "CarUtils.hpp"

const std::string CarUtils::currentPrice(double car_price, std::chrono::system_clock::time_point car_reg_time){
    try{
        //Compute time diff between adding on the car in shop until now
        auto time_now = std::chrono::system_clock::now();
        auto seconds = std::chrono::duration_cast<std::chrono::seconds>(time_now - car_reg_time );
        auto timeIntervalSellUntillNow = seconds.count();

        if(timeIntervalSellUntillNow > 30){
            //Compute dynamic price
            double priceThreshold = car_price - car_price*0.2;
            double dynamicPrice = car_price;
            
            while(dynamicPrice>priceThreshold && timeIntervalSellUntillNow>30){
                dynamicPrice -= dynamicPrice*0.01;
                timeIntervalSellUntillNow -= 10;
            }
            return std::to_string(dynamicPrice);
        }
        return std::to_string(car_price);
    }catch(...){
        std::cout << "Error while calculating  \n";
        return std::string();
    }
}

void CarUtils::addUsedCar( UsedCarshop::CarShop & carShop ) {
    unsigned int year = 0;
    double price = 0;
    std::string model;
    
    std::cin.ignore();
    std::cout << "Enter Car model: \n";
    while(true){
        std::getline( std::cin, model );
        if(model.size()>0){break;}
        else{
            std::cout << "Input Empty! Please provide a car model" << std::endl;
            std::cin.clear();
            while (std::cin.get() != '\n'); // empty loop
        }
    }
    std::cout << "Enter car price: \n";
    std::cin >> price;
    while (std::cin.fail() || price < 0) {
        std::cout << "Invalid Input! Please input a numerical value for car's Price." << std::endl;
        std::cin.clear();
        std::cin >> price;
    }
    std::cout << "Enter car year: \n";
    std::cin >> year;
    while (std::cin.fail() || year < 0 || year > CarUtils::getCurrentYear()) {
        std::cout << "Invalid Input! Please provide correct Input for car's Year." << std::endl;
        std::cin.clear();
        std::cin >> year;
    }
    auto registrationTimepoint = std::chrono::system_clock::now();
    const Car car = {
        model,
        year,
        price,
        registrationTimepoint
    };
    carShop.addCar( std::move(car) );
}

void CarUtils::sellUsedCar( UsedCarshop::CarShop & carShop) {
    std::size_t numCars = carShop.numberOfCars();
    if( numCars == 0 ) {
        std::cout << "\nThere are 0 cars; nothing to Sell.\n";
        return;
    }
    unsigned int id;
    std::cin.ignore();
    std::cout << "Enter Car ID you want to sell ";
    while(true){
        if(std::cin >> id && id>MIN_C && id<MAX_C){
            break;
        }else{
            std::cout << "Invalid Input! Please input a numerical value for the car you want to sell." << std::endl;
            std::cin.clear();
            while (std::cin.get() != '\n') ; // empty loop
        }
    }
    carShop.sellCar(std::move(std::to_string(id)));
}

const unsigned int CarUtils::getCurrentYear(){
    //get current Year
    time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);
    return aTime->tm_year + 1900;
}
