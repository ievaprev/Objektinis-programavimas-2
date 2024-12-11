cd Vector
mkdir build
cd build
cmake ..
cmake --build . --config Release
cd ..
copy src\*.txt build
cd build\Release
Vector.exe
pause
