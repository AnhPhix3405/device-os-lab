# This file is a makefile included from the top level makefile which
# defines the sources built for the target.

# Define the prefix to this directory.
# Note: The name must be unique within this build and should be
#       based on the root of the project
TARGET_SRC_PATH = src

INCLUDE_DIRS += $(TARGET_SRC_PATH)

# C source files included in this build.
# CSRC +=

# C++ source files included in this build.
CPPSRC += $(TARGET_SRC_PATH)/coap.cpp
CPPSRC += $(TARGET_SRC_PATH)/handshake.cpp
CPPSRC += $(TARGET_SRC_PATH)/spark_protocol_functions.cpp
CPPSRC += $(TARGET_SRC_PATH)/communication_dynalib.cpp
CPPSRC += $(TARGET_SRC_PATH)/dsakeygen.cpp
CPPSRC += $(TARGET_SRC_PATH)/eckeygen.cpp
CPPSRC += $(TARGET_SRC_PATH)/lightssl_message_channel.cpp
CPPSRC += $(TARGET_SRC_PATH)/dtls_message_channel.cpp
CPPSRC += $(TARGET_SRC_PATH)/dtls_protocol.cpp
CPPSRC += $(TARGET_SRC_PATH)/lightssl_protocol.cpp
CPPSRC += $(TARGET_SRC_PATH)/protocol.cpp
CPPSRC += $(TARGET_SRC_PATH)/messages.cpp
CPPSRC += $(TARGET_SRC_PATH)/chunked_transfer.cpp
CPPSRC += $(TARGET_SRC_PATH)/coap_channel.cpp
CPPSRC += $(TARGET_SRC_PATH)/publisher.cpp
CPPSRC += $(TARGET_SRC_PATH)/subscriptions.cpp
CPPSRC += $(TARGET_SRC_PATH)/protocol_defs.cpp
CPPSRC += $(TARGET_SRC_PATH)/protocol_util.cpp
CPPSRC += $(TARGET_SRC_PATH)/communication_diagnostic.cpp
CPPSRC += $(TARGET_SRC_PATH)/variables.cpp
CPPSRC += $(TARGET_SRC_PATH)/coap_defs.cpp
CPPSRC += $(TARGET_SRC_PATH)/coap_message_encoder.cpp
CPPSRC += $(TARGET_SRC_PATH)/coap_message_decoder.cpp
CPPSRC += $(TARGET_SRC_PATH)/coap_util.cpp
CPPSRC += $(TARGET_SRC_PATH)/firmware_update.cpp
CPPSRC += $(TARGET_SRC_PATH)/description.cpp
CPPSRC += $(TARGET_SRC_PATH)/v2/coap_channel.cpp
CPPSRC += $(TARGET_SRC_PATH)/v2/coap_payload.cpp
CPPSRC += $(TARGET_SRC_PATH)/v2/coap_options.cpp
CPPSRC += $(TARGET_SRC_PATH)/v2/coap_tag.cpp
CPPSRC += $(TARGET_SRC_PATH)/v2/coap_api.cpp

# ASM source files included in this build.
ASRC +=

# Update build configuration to reflect modularized structure
MODULES += coap dtls protocol_util

# Add dependencies for modularized files
coap_SRCS = coap.cpp coap_channel.cpp coap_message_decoder.cpp coap_message_encoder.cpp
coap_HDRS = coap_channel.h coap_message_decoder.h coap_message_encoder.h

dtls_SRCS = dtls_protocol.cpp dtls_message_channel.cpp

dtls_HDRS = dtls_protocol.h dtls_message_channel.h

protocol_util_SRCS = protocol_util.cpp
protocol_util_HDRS = protocol_util.h

# if PLATFORM_ID matches 13 23 25 or 26, and not DEBUG_BUILD=y, set LOG_LEVEL_ERROR
ifneq (,$(filter $(PLATFORM_ID), 13 15 23 25 26 37))
ifneq ($(DEBUG_BUILD),y)
CFLAGS += -DLOG_COMPILE_TIME_LEVEL=LOG_LEVEL_ERROR
endif
endif

LOG_MODULE_CATEGORY = comm
