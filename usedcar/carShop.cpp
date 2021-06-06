//
//  carShop.cpp
//  usedcar
//
//  Created by Dimitris Triantis on 03/06/2021.
//

#include <chrono>
#include <ctime>

#include "carShop.hpp"
#include "Utils.hpp"

//using namespace CarUtils;
using namespace UsedCarshop;

void CarShop::addCar ( std::string id, Car car )
{
    //create and fill registration time and date here
//    std::chrono::system_clock::time_point p = std::chrono::system_clock::now();
//    std::time_t t = std::chrono::system_clock::to_time_t(p);
    
   // car._registrationDateTime = std::ctime(&t);
    
    //add car on Used Car map
  //  auto [ position, success ] = _cars.emplace( std::move(id), std::move(car) );
     _cars.emplace( std::move(id), std::move(car) );
//    if (!success)
//    {
//        //ID already in Car map
//    }
}

void CarShop::sellCar ( const std::string& id )
{
    //put car in Cars sold map
    //Provlhma mallon me to Auto sto find car
    auto car = findCar(id);
 //   _soldCars.emplace( std::move(id), std::move(car) );
//    auto [ position, success ] = _soldCars.emplace( std::move(id), std::move(car) );
//    if (!success)
//    {
//        //ID already in Car map
//    }
    //try - catch
    _cars.erase(id);
}

std::optional<Car> CarShop::findCar(const std::string &id) const {
    auto it = _cars.find(id);
    if(it == _cars.end()){return std::nullopt;}
    return it->second;
}

std::size_t CarShop::numberOfCars() {
    return _cars.size();
}

std::size_t CarShop::numberOfCarsSold() {
    return _soldCars.size();
}

void CarShop::displayCars() {
    for(auto&& [id, car] : _cars){
        std::cout << "Car ID: " << id << '\n' << car._model << car._year << CarUtils::currentPrice(car._price, car._registrationDateTime) <<  '\n';
    }
}
void CarShop::displayCarsSold() {
    for(auto&& [id, car] : _soldCars){
        std::cout << "Car ID: " << id << '\n' << car._model << car._year << CarUtils::currentPrice(car._price, car._registrationDateTime) <<  '\n';
    }
}

