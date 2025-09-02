@echo off
if not exist build mkdir build
cd build
cmake ..
cmake --build .
cd ..
echo Build complete. Run the executable from bin\BudgetApp.exe