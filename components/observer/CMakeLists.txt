# Component is compiled into a library
add_library(observer "")

target_sources(observer
	PRIVATE
		src/observer.c
)

# Component include pathes
target_include_directories(observer
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/inc
	PRIVATE
)