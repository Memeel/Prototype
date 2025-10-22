#include <iostream> 
#include "vanproto.h"

Van::Van(std::string m, std::string b, double w, int s,
        double cargoV, double capW, bool slidingDoor) :  model(m), brand(b), weight(w), seats(s),
          cargoVolume(cargoV), capacityWeight(capW),
<<<<<<< HEAD
          has_sliding_door(slidingDoor) {
            std::cout << "Van object created after it took a long time." << std::endl;
          }
=======
          has_sliding_door(slidingDoor),
          heavy(std::make_shared<HeavyData>())
          {}
>>>>>>> c68819e (add heavydata)
    

Van::Van(const Van& other)
        : model(other.model), brand(other.brand), weight(  other.weight), seats(other.seats),
          cargoVolume(other.cargoVolume), capacityWeight(other.capacityWeight),
<<<<<<< HEAD
          has_sliding_door(other.has_sliding_door) {
            std::cout << "Van object copied." << std::endl;
          }  

Van* Van::Clone() const {
    std::cout << "Van object cloned instantly." << std::endl;
=======
          has_sliding_door(other.has_sliding_door),
          heavy(other.heavy) 
          {}  

Van* Van::Clone() const {
>>>>>>> c68819e (add heavydata)
    return new Van(*this);
}

void Van::show() const {
<<<<<<< HEAD
    std::cout << "Van at address: " << this << " with, Model: " << model
              << ", Brand: " << brand
              << ", Weight: " << weight << " kg"
              << ", Seats: " << seats
              << ", Cargo Volume: " << cargoVolume << " m^3"
              << ", Capacity Weight: " << capacityWeight << " kg"
              << ", Sliding Door: " << (has_sliding_door ? "Yes" : "No") << "\n";
=======
    std::cout << "Van at address: " << this << " with, Model: " << model << "\n"
              << "Brand: " << brand << "\n"
              << "Weight: " << weight << " kg\n"
              << "Seats: " << seats << "\n"
              << "Cargo Volume: " << cargoVolume << " m^3\n"
              << "Capacity Weight: " << capacityWeight << " kg\n"
              << "Sliding Door: " << (has_sliding_door ? "Yes" : "No") << "\n"
              << "HeavyData.table size: "
              << (heavy ? heavy->table->size() : 0) << "\n"
              << std::endl;
>>>>>>> c68819e (add heavydata)
}