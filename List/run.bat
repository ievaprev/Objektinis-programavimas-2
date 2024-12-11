cd List
mkdir build
cd build
cmake ..
cmake --build . --config Release
cd ..
copy src\*.txt build
cd build\Release
List.exe
pause
