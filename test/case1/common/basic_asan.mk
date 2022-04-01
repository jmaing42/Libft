ADDITIONAL_CC_LD_FLAGS := -g3 -fsanitize=address
INTERNAL_LIBFT_PATH := $(BASE_PATH)/libft_asan.a

include $(BASE_PATH)/common/basic_common.mk
