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
    
<<<<<<< HEAD
    // Clonage de ce prototype (utilisation du polymorphisme)
=======
    

    // Clonage des prototypes (utilisation du polymorphisme)
>>>>>>> c68819e (add heavydata)
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
<<<<<<< HEAD
    
=======
    delete v2;
    delete v3;

    Vehicle* car_proto = new Car("Model S", "Tesla", 1961.0, 5);
    constexpr int N = 100;

        // A) 普通 new：每次都完整构造（含 HeavyData 的昂贵初始化）
    auto t_new = bench("A) Construction classique (new)", N, [] {
        return new Car("Model S", "Tesla", 1961.0, 5);
    });

    // B) 原型克隆：共享 HeavyData，拷贝轻字段
    auto t_clone = bench("B) Prototype.clone()", N, [&] {
        return car_proto->Clone();
    });

    // 对比结论
    if (t_clone < t_new)
        std::cout << "✅ clone 明显更快（共享昂贵资源 HeavyData）\n";
    else
        std::cout << "ℹ️ clone 未更快（可增大 N 或加重 HeavyData 构造）\n";


>>>>>>> c68819e (add heavydata)
    return 0;
}