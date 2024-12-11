@echo off

cd List
mkdir build
cd build

cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . --config Release

cd ..
copy src\*.txt build\Release

cd build
ctest -C Release --output-on-failure

cd Release
ProjectTest.exe
pause

List.exe
pause
