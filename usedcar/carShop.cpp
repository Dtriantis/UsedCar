//
//  carShop.cpp
//  usedcar
//
//  Created by Dimitris Triantis on 03/06/2021.
//

#include <chrono>
#include <ctime>
#include <iomanip>
#include <random>

#include "carShop.hpp"
#include "CarUtils.hpp"

//using namespace CarUtils;
using namespace UsedCarshop;

void CarShop::addCar ( Car car )
{
    std::string id;
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<int> distr(MIN_C, MAX_C);
    //create an Id in MIN - MAX range which does not exist on _cars or _soldCars
    do {
        id = std::to_string( distr(eng) );
    } while ( _cars.count(id)<0 && _soldCars.count(id)<0 );
    
    //add car on Used Car map
    auto [ position, success ] = _cars.try_emplace( std::move(id), std::move(car) );
    if (!success)
    {
        std::cout << "Unable to add car\n";
    }else{
        std::cout << "You have successfully entered Car in the Shop \n";
    }
}

void CarShop::sellCar ( const std::string& id )
{
    //find car in _cars
    if ( _cars.find(id) == _cars.end() ) {
        std::cout << "Unable to find the car you want to sell\n";
    } else {
        try{
            auto car = findCar(id);
            auto it = _cars.find(id);
            //update the price with the price sold
            it->second._price = std::stod(CarUtils::currentPrice(it->second._price, it->second._registrationDateTime));
            //insert the car into sold cars map
            _soldCars.try_emplace(std::move(id), std::move(it->second));
            //remove car from inventory
            _cars.erase(id);
            std::cout << "Car with ID: " << id << " is Sold \n";
        }catch(...){
            std::cout << "Error while trying to sell Car\n";
        }
    }
}

std::optional<Car> CarShop::findCar(const std::string &id) const {
    auto it = _cars.find(id);
    if(it == _cars.end()){return std::nullopt;}
    return it->second;
}

double CarShop::daysEarning() {
    double sum = 0;
    try{
        for (auto it = _soldCars.begin(); it != _soldCars.end(); it++ )
        {
            sum += it->second._price;
        }
    }
    catch(...){
        std::cout << "Error while calculating earnings\n";
    }
    return sum;
}

std::size_t CarShop::numberOfCars() {
    return _cars.size();
}

std::size_t CarShop::numberOfCarsSold() {
    return _soldCars.size();
}

void CarShop::displayCars() {
    for(auto&& [id, car] : _cars){
        std::cout << "Car ID: " << id << '\n' << car._model << '\n' <<  car._year << '\n' <<  CarUtils::currentPrice(car._price, car._registrationDateTime) <<  '\n';
    }
}
void CarShop::displayCarsSold() {
    for(auto&& [id, car] : _soldCars){
        std::cout << "Car ID: " << id << '\n' << car._model << '\n' <<  car._year << '\n' <<  car._price <<  '\n';
    }
}
