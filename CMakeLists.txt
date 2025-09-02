cmake_minimum_required(VERSION 3.10)

project(BudgetApp C)

set(CMAKE_C_STANDARD 99)

# Source files
file(GLOB_RECURSE SRC_FILES src/*.c)

# Include directories
include_directories(include)

# Add executable
add_executable(BudgetApp ${SRC_FILES})

# Link libraries (adjust as needed)
target_link_libraries(BudgetApp PRIVATE glfw3)

# For Windows, link OpenGL
if (WIN32)
    target_link_libraries(BudgetApp PRIVATE opengl32)
endif()

# Set output directory
set_target_properties(BudgetApp PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
