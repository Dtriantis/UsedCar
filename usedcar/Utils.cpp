//
//  Utils.cpp
//  usedcar
//
//  Created by Dimitris Triantis on 04/06/2021.
//

#include <iostream>
#include <string>
#include <chrono>
#include <ctime>

#include "Utils.hpp"

using namespace CarUtils;

std::string CarUtils::currentPrice(double car_price, std::chrono::system_clock::time_point car_reg_time){

    //Compute time diff between adding on the car in shop until now
    auto time_now = std::chrono::system_clock::now();
    auto seconds = std::chrono::duration_cast<std::chrono::seconds>(car_reg_time - time_now);
    auto timeIntervalSellUntillNow = seconds.count();
    
    //Compute dynamic price
    double priceThreshold = car_price - car_price*0.8;
    double dynamicPrice = car_price;
    
    while(dynamicPrice<priceThreshold && timeIntervalSellUntillNow>0){
        dynamicPrice -= dynamicPrice*0.99;
        timeIntervalSellUntillNow-=10;
    }
    return std::to_string(dynamicPrice);
}

void CarUtils::addUsedCar( UsedCarshop::CarShop & carShop ) {
    unsigned int year = 0;
    double price = 0;
    std::string model, carID;

    std::cin.ignore();

    std::cout << "Enter car ID: ";
    std::getline( std::cin, carID );

    std::cout << "Enter Car model: ";
    std::getline( std::cin, model );

    std::cout << "Enter car price: ";
    std::cin >> price;

    std::cout << "Enter the car year: ";
    std::cin >> year;
    
    auto registrationTimepoint = std::chrono::system_clock::now();
    if(year!=0 && price!=0 && model.size()!=0 && carID.size()!=0){
        Car car = {
            model,
            year,
            price,
            registrationTimepoint
        };
        carShop.addCar( std::move(carID), std::move(car)  );
    }else{
        std::cout << "You missed to give all info please try adding the car again ";
    }

}

void CarUtils::sellUsedCar( UsedCarshop::CarShop & carShop) {
    std::size_t numCars = carShop.numberOfCars();
    if( numCars == 0 ) {
        std::cout << "\nThere are 0 cars; nothing to remove.\n";
        return;
    }
    std::string id;

    std::cin.ignore();
    std::cout << "Enter Car ID you want to sell ";
    std::getline( std::cin, id );
    carShop.sellCar(std::move(id));
    std::cout << "Car Sold";
}

void displayCars( UsedCarshop::CarShop & carShop ) {
    std::size_t numCars = carShop.numberOfCars();
    if( numCars == 0 ) {
        std::cout << "\nThere are 0 cars in Shop\n";
        return;
    }else{
        return;
    }

}
