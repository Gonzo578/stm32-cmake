# Component is compiled into a library
add_library(led "")

target_sources(led
	PRIVATE
		src/led.cpp
)

# Component include pathes
target_include_directories(led
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/inc
)
