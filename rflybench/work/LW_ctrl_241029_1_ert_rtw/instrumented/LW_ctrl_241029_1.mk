###########################################################################
## Makefile generated for component 'LW_ctrl_241029_1'. 
## 
## Makefile     : LW_ctrl_241029_1.mk
## Generated on : Tue Dec 23 22:14:57 2025
## Final product: $(RELATIVE_PATH_TO_ANCHOR)/LW_ctrl_241029_1.pre.o
## Product type : executable
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile

PRODUCT_NAME              = LW_ctrl_241029_1
MAKEFILE                  = LW_ctrl_241029_1.mk
MATLAB_ROOT               = D:/Matlab2024b/Matlab 2024b
MATLAB_BIN                = D:/Matlab2024b/Matlab 2024b/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = D:/bhcxq/research/benchmaker/rflybench/work
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
TGT_FCN_LIB               = None
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 0
RELATIVE_PATH_TO_ANCHOR   = ../..
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          Pixhawk Toolchain
# Supported Version(s):    
# ToolchainInfo Version:   R2017b
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# TARGET_LOAD_CMD_ARGS
# TARGET_LOAD_CMD
# PX4_BASE

#-----------
# MACROS
#-----------

Q                                   = $(if $(V),,@)
PX4_SIMULINK_APP                    = px4_simulink_app
CPFLAGS                             = -O binary
ARCHWARNINGS                        = -Wall \
-Wextra \
-Wdouble-promotion \
-Wshadow \
-Wfloat-equal \
-Wframe-larger-than=1024 \
-Wpointer-arith \
-Wlogical-op \
-Wmissing-declarations \
-Wpacked \
-Wno-unused-parameter \
-Werror=format-security \
-Werror=array-bounds \
-Wfatal-errors \
-Wformat=1
ARCHCWARNINGS                       = $(ARCHWARNINGS) \
-Wbad-function-cast \
-Wstrict-prototypes \
-Wold-style-declaration \
-Wmissing-parameter-type \
-Wmissing-prototypes \
-Wnested-externs
ARCHOPTIMIZATION                    = -O3 \
-fno-strict-aliasing \
-fno-strength-reduce \
-fomit-frame-pointer \
-funsafe-math-optimizations \
-fno-builtin-printf \
-ffunction-sections \
-fdata-sections
ARCHCPUFLAGS_CORTEXM3               = -mcpu=cortex-m4 \
-mthumb \
-march=armv7e-m \
-mfpu=fpv4-sp-d16 \
-ffixed-r10 \
-mfloat-abi=hard
ARCHCPUFLAGS                        = $(ARCHCPUFLAGS_CORTEXM3)
INSTRUMENTATIONDEFINES              = $(ARCHINSTRUMENTATIONDEFINES_CORTEXM3)
ARCHDEFINES                         = -DCONFIG_ARCH_BOARD_PX4FMU_V2
LIBGCC                              = $(shell $(CC) $(ARCHCPUFLAGS) -print-libgcc-file-name)
LIBM                                = $(shell $(CC) $(ARCHCPUFLAGS) -print-file-name=libm.a)
MAKEROOT                            = /bin

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = 

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: Pixhawk Toolchain C Compiler
CC = echo

# Linker: Pixhawk ToolchainC Pre-Linker
LD = echo

# Archiver: Pixhawk Toolchain Archiver
AR = echo

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = $(MEX_PATH)/mex

# Download: Download
DOWNLOAD =

# Invoke Make: Invoke Make
INVOKE = $(call CALLPX4MK)

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%\bin\win64
MAKE = $(MAKE_PATH)/gmake


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
ENDGRP              = --end-group
OUTPUT_FLAG         = -o
STARTGRP            = --start-group
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @del /F
ECHO                = @echo
MV                  = @move
RUN                 =

#----------------------------------------
# "Faster Builds" Build Configuration
#----------------------------------------

