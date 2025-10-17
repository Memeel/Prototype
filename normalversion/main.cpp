#include <iostream>
#include "vehicle.h"
#include "carproto.h"
#include "busproto.h"
#include "vanproto.h"
#include <string>

int main() {
    // Création des prototypes de base
    Vehicle* car = new Car("Model S", "Tesla", 1961.0, 5);
    Vehicle* bus = new Bus("Intercity", "Mercedes-Benz", 12000.0, 50, 70, "City Transit", true, true);
    Vehicle* van = new Van("Sprinter", "Mercedes-Benz", 3500.0, 3, 15.0, 1500.0, true);

    // déclaration de pointeurs de type Vehicle
    

    // Clonage des prototypes (utilisation du polymorphisme)
    Vehicle* v1= car->Clone();
    Vehicle* v2= bus->Clone();
    Vehicle* v3= van->Clone();

    // Affichage des objets originaux
    std::cout << "=== Objets originaux ===" << std::endl;
    car->show();
    bus->show();
    van->show();

    // Affichage des clones
    std::cout << "\n=== Clones ===" << std::endl;
    v1->show();
    v2->show();
    v3->show();
    // Libération de la mémoire
    delete car;
    delete bus;
    delete van;
    delete v1;
    delete v2;
    delete v3;

    return 0;
}