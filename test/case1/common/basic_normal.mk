ADDITIONAL_CC_LD_FLAGS := -g3
LIBFT_PATH := ../../../../libft_normal.a

include ../../../../common/basic_common.mk

test: test_with_valgrind
test_with_valgrind:
	$(Q)[ ! command -v valgrind ] || valgrind ./tester
.PHONY: test_with_valgrind
