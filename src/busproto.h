#include "vehicle.h"
#include <memory>
#include <iostream>
#include <string>

class Bus : public Vehicle {
private:
    std::string model;
    std::string brand;
    double weight;
    int seats;
    int maxPassengers;
    std::string TransitCompany;
    bool has_wifi;
    bool has_toilet;

public:
    // Constructor
    Bus(std::string m="Generic bus", std::string b="Generic Brand", double w=8000.0, int s=40,
        int maxP=50, std::string company="Generic Transit", bool wifi=false, bool toilet=false);

    // Copy Constructor
    Bus(const Bus& other);

    // Clone method
    Bus* Clone() const override;

    void show() const override;
};

class BusProto : public Vehicle {
public:
    BusProto();
    Bus* Clone() const override;
    void show() const override;
};