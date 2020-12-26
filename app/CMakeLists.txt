ENABLE_LANGUAGE(ASM)

include(utilities)

# Main project target
add_executable(Hello_Stm32 "")

target_sources( ${CMAKE_PROJECT_NAME}
	PRIVATE
		main.cpp
     	stm32f4xx_it.c
     	syscalls.c
     	system_stm32f4xx.c
     	startup_stm32f407xx.s
)

# Target link libraries
target_link_libraries( ${CMAKE_PROJECT_NAME} 
	cmsis
	dio
	adder
)

target_compile_definitions(${CMAKE_PROJECT_NAME}
	PRIVATE
		STM32				# MCU type
		STM32F4				
		STM32F407VGTx
		STM32F407xx
)

GET_TARGET_PROPERTY(TARGET_LD_FLAGS ${CMAKE_PROJECT_NAME} LINK_FLAGS)
SET(TARGET_LD_FLAGS "\"-T${CMAKE_CURRENT_SOURCE_DIR}/LinkerScript.ld\"")
SET_TARGET_PROPERTIES(${CMAKE_PROJECT_NAME} PROPERTIES LINK_FLAGS ${TARGET_LD_FLAGS})

ADD_BIN_TARGETS(${CMAKE_PROJECT_NAME})