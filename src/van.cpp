#include "van.h"
#include <iostream>
#include <chrono>
#include <thread>

// Van constructor (SLOW)
Van::Van(std::string m, std::string b, double w, int s,
         double cargoV, double capW, bool slidingDoor)
    : model(m), brand(b), weight(w), seats(s),
      cargoVolume(cargoV), capacityWeight(capW),
      has_sliding_door(slidingDoor) {
    // Simulate expensive resource loading
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "Van created using the constructor (SLOW)" << std::endl;
}

// Van copy constructor (FAST)
Van::Van(const Van& other)
    : model(other.model), brand(other.brand), weight(other.weight), seats(other.seats),
      cargoVolume(other.cargoVolume), capacityWeight(other.capacityWeight),
      has_sliding_door(other.has_sliding_door) {
    // Copying is fast
    std::cout << "Van created using the copy constructor (FAST)" << std::endl;
}

// Van Clone method (FAST)
Van* Van::Clone() const {
    return new Van(*this);
}

// Van show method
void Van::show() const {
    std::cout << "Van at address: " << this << " with, Model: " << model << "\n"
              << "Brand: " << brand << "\n"
              << "Weight: " << weight << " kg\n"
              << "Seats: " << seats << "\n"
              << "Cargo Volume: " << cargoVolume << " m^3\n"
              << "Capacity Weight: " << capacityWeight << " kg\n"
              << "Sliding Door: " << (has_sliding_door ? "Yes" : "No") << "\n"
              << std::endl;
}