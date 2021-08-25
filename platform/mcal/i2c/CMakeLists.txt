# Component is compiled into a library
add_library(mcal_i2c "")

target_sources(mcal_i2c
	PRIVATE
		src/i2c.cpp
)

target_link_libraries(mcal_i2c
	PRIVATE
		mcu_platform
		cmsis
)

# Component include pathes
target_include_directories(mcal_i2c
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/inc
)
