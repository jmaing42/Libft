ADDITIONAL_CC_LD_FLAGS := -g3
INTERNAL_LIBFT_PATH := $(BASE_PATH)/libft_normal.a

include $(BASE_PATH)/common/basic_common.mk

test: test_with_valgrind
test_with_valgrind:
	$Q(! command -v valgrind) || valgrind -q --leak-check=full ./tester
.PHONY: test_with_valgrind
