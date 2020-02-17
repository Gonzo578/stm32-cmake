# Component source configuration
set(dio_src src/dio.cpp)

# Component include pathes
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)

# Component is compiled into a library
add_library(dio ${dio_src})