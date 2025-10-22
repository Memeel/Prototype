#pragma once
#include <memory>
#include <vector>

// HeavyData：模拟昂贵且不可变的共享资源
// 在 Prototype 中只初始化一次，后续克隆对象共享这份数据
struct HeavyData {
    std::shared_ptr<const std::vector<double>> table;
    HeavyData(); // 在 .cpp 中实现（包含“昂贵初始化”的模拟）
};
