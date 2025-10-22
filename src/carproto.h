#include "vehicle.h"
#include <memory>
#include <iostream>
#include <string>

class Car : public Vehicle {
private:
    std::string model;
    std::string brand;
    double weight;
    int seats;

public:
    // Constructor
    Car(std::string m="Generic car", std::string b="Generic Brand", double w=1200.0, int s=4);
    // Copy Constructor
    Car(const Car& other);

    // Clone method
    Car* Clone() const override;

    void show() const override;

};

class CarProto : public Vehicle {
public:
    CarProto();
    Car* Clone() const override;
    void show() const override;
};
