# Component is compiled into a library
add_library(adder "")

target_sources(adder
	PRIVATE
		src/adder.cpp
)

# Component include pathes
target_include_directories(adder
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/inc
)
