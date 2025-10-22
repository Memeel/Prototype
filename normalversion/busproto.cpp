#include "busproto.h"
#include <iostream>

Bus::Bus(std::string m, std::string b, double w, int s,
        int maxP, std::string company, bool wifi, bool toilet)
        : model(m), brand(b), weight(w), seats(s),
          maxPassengers(maxP), TransitCompany(company),
<<<<<<< HEAD
          has_wifi(wifi), has_toilet(toilet) {
            std::cout << "Bus object created after it took a long time." << std::endl;
          }
=======
          has_wifi(wifi), has_toilet(toilet), 
          heavy(std::make_shared<HeavyData>())
          {}
>>>>>>> c68819e (add heavydata)

Bus::Bus(const Bus& other)
    : model(other.model), brand(other.brand), weight(other.weight), seats(other.seats),
      maxPassengers(other.maxPassengers), TransitCompany(other.TransitCompany),
<<<<<<< HEAD
      has_wifi(other.has_wifi), has_toilet(other.has_toilet) {
    std::cout << "Bus object copied." << std::endl;
      }

Bus* Bus::Clone() const {
    std::cout << "Bus object cloned instantly." << std::endl;
=======
      has_wifi(other.has_wifi), has_toilet(other.has_toilet),
      heavy(other.heavy)
      {}

Bus* Bus::Clone() const {
>>>>>>> c68819e (add heavydata)
    return new Bus(*this);
}

void Bus::show() const {
<<<<<<< HEAD
    std::cout << "Bus at address: " << this << " with, Model: " << model
              << ", Brand: " << brand
              << ", Weight: " << weight << " kg"
              << ", Seats: " << seats
              << ", Max Passengers: " << maxPassengers
              << ", Transit Company: " << TransitCompany
              << ", WiFi: " << (has_wifi ? "Yes" : "No")
              << ", Toilet: " << (has_toilet ? "Yes" : "No") << "\n";
=======
    std::cout << "Bus at address: " << this << " with, Model: " << model << "\n"
              << "Brand: " << brand << "\n"
              << "Weight: " << weight << " kg\n"
              << "Seats: " << seats << "\n"
              << "Max Passengers: " << maxPassengers << "\n"
              << "Transit Company: " << TransitCompany << "\n"
              << "WiFi: " << (has_wifi ? "Yes" : "No") << "\n"
              << "Toilet: " << (has_toilet ? "Yes" : "No") << "\n"
              << "HeavyData.table size: "
              << (heavy ? heavy->table->size() : 0) << "\n"
              << std::endl;
>>>>>>> c68819e (add heavydata)
}