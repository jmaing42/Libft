Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)

CC := gcc
CCLD := gcc
AR := ar
CFLAGS := -Wall -Wextra -Werror -g3 -fsanitize=undefined -fsanitize=nullability -fsanitize=float-divide-by-zero -fsanitize=unsigned-integer-overflow -fsanitize=implicit-conversion -fsanitize=local-bounds
LDFLAGS := -g3 -fsanitize=undefined -fsanitize=nullability -fsanitize=float-divide-by-zero -fsanitize=unsigned-integer-overflow -fsanitize=implicit-conversion -fsanitize=local-bounds
SRC_DIR := ..
OBJ_DIR := .
SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
DEPS := $(OBJS:.o=.d)
TEMPS := *.o *.d

all: test
clean:
	$(Q)rm -f $(TEMPS)
fclean: clean
	$(Q)rm -f tester
test: tester
	$(Q)./tester
.PHONY: all clean fclean test

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(Q)$(CC) $(CFLAGS) -c $< -o $@ -MMD
tester: tester.a
	$(Q)$(CCLD) -o tester $(LDFLAGS) tester.a ../../../libft/libft.a
tester.a: $(OBJS)
	$(Q)$(AR) cr $@ $^
