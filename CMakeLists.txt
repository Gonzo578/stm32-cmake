CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
PROJECT(Hello_Stm32)

# Disable in-source builds to prevent source tree corruption.
if(" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}")
    message(FATAL_ERROR "
            FATAL: In-source builds are not allowed.
            You should create a separate directory for build files.
")
endif()

# Add path to 3rd party SW libraries
add_subdirectory(3rdparty)

# Add path to component libraries
add_subdirectory(components)

add_subdirectory(src)
