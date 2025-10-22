#include "car.h"
#include <iostream>
#include <chrono>
#include <thread>

// Car constructor (SLOW)
Car::Car(std::string m, std::string b, double w, int s)
    : model(m), brand(b), weight(w), seats(s) {
    // Simulate expensive resource loading
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "Car created using the constructor (SLOW)" << std::endl;
}

// Car copy constructor (FAST)
Car::Car(const Car& other)
    : model(other.model), brand(other.brand), weight(other.weight), seats(other.seats) {
    // Copying is fast, no sleep
    std::cout << "Car created using the copy constructor (FAST)" << std::endl;
}

// Car Clone method (FAST)
Car* Car::Clone() const {
    return new Car(*this);
}

// Car show method
void Car::show() const {
    std::cout << "Car at address: " << this << " with, Model: " << model << "\n"
              << "Brand: " << brand << "\n"
              << "Weight: " << weight << " kg\n"
              << "Seats: " << seats << "\n"
              << std::endl;
}