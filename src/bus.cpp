#include "bus.h"
#include <iostream>
#include <chrono>
#include <thread>

// Bus constructor (SLOW)
Bus::Bus(std::string m, std::string b, double w, int s,
         int maxP, std::string company, bool wifi, bool toilet)
    : model(m), brand(b), weight(w), seats(s),
      maxPassengers(maxP), TransitCompany(company),
      has_wifi(wifi), has_toilet(toilet) {
    // Simulate expensive resource loading
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "Bus created using the default constructor (SLOW)" << std::endl;
}

// Bus copy constructor (FAST)
Bus::Bus(const Bus& other)
    : model(other.model), brand(other.brand), weight(other.weight), seats(other.seats),
      maxPassengers(other.maxPassengers), TransitCompany(other.TransitCompany),
      has_wifi(other.has_wifi), has_toilet(other.has_toilet) {
    // Copying is fast
    std::cout << "Bus created using the copy constructor (FAST)" << std::endl;
}

// Bus Clone method (FAST)
Bus* Bus::Clone() const {
    return new Bus(*this);
}

// Bus show method
void Bus::show() const {
    std::cout << "Bus at address: " << this << " with, Model: " << model << "\n"
              << "Brand: " << brand << "\n"
              << "Weight: " << weight << " kg\n"
              << "Seats: " << seats << "\n"
              << "Max Passengers: " << maxPassengers << "\n"
              << "Transit Company: " << TransitCompany << "\n"
              << "WiFi: " << (has_wifi ? "Yes" : "No") << "\n"
              << "Toilet: " << (has_toilet ? "Yes" : "No") << "\n"
              << std::endl;
}