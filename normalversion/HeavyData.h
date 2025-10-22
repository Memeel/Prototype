#pragma once
#include <memory>
#include <vector>

// HeavyData: simulates an expensive and immutable shared resource
// Initialized only once in the Prototype, and shared among cloned objects
struct HeavyData {
    std::shared_ptr<const std::vector<double>> table;
    HeavyData(); // Implemented in .cpp (simulates an "expensive initialization")
};
