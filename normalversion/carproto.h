#include "vehicle.h"
#include "HeavyData.h"
#include <memory>
#include <iostream>
#include <string>

class Car : public Vehicle {
private:
    std::string model;
    std::string brand;
    double weight;
    int seats;

    std::shared_ptr<const HeavyData> heavy;

public:
    // Constructor
    Car(std::string m="Generic car", std::string b="Generic Brand", double w=1200.0, int s=4);
    // Copy Constructor
    Car(const Car& other);

    // Clone method
    Car* Clone() const override;

    void show() const override;
    
};
