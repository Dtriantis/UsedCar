//
//  carShop.hpp
//  usedcar
//
//  Created by Dimitris Triantis on 03/06/2021.
//

#ifndef carShop_hpp
#define carShop_hpp

#include <stdio.h>
#include <string>
#include <unordered_map>

#include "car.h"

constexpr int MIN_C = 1;
constexpr int MAX_C = 10000;

namespace UsedCarshop{

class CarShop {
    typedef std::unordered_map<std::string, Car> CarsMap;
    typedef std::unordered_map<std::string, Car> SoldCarsMap;
private:
    CarsMap _cars;
    SoldCarsMap _soldCars;
public:
    void addCar ( Car car );
    void sellCar ( const std::string& id );
    
    std::optional<Car> findCar( const std::string& id ) const;
    std::size_t numberOfCars() const;
    std::size_t numberOfCarsSold() const;
    double daysEarning();
    
    void displayCars() const;
    void displayCarsSold() const;
    
};
}

#endif /* carShop_hpp */
