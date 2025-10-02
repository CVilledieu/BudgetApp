cmake_minimum_required(VERSION 3.10)


project(DemoApp C)

set(CMAKE_C_STANDARD 99)

# Include directories
include_directories(include)

# Crafter static library
file(GLOB_RECURSE CRAFTER_SRC src/crafter/*.c)
add_library(CrafterLib STATIC ${CRAFTER_SRC})

# Demo app sources
set(MAIN_SRC src/demo_app/main.c)
file(GLOB_RECURSE BUDGET_SRC src/demo_app/*.c)
add_executable(DemoApp ${MAIN_SRC} ${BUDGET_SRC})

# Link libraries
target_link_libraries(DemoApp PRIVATE CrafterLib glfw3)

# For Windows, link OpenGL
if (WIN32)
    target_link_libraries(DemoApp PRIVATE opengl32)
endif()

# Set output directory
set_target_properties(DemoApp PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
