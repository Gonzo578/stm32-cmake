# Component is compiled into a library
add_library(dio "")

target_sources(dio
	PRIVATE
		src/dio.cpp
)

target_link_libraries(dio
	PRIVATE
		mcu_platform
		cmsis
)

# Component include pathes
target_include_directories(dio
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/inc
)

target_compile_definitions(dio
	PUBLIC
		STM32				# MCU type
		STM32G4				
		STM32G474RETx
		STM32G474xx
)