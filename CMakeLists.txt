cmake_minimum_required(VERSION 3.10)


project(BudgetApp C)

set(CMAKE_C_STANDARD 99)

# Include directories
include_directories(include)

# Crafter static library
file(GLOB_RECURSE CRAFTER_SRC src/crafter/*.c)
add_library(CrafterLib STATIC ${CRAFTER_SRC})

# Main app sources
set(MAIN_SRC src/main.c)
file(GLOB_RECURSE BUDGET_SRC src/budget_app/*.c)
add_executable(BudgetApp ${MAIN_SRC} ${BUDGET_SRC})

# Link libraries
target_link_libraries(BudgetApp PRIVATE CrafterLib glfw3)

# For Windows, link OpenGL
if (WIN32)
    target_link_libraries(BudgetApp PRIVATE opengl32)
endif()

# Set output directory
set_target_properties(BudgetApp PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
