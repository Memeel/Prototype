#include "vehicle.h"
#include <memory>
#include <iostream>
#include <string>

class Van : public Vehicle {
private:
    std::string model;
    std::string brand;
    double weight;
    int seats;
    double cargoVolume;
    double capacityWeight;
    bool has_sliding_door;

public:
    // Constructor
    Van(std::string m="Generic van", std::string b="Generic Brand", double w=3000.0, int s=2,
        double cargoV=10.0, double capW=1000.0, bool slidingDoor=false);
    // Copy Constructor
    Van(const Van& other);
    // Clone method
    Van* Clone() const override;

    void show() const override;
};

class VanProto : public Vehicle {
public:
    VanProto();
    Van* Clone() const override;
    void show() const override;
};
