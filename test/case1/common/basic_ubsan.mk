ADDITIONAL_CC_LD_FLAGS := -g3 -fsanitize=undefined -fsanitize=nullability -fsanitize=float-divide-by-zero -fsanitize=unsigned-integer-overflow -fsanitize=implicit-conversion -fsanitize=local-bounds
LIBFT_PATH := ../../../../libft_ubsan.a

include ../../../../common/basic_common.mk
