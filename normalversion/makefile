<<<<<<< HEAD
main: main.o carproto.o busproto.o vanproto.o
	g++ -o main main.o carproto.o busproto.o vanproto.o
main.o: main.cpp vehicle.h carproto.h busproto.h vanproto.h
	g++ -c main.cpp
carproto.o: carproto.cpp carproto.h vehicle.h
	g++ -c carproto.cpp
busproto.o: busproto.cpp busproto.h vehicle.h
	g++ -c busproto.cpp
vanproto.o: vanproto.cpp vanproto.h vehicle.h
	g++ -c vanproto.cpp
clean:
	rm -f main *.o
=======
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
>>>>>>> c68819e (add heavydata)
