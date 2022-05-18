ADDITIONAL_CC_LD_FLAGS := -g3 -fsanitize=undefined -fsanitize=nullability -fsanitize=unsigned-integer-overflow -fsanitize=implicit-conversion -fsanitize=local-bounds
INTERNAL_LIBFT_PATH := $(BASE_PATH)/libft_ubsan.a

TEST_NAME += with UndefinedBehaviorSanitizer

include $(BASE_PATH)/common/basic_common.mk
