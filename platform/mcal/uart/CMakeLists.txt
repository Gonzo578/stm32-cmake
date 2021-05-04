# Component is compiled into a library
add_library(uart "")

target_sources(uart
	PRIVATE
		src/uart.cpp
)

target_link_libraries(uart
	PRIVATE
		mcu_platform
		cmsis
)

# Component include pathes
target_include_directories(uart
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/inc
)

target_compile_definitions(uart
	PUBLIC
		STM32				# MCU type
		STM32G4				
		STM32G474RETx
		STM32G474xx
)
