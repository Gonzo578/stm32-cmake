cmake -S . -B build/ -DCMAKE_TOOLCHAIN_FILE=../cmake/cm4.cmake -DCMAKE_BUILD_TYPE=Debug #-DCMAKE_VERBOSE_MAKEFILE:BOOL=ON
cmake --build build/