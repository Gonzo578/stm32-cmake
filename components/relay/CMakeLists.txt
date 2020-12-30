# Component is compiled into a library
add_library(relay "")

target_sources(relay
	PRIVATE
		src/relay.cpp
)

# Component include pathes
target_include_directories(relay
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/inc
)
