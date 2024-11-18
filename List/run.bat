cd List
mkdir build
cd build
cmake ..
cmake --build . --config Release
cd ..
copy src\*.txt build\x64\Release
cd build\x64\Release
Objektinis-programavimas.exe
pause