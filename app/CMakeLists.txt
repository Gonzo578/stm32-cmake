ENABLE_LANGUAGE(ASM)

include(utilities)

# Main project target
add_executable(Hello_Stm32 "")

target_sources( ${CMAKE_PROJECT_NAME}
	PRIVATE
		main.cpp
     	syscalls.c
     	STM32G4xx/stm32g4xx_it.c
     	STM32G4xx/system_stm32g4xx.c
     	STM32G4xx/startup_stm32g474xx.s
)

# Target link libraries
target_link_libraries( ${CMAKE_PROJECT_NAME}
	mcu_platform
	cmsis
	dio
	adder
	led
)

target_compile_definitions(${CMAKE_PROJECT_NAME}
	PRIVATE
		STM32				# MCU type
		STM32G4				
		STM32G474RETx
		STM32G474xx
)

GET_TARGET_PROPERTY(TARGET_LD_FLAGS ${CMAKE_PROJECT_NAME} LINK_FLAGS)
SET(TARGET_LD_FLAGS "\"-T${CMAKE_CURRENT_SOURCE_DIR}/STM32G4xx/STM32G474RETX_FLASH.ld\"")
SET_TARGET_PROPERTIES(${CMAKE_PROJECT_NAME} PROPERTIES LINK_FLAGS ${TARGET_LD_FLAGS})

ADD_BIN_TARGETS(${CMAKE_PROJECT_NAME})