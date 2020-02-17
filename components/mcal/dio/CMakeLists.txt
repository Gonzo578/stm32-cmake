# Component source configuration
set(dio_src src/dio.cpp)

# Component include pathes
include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/inc
	${CMAKE_CURRENT_SOURCE_DIR}/../../../contrib/CMSIS/core
	${CMAKE_CURRENT_SOURCE_DIR}/../../../contrib/CMSIS/device
)

# Component is compiled into a library
add_library(dio ${dio_src})

target_compile_definitions(dio PUBLIC STM32 STM32F4 STM32F407VGTx STM32F407xx DEBUG)