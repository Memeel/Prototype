#pragma once
#include <vector>
#include <memory>
#include <chrono>
#include <iostream>
#include <utility>

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
        // (If the class has show() or heavy data, perform minimal access that doesn't affect timing trend)
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
