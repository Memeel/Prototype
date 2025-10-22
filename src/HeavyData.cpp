#include "HeavyData.h"
#include <chrono>
#include <thread>
#include <memory>

HeavyData::HeavyData() {
    
    std::this_thread::sleep_for(std::chrono::milliseconds(80)); 

    
    table = std::make_shared<std::vector<double>>(1, 1);
}
