CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
PROJECT(stm32-minimal-cpp)

# Disable in-source builds to prevent source tree corruption.
if(" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}")
    message(FATAL_ERROR "
            FATAL: In-source builds are not allowed.
            You should create a separate directory for build files.
")
endif()

ENABLE_LANGUAGE(ASM)

# Add path to 3rd party SW libraries
add_subdirectory(3rdparty)

# Add path to component libraries
add_subdirectory(components)

# Main project target
add_executable(${CMAKE_PROJECT_NAME} "")

target_sources( ${CMAKE_PROJECT_NAME}
	PRIVATE
		src/main.cpp
     	src/stm32f4xx_it.c
     	src/syscalls.c
     	src/system_stm32f4xx.c
     	src/startup_stm32f407xx.s
)

# Target link libraries
target_link_libraries( ${CMAKE_PROJECT_NAME} 
	cmsis
	dio
	adder
)

target_compile_definitions(${CMAKE_PROJECT_NAME}
	PRIVATE
		STM32
		STM32F4
		STM32F407VGTx
		STM32F407xx
)

GET_TARGET_PROPERTY(TARGET_LD_FLAGS ${CMAKE_PROJECT_NAME} LINK_FLAGS)
SET(TARGET_LD_FLAGS "\"-T../LinkerScript.ld\"")
SET_TARGET_PROPERTIES(${CMAKE_PROJECT_NAME} PROPERTIES LINK_FLAGS ${TARGET_LD_FLAGS})

ADD_BIN_TARGETS(${CMAKE_PROJECT_NAME})
