#include <iostream> 
#include "vanproto.h"

Van::Van(std::string m, std::string b, double w, int s,
        double cargoV, double capW, bool slidingDoor) :  model(m), brand(b), weight(w), seats(s),
          cargoVolume(cargoV), capacityWeight(capW),
          has_sliding_door(slidingDoor) {}
    

Van::Van(const Van& other)
        : model(other.model), brand(other.brand), weight(  other.weight), seats(other.seats),
          cargoVolume(other.cargoVolume), capacityWeight(other.capacityWeight),
          has_sliding_door(other.has_sliding_door) {}  

Van* Van::Clone() const {
    return new Van(this->model, this->brand, this->weight, this->seats,
                   this->cargoVolume, this->capacityWeight, this->has_sliding_door);
}

void Van::show() const {
    std::cout << "Van at address: " << this << " with, Model: " << model << "\n"
              << "Brand: " << brand << "\n"
              << "Weight: " << weight << " kg\n"
              << "Seats: " << seats << "\n"
              << "Cargo Volume: " << cargoVolume << " m^3\n"
              << "Capacity Weight: " << capacityWeight << " kg\n"
              << "Sliding Door: " << (has_sliding_door ? "Yes" : "No") << "\n";
}