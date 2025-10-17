#include <iostream>
#include "carproto.h"

Car::Car(std::string m, std::string b, double w, int s)
    : model(m), brand(b), weight(w), seats(s) {}

Car::Car(const Car& other)
    : model(other.model), brand(other.brand), weight(other.weight), seats(other.seats) {}

Car* Car::Clone() const {
    return new Car(this->model, this->brand, this->weight, this->seats);
}
void Car::show() const {
    std::cout << "Car at address: " << this << " with, Model: " << model << "\n"
              << "Brand: " << brand << "\n"
              << "Weight: " << weight << " kg\n"
              << "Seats: " << seats << "\n";
}
