if exist build\ (
rmdir /s /q build
)
mkdir build
cd build
cmake -G "MinGW Makefiles" ../src/
mingw32-make.exe -j6
"%cd%"\build\Workshop.exe