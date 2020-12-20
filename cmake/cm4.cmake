###################################################################################################
# This is the master toolchain file for cortex-m4 cross compilation
###################################################################################################

# Define basic system
SET(CMAKE_SYSTEM_NAME Generic)
SET(CMAKE_SYSTEM_PROCESSOR cortex-m4)

set(MCPU_FLAGS "-mthumb -mcpu=cortex-m4")				# Basic core related flags
set(VFP_FLAGS "-mfpu=fpv4-sp-d16 -mfloat-abi=hard")		# Floating point configuration
set(SPEC_FLAGS "")										# e.g. "--specs=nosys.specs" or "--specs=newlib.nano"

include(${CMAKE_CURRENT_LIST_DIR}/gcc-arm-none-eabi.cmake)