ARFLAGS              = ruvs
CFLAGS               = -MD \
                       -c \
                       -std=gnu99 \
                       $(ARCHCWARNINGS) \
                       $(ARCHCPUFLAGS) \
                       $(ARCHINCLUDES) \
                       $(INSTRUMENTATIONDEFINES) \
                       $(ARCHDEFINES) \
                       -fno-common \
                       -nodefaultlibs \
                       -nostdlib \
                       -Wframe-larger-than=2000 \
                       -fvisibility=hidden \
                       -include visibility.h \
                       -O0 \
                       -fno-builtin-printf
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
MAKEFILENAME         =
LDFLAGS              = -Ur \
                       -Map $(PRODUCT_NAME).pre.o.map
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE) postdownload_preexecute
SHAREDLIB_LDFLAGS    =



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(RELATIVE_PATH_TO_ANCHOR)/LW_ctrl_241029_1.pre.o
PRODUCT_TYPE = "executable"
BUILD_TYPE = "Top-Level Standalone Executable"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR) -I$(START_DIR)/LW_ctrl_241029_1_ert_rtw/instrumented -ID:/bhcxq/research/benchmaker/rflybench/mainModel -I$(MATLAB_ROOT)/extern/include -I$(MATLAB_ROOT)/simulink/include -I$(MATLAB_ROOT)/rtw/c/src -I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common -I$(MATLAB_ROOT)/rtw/c/ert -I$(MATLAB_ROOT)/rtw/c/src/ext_mode/serial -I$(PX4_ROOT)/src/lib/mathlib/CMSIS/Include -I$(PX4_ROOT)/lib/gcc/wingw32/4.6.2.include -I$(PX4_ROOT)/Firmware/src -I$(PX4_ROOT)/Firmware/build_$(PX4PSP_CMAKE_CONFIG) -I$(PX4_ROOT)/Firmware/build_$(PX4PSP_CMAKE_CONFIG)/src -I$(PX4_ROOT)/Firmware/src/modules -I$(PX4_ROOT)/Firmware/src/include -I$(PX4_ROOT)/Firmware/src/lib -I$(PX4_ROOT)/Firmware/src/platforms -I$(PX4_ROOT)/Firmware/src/drivers/boards/px4fmu-v2 -I$(PX4_ROOT)/Firmware/build_$(PX4PSP_CMAKE_CONFIG)/src/modules/px4_messages -I$(PX4_ROOT)/Firmware/build_$(PX4PSP_CMAKE_CONFIG)/src/modules -I$(PX4_ROOT)/Firmware/mavlink/include/mavlink -I$(PX4_ROOT)/Firmware/src/lib/DriverFramework/framework/include -I$(PX4_ROOT)/Firmware/src/lib/matrix -I$(PX4PSP_MODULE_BUILD_OUTPUT)/px4fmu-v2/NuttX/nuttx-export/include -I$(PX4PSP_MODULE_BUILD_OUTPUT)/px4fmu-v2/NuttX/nuttx-export/include/cxx -I$(PX4PSP_MODULE_BUILD_OUTPUT)/px4fmu-v2/NuttX/nuttx-export/arch/chip -I$(PX4PSP_MODULE_BUILD_OUTPUT)/px4fmu-v2/NuttX/nuttx-export/arch/common -I$(PX4PSP_MODULE_BUILD_OUTPUT)/external/Install/include -IC:/Users/bhcxq/Documents/MATLAB/Add-Ons/Toolboxes/PX4PSP/code/include

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_ = -DMW_STANDALONE_EXECUTION_PROFILER_ON -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__
DEFINES_BUILD_ARGS = -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=0
DEFINES_CUSTOM = 
DEFINES_OPTS = -DTID01EQ=0 -DPROFILING_DEFINE_UINT64_TIMER_TYPE
DEFINES_SKIPFORSIL = -DUSE_STDPERIPH_DRIVER -DPX4 -DCONFIG_ARCH_BOARD_PX4FMU_V2 -DGIT_VERSION=d3398270e101359de9687c2d077d991c9892f573 -D__DF_NUTTX -D__PX4_NUTTX -DARM_MATH_CM4=1 -D__FPU_PRESENT=1 -D__FPU_USED=1 -DHSE_VALUE=8000000 -DNULL=0 -DEXIT_FAILURE=1 -DEXTMODE_DISABLETESTING -DEXTMODE_DISABLEPRINTF -DSTACK_SIZE=128 -DRT
DEFINES_STANDARD = -DMODEL=LW_ctrl_241029_1 -DNUMST=1 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0

DEFINES = $(DEFINES_) $(DEFINES_BUILD_ARGS) $(DEFINES_CUSTOM) $(DEFINES_OPTS) $(DEFINES_SKIPFORSIL) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/LW_ctrl_241029_1_ert_rtw/instrumented/LW_ctrl_241029_1.c $(START_DIR)/LW_ctrl_241029_1_ert_rtw/instrumented/LW_ctrl_241029_1_data.c $(START_DIR)/LW_ctrl_241029_1_ert_rtw/instrumented/rtGetInf.c $(START_DIR)/LW_ctrl_241029_1_ert_rtw/instrumented/rtGetNaN.c $(START_DIR)/LW_ctrl_241029_1_ert_rtw/instrumented/rt_nonfinite.c C:/Users/bhcxq/Documents/MATLAB/Add-Ons/Toolboxes/PX4PSP/code/src/ReadCalib_Parameter.c D:/bhcxq/research/benchmaker/rflybench/mainModel/px4_simulink_app_params.c C:/Users/bhcxq/Documents/MATLAB/Add-Ons/Toolboxes/PX4PSP/code/src/PX4_TaskControl.c C:/Users/bhcxq/Documents/MATLAB/Add-Ons/Toolboxes/PX4PSP/code/src/nuttxinitialize.c coder_profile_timer.c

MAIN_SRC = $(START_DIR)/LW_ctrl_241029_1_ert_rtw/instrumented/ert_main.c

ALL_SRCS = $(SRCS) $(MAIN_SRC)

