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
    try{
        //Compute time diff between adding on the car in shop until now
        auto time_now = std::chrono::system_clock::now();
        auto seconds = std::chrono::duration_cast<std::chrono::seconds>(time_now - car_reg_time );
        auto timeIntervalSellUntillNow = seconds.count();
        
        //Compute dynamic price
        double priceThreshold = car_price - car_price*0.2;
        double dynamicPrice = car_price;
        
        while(dynamicPrice>priceThreshold && timeIntervalSellUntillNow>0){
            dynamicPrice -= dynamicPrice*0.01;
            timeIntervalSellUntillNow -= 10;
        }
        return std::to_string(dynamicPrice);

    }catch(...){
        std::cout << "Error while calculating  \n";
        return std::string();;
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
            while (std::cin.get() != '\n') ; // empty loop
        }
    }

    std::cout << "Enter car price: \n";
    while (true) {
      if (std::cin >> price && price > 0) {
          // valid price
          break;
      } else {
          // not valid price
          std::cout << "Invalid Input! Please input a numerical value for car's Price." << std::endl;
          std::cin.clear();
          while (std::cin.get() != '\n') ; // empty loop
      }
    }

    std::cout << "Enter the car year: \n";
    while (true) {
      if (std::cin >> year && year > 0) {
          // valid year
          break;
      } else {
          // not valid year
          std::cout << "Invalid Input! Please input a numerical value for car's Year." << std::endl;
          std::cin.clear();
          while (std::cin.get() != '\n') ; // empty loop
      }
    }
    
    auto registrationTimepoint = std::chrono::system_clock::now();
    if(model.size()!=0){
        Car car = {
            model,
            year,
            price,
            registrationTimepoint
        };
        carShop.addCar( std::move(car) );
    }else{
        std::cout << "You missed to give all info please try adding the car again ";
    }
}

void CarUtils::sellUsedCar( UsedCarshop::CarShop & carShop) {
    std::size_t numCars = carShop.numberOfCars();
    if( numCars == 0 ) {
        std::cout << "\nThere are 0 cars; nothing to Sell.\n";
        return;
    }
    std::string id;
    std::cin.ignore();
    std::cout << "Enter Car ID you want to sell ";
    std::getline( std::cin, id );
    carShop.sellCar(std::move(id));
    std::cout << "Car Sold";
}
