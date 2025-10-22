# ===== 基本配置 =====
PROJECT := main
CXX     ?= g++
CXXFLAGS:= -std=c++17 -O2 -Wall -Wextra -pedantic -pthread
LDFLAGS := -pthread

# 扁平目录：收集当前目录下所有 .cpp
SRCS := $(wildcard *.cpp)
BUILD_DIR := build
OBJS := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SRCS))
DEPS := $(OBJS:.o=.d)

.PHONY: all clean run rebuild print

all: $(PROJECT)

# 链接
$(PROJECT): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

# 通用编译规则：任何 *.cpp -> build/*.o（自动建子目录），并生成依赖文件
$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

# 自动依赖
-include $(DEPS)

run: $(PROJECT)
	./$(PROJECT)

clean:
	rm -rf $(BUILD_DIR) $(PROJECT)

rebuild: clean all

# 调试：打印源/目标文件
print:
	@echo "SRCS = $(SRCS)"
	@echo "OBJS = $(OBJS)"
