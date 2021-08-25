# Component is compiled into a library
add_library(mcal_dio "")

target_sources(mcal_dio
	PRIVATE
		src/dio.cpp
)

target_link_libraries(mcal_dio
	PRIVATE
		mcu_platform
		cmsis
)

# Component include pathes
target_include_directories(mcal_dio
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/inc
)

target_compile_definitions(mcal_dio
	PUBLIC
		STM32				# MCU type
		STM32G4				
		STM32G474RETx
		STM32G474xx
)