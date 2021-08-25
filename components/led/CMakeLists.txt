# Component is compiled into a library
add_library(led "")

target_sources(led
	PRIVATE
		src/led.cpp
)

target_link_libraries(led
	PRIVATE
		mcal_dio
)

# Component include pathes
target_include_directories(led
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/inc
	PRIVATE
)
