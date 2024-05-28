cmake_minimum_required(VERSION 3.28)
project(un)

set(CMAKE_CXX_STANDARD 14)

# Specify the path to your GLFW build
set(GLFW_BUILD_PATH /home/paulo/glfw-3.4/build)

# Include directories for GLFW
include_directories(${GLFW_BUILD_PATH}/include)
include_directories(.)

# Add the executable
add_executable(un main.cpp main.h)

# Link against GLFW library
find_library(GLFW_LIBRARY glfw3 PATHS ${GLFW_BUILD_PATH}/src)

if (GLFW_LIBRARY)
    target_link_libraries(un ${GLFW_LIBRARY})
else()
    message(FATAL_ERROR "Could not find the GLFW library")
endif()
