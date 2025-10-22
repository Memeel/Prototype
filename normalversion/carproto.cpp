#include <iostream>
#include "carproto.h"

Car::Car(std::string m, std::string b, double w, int s)
<<<<<<< HEAD
    : model(m), brand(b), weight(w), seats(s) {
        std::cout << "Car object created after it took a long time." << std::endl;
    }

Car::Car(const Car& other)
    : model(other.model), brand(other.brand), weight(other.weight), seats(other.seats) {
        std::cout << "Car object copied." << std::endl;
    }

Car* Car::Clone() const {
    std::cout << "Car object cloned instantly." << std::endl;
    return new Car(*this);
}
void Car::show() const {
    std::cout << "Car at address: " << this << " with, Model: " << model
              << ", Brand: " << brand
              << ", Weight: " << weight << " kg"
              << ", Seats: " << seats << "\n";
=======
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
>>>>>>> c68819e (add heavydata)
}
