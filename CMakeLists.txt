PROJECT(stm32-minimal-cpp)

# Disable in-source builds to prevent source tree corruption.
if(" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}")
    message(FATAL_ERROR "
            FATAL: In-source builds are not allowed.
            You should create a separate directory for build files.
")
endif()

CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
ENABLE_LANGUAGE(ASM)

# Add path to 3rd party SW libraries
add_subdirectory(contrib)

SET(PROJECT_SOURCES
    src/main.cpp
    src/stm32f4xx_it.c
    src/syscalls.c
    src/system_stm32f4xx.c
    startup/startup_stm32f407xx.s
)

include_directories(
	inc
	${CMAKE_CURRENT_SOURCE_DIR}/contrib/CMSIS/core
	${CMAKE_CURRENT_SOURCE_DIR}/contrib/CMSIS/device
)

add_executable(${CMAKE_PROJECT_NAME} ${PROJECT_SOURCES})

target_compile_definitions(${CMAKE_PROJECT_NAME} PUBLIC STM32 STM32F4 STM32F407VGTx STM32F407xx DEBUG)

GET_TARGET_PROPERTY(TARGET_LD_FLAGS ${CMAKE_PROJECT_NAME} LINK_FLAGS)
SET(TARGET_LD_FLAGS "\"-T../LinkerScript.ld\"")
SET_TARGET_PROPERTIES(${CMAKE_PROJECT_NAME} PROPERTIES LINK_FLAGS ${TARGET_LD_FLAGS})

STM32_ADD_HEX_BIN_TARGETS(${CMAKE_PROJECT_NAME})
