ADDITIONAL_CC_LD_FLAGS := -g3 -fsanitize=memory
INTERNAL_LIBFT_PATH := $(BASE_PATH)/libft_msan.a

include $(BASE_PATH)/common/basic_common.mk
