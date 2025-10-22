#include <iostream>
#include <ctime>
#include "vehicle.h"
#include "carproto.h"
#include "busproto.h"
#include "vanproto.h"

// ANSI escape codes for colors
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

// Get current time in microseconds using wall-clock time
// This captures actual elapsed time, including sleep delays
long long get_time_microseconds() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (long long)ts.tv_sec * 1000000LL + ts.tv_nsec / 1000LL;
}

// Demonstrate the prototype pattern by cloning vehicles from prototypes
void demonstrate_prototypes(CarProto* carPrototype, BusProto* busPrototype, VanProto* vanPrototype) {
    std::cout << BLUE << "\nDemonstrating cloning from prototypes:" << RESET << std::endl;

    // Clone one of each vehicle type from the prototypes
    Vehicle* clonedCar = carPrototype->Clone();
    Vehicle* clonedBus = busPrototype->Clone();
    Vehicle* clonedVan = vanPrototype->Clone();

    // Display the cloned vehicles
    std::cout << BLUE << "\nCloned vehicles:" << RESET << std::endl;
    clonedCar->show();
    clonedBus->show();
    clonedVan->show();

    // Clean up cloned objects
    delete clonedCar;
    delete clonedBus;
    delete clonedVan;
}

int main() {
    // Create prototype instances (these will invoke the slow constructors with sleep)
    std::cout << CYAN << "Creating prototype instances..." << RESET << std::endl;
    CarProto* carPrototype = new CarProto();
    BusProto* busPrototype = new BusProto();
    VanProto* vanPrototype = new VanProto();
    std::cout << GREEN << "Prototype instances created." << RESET << std::endl;

    // Show how cloning works
    demonstrate_prototypes(carPrototype, busPrototype, vanPrototype);

    // Number of objects to create in the benchmark
    const int N = 5;

    std::cout << MAGENTA << "\nBenchmarking direct construction vs. cloning..." << RESET << std::endl;

    // Arrays to store the created objects
    Vehicle* direct_cars[N];
    Vehicle* cloned_benchmark_cars[N];

    // Benchmark 1: Direct construction (calls constructor N times, including sleep)
    long long start = get_time_microseconds();
    for (int i = 0; i < N; ++i) {
        direct_cars[i] = new CarProto();
    }
    long long end = get_time_microseconds();
    long long t_direct_car_proto = end - start;

    // Display direct construction time
    if (t_direct_car_proto >= 1000) {
        std::cout << YELLOW << "Direct CarProto construction" << RESET << ": created " << N << " objects in " << (t_direct_car_proto / 1000) << " ms\n";
    } else {
        std::cout << YELLOW << "Direct CarProto construction" << RESET << ": created " << N << " objects in " << t_direct_car_proto << " µs\n";
    }

    // Benchmark 2: Cloning (copies existing object, skips constructor and sleep)
    start = get_time_microseconds();
    for (int i = 0; i < N; ++i) {
        cloned_benchmark_cars[i] = carPrototype->Clone();
    }
    end = get_time_microseconds();
    long long t_clone_car_proto = end - start;

    // Display cloning time
    if (t_clone_car_proto >= 1000) {
        std::cout << YELLOW << "Cloning from CarProto" << RESET << ": created " << N << " objects in " << (t_clone_car_proto / 1000) << " ms\n";
    } else {
        std::cout << YELLOW << "Cloning from CarProto" << RESET << ": created " << N << " objects in " << t_clone_car_proto << " µs\n";
    }

    // Compare results
    if (t_clone_car_proto < t_direct_car_proto)
        std::cout << GREEN << "Cloning CarProto is faster than direct construction.\n" << RESET;
    else
        std::cout << RED << "Cloning CarProto is not faster (try increasing N or sleep duration).\n" << RESET;

    // Clean up prototype instances
    delete carPrototype;
    delete busPrototype;
    delete vanPrototype;

    // Clean up all benchmarked objects
    for (int i = 0; i < N; ++i) {
        delete direct_cars[i];
        delete cloned_benchmark_cars[i];
    }

    return 0;
}