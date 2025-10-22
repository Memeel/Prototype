#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <memory>
#include <utility>
#include "vehicle.h"
#include "carproto.h"
#include "busproto.h"
#include "vanproto.h"

using clk = std::chrono::high_resolution_clock;

// Simple benchmark: create N objects and store them in a vector to prevent optimization
template <typename MakeFunc>
long long bench(const std::string& label, int N, MakeFunc make) {
    auto t0 = clk::now();
    std::vector<std::unique_ptr<class Vehicle>> v;
    v.reserve(N);

    for (int i = 0; i < N; ++i) {
        auto obj = make();              // Can be Vehicle* or unique_ptr<Vehicle>
        v.emplace_back(std::move(obj)); // Store as unique_ptr to unify ownership
        // Lightly use the object to avoid over-optimization
        // (If the class has show() or heavy data, perform minimal access that doesn\'t affect timing trend)
    }

    auto t1 = clk::now();
    auto dur_us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();

    // Automatically choose display unit
    if (dur_us >= 1000) {
        std::cout << label << ": created " << N << " objects in " << (dur_us / 1000) << " ms\n";
    } else {
        std::cout << label << ": created " << N << " objects in " << dur_us << " µs\n";
    }
    return dur_us;
}

int main() {
    // Create prototype instances (this is where the sleep in *Proto constructors will occur)
    std::cout << "Creating prototype instances..." << std::endl;
    CarProto* carPrototype = new CarProto();
    BusProto* busPrototype = new BusProto();
    VanProto* vanPrototype = new VanProto();
    std::cout << "Prototype instances created." << std::endl;

    std::cout << "\nDemonstrating cloning from prototypes:" << std::endl;

    // Clone vehicles from prototypes
    Vehicle* clonedCar = carPrototype->Clone();
    Vehicle* clonedBus = busPrototype->Clone();
    Vehicle* clonedVan = vanPrototype->Clone();

    std::cout << "\nCloned vehicles:" << std::endl;
    clonedCar->show();
    clonedBus->show();
    clonedVan->show();

    // Benchmarking the creation process
    constexpr int N = 5;

    std::cout << "\nBenchmarking direct construction vs. cloning..." << std::endl;

    // Benchmarking direct construction of CarProto (will include the sleep)
    auto t_direct_car_proto = bench("Direct CarProto construction", N, [] {
        return new CarProto();
    });

    // Benchmarking cloning from an existing CarProto (should be faster)
    auto t_clone_car_proto = bench("Cloning from CarProto", N, [&] {
        return carPrototype->Clone();
    });

    if (t_clone_car_proto < t_direct_car_proto)
        std::cout << "✅ Cloning CarProto is faster than direct construction.\n";
    else
        std::cout << "ℹ️ Cloning CarProto is not faster (try increasing N or sleep duration).\n";

    // Clean up
    delete carPrototype;
    delete busPrototype;
    delete vanPrototype;
    delete clonedCar;
    delete clonedBus;
    delete clonedVan;

    return 0;
}