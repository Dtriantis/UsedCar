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

namespace UsedCarshop{

    class CarShop {
        typedef std::unordered_map<std::string, Car> CarsMap;
        typedef std::unordered_map<std::string, Car> SoldCarsMap;
    private:
        CarsMap _cars;
        SoldCarsMap _soldCars;
    public:
        void addCar ( std::string id, Car car );
        void sellCar ( const std::string& id );

        std::optional<Car> findCar( const std::string& id ) const;
        std::size_t numberOfCars();
        std::size_t numberOfCarsSold();
        void displayCars();
        void displayCarsSold();

    };
}

#endif /* carShop_hpp */
