cmake_minimum_required(VERSION 3.10)
project(un)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Specify the path to your GLFW build
set(GLFW_BUILD_PATH "/home/paulo/glfw-3.4/build")

# Include directories for GLFW
include_directories(${GLFW_BUILD_PATH}/include)

# Add the executable
add_executable(un main.cpp main.h)

target_link_libraries(un glfw)

# Link against GLFW library
find_library(GLFW_LIBRARY glfw3 PATHS ${GLFW_BUILD_PATH})

if (GLFW_LIBRARY)
    target_link_libraries(un ${GLFW_LIBRARY})
else()
    message(FATAL_ERROR "Could not find the GLFW library")
endif()