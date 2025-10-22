#ifndef CAR_H
#define CAR_H

#include "vehicle.h"
#include <string>

class Car : public Vehicle {
private:
    std::string model;
    std::string brand;
    double weight;
    int seats;

public:
    // Constructor (simulates expensive, slow creation)
    Car(std::string m = "Generic car", std::string b = "Generic Brand", double w = 1200.0, int s = 4);

    // Copy Constructor (fast, for cloning)
    Car(const Car& other);

    // Clone method implementation
    Car* Clone() const override;

    void show() const override;
};

#endif // CAR_H