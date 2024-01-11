# Makefile
CXX = g++

# Flags for compilation
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror

SRC_DIR = src
INCLUDE_DIR = header
BUILD_DIR = build

TARGET = my_program

# Include and library paths
INC_SRC_PATHS = -I$(INCLUDE_DIR)

# List of source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# List of object files
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))


# Build main program
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(INC_SRC_PATHS) -c -o $@ $<
	
	
.DEFAULT_GOAL := $(TARGET)
.PHONY: all clean run_test run

all: $(TARGET) run

run:
	@./$(TARGET)

clean:
	rm -rf $(BUILD_DIR)/*.o my_program

clean_run:
	rm my_program

clean_build:
	rm -rf $(BUILD_DIR)/*.o