#include "carproto.h"
#include <iostream>
#include <chrono>
#include <thread>

// CarProto constructor
CarProto::CarProto()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "CarProto created using the constructor" << std::endl;
}

// CarProto Clone method
Car* CarProto::Clone() const {
    std::cout << "CarProto cloned" << std::endl;
    return new Car(); // Create a default Car object
}

// CarProto show method (optional, for completeness)
void CarProto::show() const {
    std::cout << "CarProto instance" << std::endl;
}

// Car constructor
Car::Car(std::string m, std::string b, double w, int s):
          model(m), brand(b), weight(w), seats(s){}

// Car copy constructor
Car::Car(const Car& other): model(other.model), brand(other.brand), weight(other.weight), seats(other.seats){}

// Car Clone method
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
