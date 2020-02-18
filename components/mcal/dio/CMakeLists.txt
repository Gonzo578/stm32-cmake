# Component source configuration
set(dio_src src/dio.cpp)

# Component is compiled into a library
add_library(dio ${dio_src})

# Component include pathes
target_include_directories( dio
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/inc
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}/../../../contrib/CMSIS/core
		${CMAKE_CURRENT_SOURCE_DIR}/../../../contrib/CMSIS/device
)

target_compile_definitions(dio PUBLIC STM32 STM32F4 STM32F407VGTx STM32F407xx DEBUG)