###########################################################################
## OBJECTS
###########################################################################

OBJS = LW_ctrl_241029_1.o LW_ctrl_241029_1_data.o rtGetInf.o rtGetNaN.o rt_nonfinite.o ReadCalib_Parameter.o px4_simulink_app_params.o PX4_TaskControl.o nuttxinitialize.o coder_profile_timer.o

MAIN_OBJ = ert_main.o

ALL_OBJS = $(OBJS) $(MAIN_OBJ)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = 

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_BASIC)

###########################################################################
## INLINED COMMANDS
###########################################################################


define CALLPX4MK 
	@echo "Making Firmware $2" 
	C:\Windows\Sysnative\wsl.exe -d RflySim-20.04 echo Starting PX4 Build;cd $(PX4_BASE);pwd; ./BkFile/EnvCur.sh; export PATH=$$HOME/gcc-arm-none-eabi-7-2017-q4-major/bin:$$PATH;make px4_fmu-v6c_default
	@echo "### Finished calling CMAKE build process ###" 
endef


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build buildobj clean info prebuild download postdownload_preexecute execute


all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


buildobj : prebuild $(OBJS) $(PREBUILT_OBJS)
	@echo "### Successfully generated all binary outputs."


prebuild : 


download : $(PRODUCT)


postdownload_preexecute : download
	@echo "### Invoking postbuild tool "Invoke Make" ..."
	$(INVOKE) $(MAKEFILENAME)
	@echo "### Done invoking postbuild tool."


execute : postdownload_preexecute
	@echo "### Invoking postbuild tool "Execute" ..."
	$(EXECUTE) $(EXECUTE_FLAGS)
	@echo "### Done invoking postbuild tool."


###########################################################################
## FINAL TARGET
###########################################################################

#-------------------------------------------
# Create a standalone executable            
#-------------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS) $(MAIN_OBJ)
	@echo "### Creating standalone executable "$(PRODUCT)" ..."
	$(LD) $(LDFLAGS) -o $(PRODUCT) $(OBJS) $(MAIN_OBJ) $(SYSTEM_LIBS) $(TOOLCHAIN_LIBS)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.o : %.c
	$(CC) $(CFLAGS) -o $@ $<


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.o : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.o : D:/bhcxq/research/benchmaker/rflybench/mainModel/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.o : C:/Users/bhcxq/Documents/MATLAB/Add-Ons/Toolboxes/PX4PSP/code/src/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.o : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.o : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.o : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.o : $(START_DIR)/LW_ctrl_241029_1_ert_rtw/instrumented/%.c
	$(CC) $(CFLAGS) -o $@ $<


ert_main.o : $(START_DIR)/LW_ctrl_241029_1_ert_rtw/instrumented/ert_main.c
	$(CC) $(CFLAGS) -o $@ $<


LW_ctrl_241029_1.o : $(START_DIR)/LW_ctrl_241029_1_ert_rtw/instrumented/LW_ctrl_241029_1.c
	$(CC) $(CFLAGS) -o $@ $<


LW_ctrl_241029_1_data.o : $(START_DIR)/LW_ctrl_241029_1_ert_rtw/instrumented/LW_ctrl_241029_1_data.c
	$(CC) $(CFLAGS) -o $@ $<


rtGetInf.o : $(START_DIR)/LW_ctrl_241029_1_ert_rtw/instrumented/rtGetInf.c
	$(CC) $(CFLAGS) -o $@ $<


rtGetNaN.o : $(START_DIR)/LW_ctrl_241029_1_ert_rtw/instrumented/rtGetNaN.c
	$(CC) $(CFLAGS) -o $@ $<


rt_nonfinite.o : $(START_DIR)/LW_ctrl_241029_1_ert_rtw/instrumented/rt_nonfinite.c
	$(CC) $(CFLAGS) -o $@ $<


ReadCalib_Parameter.o : C:/Users/bhcxq/Documents/MATLAB/Add-Ons/Toolboxes/PX4PSP/code/src/ReadCalib_Parameter.c
	$(CC) $(CFLAGS) -o $@ $<


px4_simulink_app_params.o : D:/bhcxq/research/benchmaker/rflybench/mainModel/px4_simulink_app_params.c
	$(CC) $(CFLAGS) -o $@ $<


PX4_TaskControl.o : C:/Users/bhcxq/Documents/MATLAB/Add-Ons/Toolboxes/PX4PSP/code/src/PX4_TaskControl.c
	$(CC) $(CFLAGS) -o $@ $<


nuttxinitialize.o : C:/Users/bhcxq/Documents/MATLAB/Add-Ons/Toolboxes/PX4PSP/code/src/nuttxinitialize.c
	$(CC) $(CFLAGS) -o $@ $<


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### MAKEFILENAME = $(MAKEFILENAME)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files ..."
	$(RM) $(subst /,\,$(PRODUCT))
	$(RM) $(subst /,\,$(ALL_OBJS))
	$(ECHO) "### Deleted all derived files."


