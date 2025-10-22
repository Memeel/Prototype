# ===== Basic configuration =====
PROJECT := main
CXX     ?= g++
CXXFLAGS:= -std=c++17 -O2 -Wall -Wextra -pedantic -pthread
LDFLAGS := -pthread -lrt

# Flat directory: collect all .cpp files in the current directory
SRCS := $(wildcard *.cpp)
BUILD_DIR := build
OBJS := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SRCS))
DEPS := $(OBJS:.o=.d)

.PHONY: all clean run rebuild print

all: $(PROJECT)

# Linking
$(PROJECT): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

# Generic compile rule: compile any *.cpp -> build/*.o (auto-create subdirectories) and generate dependency (.d) files
$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

# Automatic dependencies
-include $(DEPS)

run: $(PROJECT)
	./$(PROJECT)

clean:
	rm -rf $(BUILD_DIR) $(PROJECT)

rebuild: clean all

# Debug: print source/target files
print:
	@echo "SRCS = $(SRCS)"
	@echo "OBJS = $(OBJS)"
