cmake_minimum_required(VERSION 3.28)
project(un)

set(CMAKE_CXX_STANDARD 14)

# Specify the path to your GLFW installation
# If you installed GLFW using `sudo make install`, it should be in /usr/local by default

# Find the GLFW package
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)

# Include directories
include_directories(${GLFW_INCLUDE_DIRS})
include_directories(.)

# Add the executable
add_executable(un main.cpp main.h)

# Link against GLFW
target_link_libraries(un ${GLFW_LIBRARIES})
