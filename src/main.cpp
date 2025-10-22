#include <iostream>
#include <ctime>
#include "vehicle.h"
#include "car.h"
#include "bus.h"
#include "van.h"

// ANSI escape codes for colors
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

// Get current time in microseconds using wall-clock time
long long get_time_microseconds() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (long long)ts.tv_sec * 1000000LL + ts.tv_nsec / 1000LL;
}

// Demonstrate the prototype pattern by cloning vehicles from prototypes
void demonstrate_prototypes(Vehicle* carPrototype, Vehicle* busPrototype, Vehicle* vanPrototype) {
    std::cout << BLUE << "\nDemonstrating cloning from prototypes:" << RESET << std::endl;

    // Clone one of each vehicle type from the prototypes (FAST)
    Vehicle* clonedCar = carPrototype->Clone();
    Vehicle* clonedBus = busPrototype->Clone();
    Vehicle* clonedVan = vanPrototype->Clone();

    // Show them
    clonedCar->show();
    clonedBus->show();
    clonedVan->show();

    // Clean up cloned objects
    delete clonedCar;
    delete clonedBus;
    delete clonedVan;
}

int main() {
    // Create prototype instances (these will invoke the slow constructors)
    std::cout << CYAN << "Creating prototype instances (SLOW)..." << RESET << std::endl;
    Vehicle* carPrototype = new Car(); // This is slow
    Vehicle* busPrototype = new Bus(); // This is slow
    Vehicle* vanPrototype = new Van(); // This is slow
    std::cout << GREEN << "Prototype instances created." << RESET << std::endl;

    // Show how cloning works
    demonstrate_prototypes(carPrototype, busPrototype, vanPrototype);

    // Number of objects to create in the benchmark
    const int N = 5;

    std::cout << MAGENTA << "\nBenchmarking direct construction vs. cloning (" << N << " objects)..." << RESET << std::endl;

    // Arrays to store the created objects
    Vehicle* direct_cars[N];
    Vehicle* cloned_benchmark_cars[N];

    // Benchmark 1: Direct construction (calls SLOW constructor N times)
    long long start = get_time_microseconds();
    for (int i = 0; i < N; ++i) {
        direct_cars[i] = new Car(); // Calls slow constructor
    }
    long long end = get_time_microseconds();
    long long t_direct_car = end - start;

    // Display direct construction time
    if (t_direct_car >= 1000) {
        std::cout << YELLOW << "Direct Car construction" << RESET << ": created " << N << " objects in " << (t_direct_car / 1000) << " ms\n\n";
    } else {
        std::cout << YELLOW << "Direct Car construction" << RESET << ": created " << N << " objects in " << t_direct_car << " µs\n\n";
    }

    // Benchmark 2: Cloning (calls FAST copy constructor N times)
    start = get_time_microseconds();
    for (int i = 0; i < N; ++i) {
        cloned_benchmark_cars[i] = carPrototype->Clone();
    }
    end = get_time_microseconds();
    long long t_clone_car = end - start;

    // Display cloning time
    if (t_clone_car >= 1000) {
        std::cout << YELLOW << "Cloning from Car" << RESET << ": created " << N << " objects in " << (t_clone_car / 1000) << " ms\n";
    } else {
        std::cout << YELLOW << "Cloning from Car" << RESET << ": created " << N << " objects in " << t_clone_car << " µs\n";
    }

    // Compare results
    if (t_clone_car < t_direct_car)
        std::cout << GREEN << "\nCloning Car is faster than direct construction.\n" << RESET;
    else
        std::cout << RED << "\nCloning Car is not faster (try increasing N or sleep duration).\n" << RESET;

    std::cout << CYAN << "\nCleaning up all prototypes and benchmark objects..." << RESET << std::endl;

    // Clean up prototype instances
    delete carPrototype;
    delete busPrototype;
    delete vanPrototype;

    // Clean up all benchmarked objects
    for (int i = 0; i < N; ++i) {
        delete direct_cars[i];
        delete cloned_benchmark_cars[i];
    }

    std::cout << GREEN << "Cleanup complete." << RESET << std::endl;

    return 0;
}