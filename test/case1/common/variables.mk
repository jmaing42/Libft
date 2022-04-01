Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)
MAKE := make --no-print-directory
CC := clang
CXX := clang
AR := ar

LIBFT_PATH ?= ../../src

ifneq ($(BASE_PATH),)
-include $(BASE_PATH)/variables.local.mk
endif
