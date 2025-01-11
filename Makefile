# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Project settings
TARGET = build/app
SRC = $(wildcard src/*.cpp)
OBJ = $(patsubst src/%.cpp, build/%.o, $(SRC))

# Default target
all: $(TARGET)
	@echo "Running $(TARGET)..."
	@cd build && ./app && cd ..

# Link object files to create the executable
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)

# Compile .cpp files to .o files in build/
build/%.o: src/%.cpp | build
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create the build directory if it doesn't exist
build:
	mkdir -p build

# Clean build artifacts
clean:
	rm -rf build/

# Phony targets
.PHONY: all clean
