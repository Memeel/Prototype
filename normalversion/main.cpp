#include <iostream>
#include "vehicle.h"
#include "carproto.h"
#include "busproto.h"
#include "vanproto.h"
#include <string>

int main() {
    // Création du prototype de base
    Vehicle* car = new Car("Model S", "Tesla", 1961.0, 5);
    
    // Clonage de ce prototype (utilisation du polymorphisme)
    Vehicle* v1= car->Clone();


    // Affichage de l'objet original
    std::cout << "=== Objet original ===" << std::endl;
    car->show();

    // Affichage du clone
    std::cout << "\n=== Clone ===" << std::endl;
    v1->show();

    // Libération de la mémoire
    delete car;
    delete v1;
    
    return 0;
}