project(cmsis)

# Define cmsis as header only library target
add_library(cmsis INTERFACE)

# Component include pathes
target_include_directories(cmsis
	INTERFACE
		${CMAKE_CURRENT_SOURCE_DIR}/Core/Include
)

add_library(mcu_platform INTERFACE)

target_include_directories(mcu_platform
	INTERFACE
		${CMAKE_CURRENT_SOURCE_DIR}/Device/STM32F4xx
)