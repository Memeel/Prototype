#include <iostream>
#include "carproto.h"

Car::Car(std::string m, std::string b, double w, int s)
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
}
