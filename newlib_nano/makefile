MODULE=newlib_nano
NEWLIBNANO_MODULE_PATH=.

# Target this makefile is building.
TARGET_TYPE = a
BUILD_PATH_EXT = $(NEWLIBNANO_BUILD_PATH_EXT)

DEPENDENCIES = hal services platform dynalib

# Ensure compatibility with newlib_nano
CFLAGS += -DNEWLIB_NANO
LDFLAGS += -specs=custom-nano-4.8.4.specs

include ../build/arm-tlm.mk
