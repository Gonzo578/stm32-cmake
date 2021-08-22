# Component is compiled into a library
add_library(obs_example "")

target_sources(obs_example
	PRIVATE
		obs_example.c
)

target_link_libraries(obs_example
	PRIVATE
        Observer
)

# Component include pathes
target_include_directories(obs_example
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}
	PRIVATE
)
