CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
PROJECT(observer)

###############################################################################
##  BUILD OPTIONS
###############################################################################
option(BUILD_TESTS "Build tests (default OFF)" OFF)

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

###############################################################################
##  TESTING
###############################################################################
if(BUILD_TESTS)
    message(STATUS "Building tests")
    enable_testing()

	include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
	conan_basic_setup() 

	add_subdirectory(test)
endif()