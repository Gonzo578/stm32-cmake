project(cmsis)

# Define cmsis as header only library target
add_library(cmsis INTERFACE)

# Component include pathes
target_include_directories(cmsis
	INTERFACE
		${CMAKE_CURRENT_SOURCE_DIR}/core
		${CMAKE_CURRENT_SOURCE_DIR}/device
)