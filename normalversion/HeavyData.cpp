#include "HeavyData.h"
#include <cmath>
#include <chrono>
#include <thread>

using clk = std::chrono::high_resolution_clock;

HeavyData::HeavyData() {
    // --- Simulate expensive initialization: heavy computation + I/O delay ---
    auto buf = std::make_shared<std::vector<double>>(30000);
    for (size_t i = 0; i < buf->size(); ++i) {
        (*buf)[i] = std::sin(0.001 * i) * std::cos(0.002 * i) + std::sqrt(0.1 + i % 97);
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(80)); // Simulate I/O delay
    table = buf; // Immutable shared data
}

