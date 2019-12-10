SET(TOOLCHAIN_DIR "/usr/bin/gcc-arm-none-eabi-8-2019-q3-update")
SET(TOOLCHAIN_PREFIX "arm-none-eabi")
SET(TOOLCHAIN_BIN_DIR "${TOOLCHAIN_DIR}/bin")
SET(TOOLCHAIN_INC_DIR "${TOOLCHAIN_DIR}/${TOOLCHAIN_PREFIX}/include")
SET(TOOLCHAIN_LIB_DIR "${TOOLCHAIN_DIR}/${TOOLCHAIN_PREFIX}/lib")

SET(CMAKE_SYSTEM_NAME Generic)
SET(CMAKE_SYSTEM_PROCESSOR arm)

SET(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
SET(CMAKE_C_COMPILER "${TOOLCHAIN_BIN_DIR}/${TOOLCHAIN_PREFIX}-gcc")
SET(CMAKE_CXX_COMPILER "${TOOLCHAIN_BIN_DIR}/${TOOLCHAIN_PREFIX}-g++")
SET(CMAKE_ASM_COMPILER "${TOOLCHAIN_BIN_DIR}/${TOOLCHAIN_PREFIX}-gcc")

SET(CMAKE_OBJCOPY "${TOOLCHAIN_BIN_DIR}/${TOOLCHAIN_PREFIX}-objcopy" CACHE INTERNAL "objcopy tool")
SET(CMAKE_OBJDUMP "${TOOLCHAIN_BIN_DIR}/${TOOLCHAIN_PREFIX}-objdump" CACHE INTERNAL "objdump tool")
SET(CMAKE_SIZE "${TOOLCHAIN_BIN_DIR}/${TOOLCHAIN_PREFIX}-size" CACHE INTERNAL "size tool")
SET(CMAKE_DEBUGGER "${TOOLCHAIN_BIN_DIR}/${TOOLCHAIN_PREFIX}-gdb" CACHE INTERNAL "debugger")
SET(CMAKE_CPPFILT "${TOOLCHAIN_BIN_DIR}/${TOOLCHAIN_PREFIX}-c++filt" CACHE INTERNAL "C++filt")

SET(CMAKE_C_FLAGS_DEBUG "-Og -g" CACHE INTERNAL "c compiler flags debug")
SET(CMAKE_CXX_FLAGS_DEBUG "-Og -g" CACHE INTERNAL "cxx compiler flags debug")
SET(CMAKE_ASM_FLAGS_DEBUG "-g" CACHE INTERNAL "asm compiler flags debug")
SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "" CACHE INTERNAL "linker flags debug")

SET(CMAKE_C_FLAGS_RELEASE "-Os -flto" CACHE INTERNAL "c compiler flags release")
SET(CMAKE_CXX_FLAGS_RELEASE "-Os -flto" CACHE INTERNAL "cxx compiler flags release")
SET(CMAKE_ASM_FLAGS_RELEASE "" CACHE INTERNAL "asm compiler flags release")
SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "-flto" CACHE INTERNAL "linker flags release")

SET(CMAKE_FIND_ROOT_PATH "${TOOLCHAIN_DIR}/${TOOLCHAIN_PREFIX}")
SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

SET(CMAKE_C_FLAGS "-mthumb -fno-builtin -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -Wall -std=gnu11 -ffunction-sections -fdata-sections -fomit-frame-pointer -mabi=aapcs -fno-unroll-loops -ffast-math -ftree-vectorize" CACHE INTERNAL "c compiler flags")
SET(CMAKE_CXX_FLAGS "-mthumb -fno-builtin -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -Wall -std=c++11 -ffunction-sections -fdata-sections -fomit-frame-pointer -mabi=aapcs -fno-unroll-loops -ffast-math -ftree-vectorize" CACHE INTERNAL "cxx compiler flags")
SET(CMAKE_ASM_FLAGS "-mthumb -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -x assembler-with-cpp" CACHE INTERNAL "asm compiler flags")

SET(CMAKE_EXE_LINKER_FLAGS "-Wl,--gc-sections -mthumb -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mabi=aapcs" CACHE INTERNAL "executable linker flags")
SET(CMAKE_MODULE_LINKER_FLAGS "-mthumb -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mabi=aapcs" CACHE INTERNAL "module linker flags")
SET(CMAKE_SHARED_LINKER_FLAGS "-mthumb -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mabi=aapcs" CACHE INTERNAL "shared linker flags")

FUNCTION(STM32_ADD_HEX_BIN_TARGETS TARGET)
    ADD_CUSTOM_TARGET(${TARGET}.hex DEPENDS ${TARGET} COMMAND ${CMAKE_OBJCOPY} -O ihex "${TARGET}" ${TARGET}.hex)
    ADD_CUSTOM_TARGET(${TARGET}.srec DEPENDS ${TARGET} COMMAND ${CMAKE_OBJCOPY} -O srec "${TARGET}" ${TARGET}.srec)
    ADD_CUSTOM_TARGET(${TARGET}.bin DEPENDS ${TARGET} COMMAND ${CMAKE_OBJCOPY} -O binary "${TARGET}" ${TARGE}.bin)
ENDFUNCTION()