#include <iostream>
#include "vehicle.h"
#include "carproto.h"
#include "busproto.h"
#include "vanproto.h"
#include "bench.h"
#include <string>

int main() {
    // Création du prototype de base
    Vehicle* car = new Car("Model S", "Tesla", 1961.0, 5);
    
    

    // Clonage des prototypes (utilisation du polymorphisme)
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

    Vehicle* car_proto = new Car("Model S", "Tesla", 1961.0, 5);
    constexpr int N = 100;

    // A) Normal new: fully constructs each time (including expensive HeavyData initialization)
    auto t_new = bench("A) Classic construction (new)", N, [] {
        return new Car("Model S", "Tesla", 1961.0, 5);
    });

    // B) Prototype cloning: shares HeavyData, copies only lightweight fields
    auto t_clone = bench("B) Prototype.clone()", N, [&] {
        return car_proto->Clone();
    });

    // Comparison result
    if (t_clone < t_new)
        std::cout << "✅ clone is significantly faster (shared expensive resource HeavyData)\n";
    else
        std::cout << "ℹ️ clone is not faster (try increasing N or making HeavyData construction heavier)\n";


    return 0;
}