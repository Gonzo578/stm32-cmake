# Component is compiled into a library
add_library(BME280_driver "")

target_sources(BME280_driver
	PRIVATE
		bme280.c
)

# Component include pathes
target_include_directories(BME280_driver
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}
	PRIVATE
)