# UICrafter with Budget App

## Project Details

### UICrafter

UICrafter is gui library made using opengl and C.

### Demo App

A simple app to demo the gui lib

## System Requirements

- CMake 3.10 or newer
- C Compiler: GCC (7.0+), Clang (5.0+), or MSVC (2017+)
- OpenGL 3.3 or newer
- GLFW 3.3 or newer
- GLAD (included in source)
- (Optional) Make or Ninja (for Unix/Linux builds)

All other dependencies (GLAD, GLFW headers, etc.) are included in the `libs/` and `include/` folders.

## Building and Running

This project uses CMake to generate its build system.

### Windows

Run `build.bat` to build the project.
Next, run `bin/BudgetApp.exe` to start the app.

### Linux and Mac

Run `sh build.sh` to build the project.
Next, run `bin/BudgetApp` to start the app.

## Troubleshooting

- Ensure CMake and a supported C compiler are installed and available in your PATH.
- If you see errors about missing dependencies, check that you are using the provided `libs/` and `include/` folders.


## Credits
