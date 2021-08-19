CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
PROJECT(Hello_Stm32)

# Disable in-source builds to prevent source tree corruption.
if(" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}")
    message(FATAL_ERROR "
            FATAL: In-source builds are not allowed.
            You should create a separate directory for build files.
")
endif()

# Add cmake module path in order to give access to it for the whole project
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# Add path to 3rd party SW libraries
add_subdirectory(3rdparty)

# Add path to platform libraries
add_subdirectory(platform)

# Add path to component libraries
add_subdirectory(components)

add_subdirectory(app)

# Output some compilation infos
message(STATUS "[cmake] Bulid for OS type:		${CMAKE_SYSTEM_NAME}")
message(STATUS "[cmake] Build for OS version:	${CMAKE_SYSTEM_VERSION}")
message(STATUS "[cmake] Build for CPU type:		${CMAKE_SYSTEM_PROCESSOR}")
message(STATUS "[cmake] Build type:				${CMAKE_BUILD_TYPE}")
string(TOUPPER "${CMAKE_BUILD_TYPE}" BUILD_TYPE)
message(STATUS "[cmake] Build with cxx flags:	${CMAKE_CXX_FLAGS_${BUILD_TYPE}} ${CMAKE_CXX_FLAGS}")
message(STATUS "[cmake] Build with c flags:		${CMAKE_C_FLAGS_${BUILD_TYPE}} ${CMAKE_C_FLAGS}")
