#include <iostream> 
#include "vanproto.h"

Van::Van(std::string m, std::string b, double w, int s,
        double cargoV, double capW, bool slidingDoor) :  model(m), brand(b), weight(w), seats(s),
          cargoVolume(cargoV), capacityWeight(capW),
          has_sliding_door(slidingDoor) {
            std::cout << "Van object created after it took a long time." << std::endl;
          }
    

Van::Van(const Van& other)
        : model(other.model), brand(other.brand), weight(  other.weight), seats(other.seats),
          cargoVolume(other.cargoVolume), capacityWeight(other.capacityWeight),
          has_sliding_door(other.has_sliding_door) {
            std::cout << "Van object copied." << std::endl;
          }  

Van* Van::Clone() const {
    std::cout << "Van object cloned instantly." << std::endl;
    return new Van(*this);
}

void Van::show() const {
    std::cout << "Van at address: " << this << " with, Model: " << model
              << ", Brand: " << brand
              << ", Weight: " << weight << " kg"
              << ", Seats: " << seats
              << ", Cargo Volume: " << cargoVolume << " m^3"
              << ", Capacity Weight: " << capacityWeight << " kg"
              << ", Sliding Door: " << (has_sliding_door ? "Yes" : "No") << "\n";
}