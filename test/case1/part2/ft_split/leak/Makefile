BASE_PATH := ../../..

include $(BASE_PATH)/common/variables.mk

INTERNAL_LIBFT_PATH := $(BASE_PATH)/libft/libft.a

CFLAGS := -Wall -Wextra -Werror -fsanitize=address
LDFLAGS := -fsanitize=address
SRC_DIR := .
OBJ_DIR := .
SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
DEPS := $(OBJS:.o=.d)
TEMPS := *.o *.d

all: test
clean:
	$Qrm -f $(TEMPS) tester
fclean: clean
	$Qrm -f tester.a
test: tester
	@echo "Testing ft_split with libft_leak_test"
	$Q./tester
.PHONY: all clean fclean test

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$Q$(CC) $(CFLAGS) -c $< -o $@ -MMD
tester: tester.a $(INTERNAL_LIBFT_PATH) $(BASE_PATH)/common/leak_test/libft_leak_test.address.a
	$Q$(CC) -o tester $(LDFLAGS) $^
tester.a: $(OBJS)
	$Q$(AR) cr $@ $^

.PHONY: $(BASE_PATH)/common/leak_test/libft_leak_test.address.a
$(BASE_PATH)/common/leak_test/libft_leak_test.address.a:
	$Q$(MAKE) -C $(BASE_PATH)/common/leak_test libft_leak_test.address.a
