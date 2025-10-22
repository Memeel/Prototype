#include "vanproto.h"
#include <iostream>
#include <chrono>
#include <thread>

// VanProto constructor
VanProto::VanProto()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "VanProto created using the constructor" << std::endl;
}

// VanProto Clone method
Van* VanProto::Clone() const {
    std::cout << "VanProto cloned" << std::endl;
    return new Van(); // Create a default Van object
}

// VanProto show method (optional, for completeness)
void VanProto::show() const {
    std::cout << "VanProto instance" << std::endl;
}

// Van constructor
Van::Van(std::string m, std::string b, double w, int s,
        double cargoV, double capW, bool slidingDoor):
          model(m), brand(b), weight(w), seats(s),
          cargoVolume(cargoV), capacityWeight(capW),
          has_sliding_door(slidingDoor){}

// Van copy constructor
Van::Van(const Van& other): model(other.model), brand(other.brand), weight(other.weight), seats(other.seats),
          cargoVolume(other.cargoVolume), capacityWeight(other.capacityWeight),
          has_sliding_door(other.has_sliding_door){}

// Van Clone method
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