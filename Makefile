# Makefile for a C++ project

# Compiler and compiler flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror 

# Source files, object files, and executable name
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
EXECUTABLE = prog

# Rule to build the executable
$(EXECUTABLE): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to build object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<
	
# Default target
all: clean $(EXECUTABLE) run

# Clean target
clean:
	rm -f $(OBJS) $(EXECUTABLE)

# Execute target	
run:
	./$(EXECUTABLE)
	

