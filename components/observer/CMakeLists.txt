# Component is compiled into a library
add_library(Observer "")

target_sources(Observer
	PRIVATE
		src/Observer.c
)

# Component include pathes
target_include_directories(Observer
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/inc
	PRIVATE
)