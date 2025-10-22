#include <iostream>
#include "carproto.h"

Car::Car(std::string m, std::string b, double w, int s)
    : model(m), brand(b), weight(w), seats(s),  
    heavy(std::make_shared<HeavyData>())
    {}

Car::Car(const Car& other)
    : model(other.model), brand(other.brand), weight(other.weight), seats(other.seats),
    heavy(other.heavy)
    {}

Car* Car::Clone() const {
    return new Car(*this);
}
void Car::show() const {
    std::cout << "Car at address: " << this << " with, Model: " << model << "\n"
              << "Brand: " << brand << "\n"
              << "Weight: " << weight << " kg\n"
              << "Seats: " << seats << "\n"
              << "HeavyData.table size: "
              << (heavy ? heavy->table->size() : 0) << "\n"
              << std::endl;
}
