#pragma once
#include <vector>
#include <memory>
#include <chrono>
#include <iostream>
#include <utility>

using clk = std::chrono::high_resolution_clock;

// 简单基准：创建 N 个对象并把它们存到 vector 里，避免被优化掉
template <typename MakeFunc>
long long bench(const std::string& label, int N, MakeFunc make) {
    auto t0 = clk::now();
    std::vector<std::unique_ptr<class Vehicle>> v;
    v.reserve(N);

    for (int i = 0; i < N; ++i) {
        auto obj = make();              // 可以是 Vehicle* 或 unique_ptr<Vehicle>
        v.emplace_back(std::move(obj)); // 统一转成 unique_ptr 存起来
        // 轻微使用一下对象，防止被过度优化
        // （如果类里有 show 或 heavy，可做极轻访问，不影响总耗时趋势）
    }

    auto t1 = clk::now();
    auto dur_us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();

    // 自动选择单位显示
    if (dur_us >= 1000) {
        std::cout << label << "：创建 " << N << " 个对象耗时 " << (dur_us / 1000) << " ms\n";
    } else {
        std::cout << label << "：创建 " << N << " 个对象耗时 " << dur_us << " µs\n";
    }
    return dur_us;
}
