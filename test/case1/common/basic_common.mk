# requires ADDITIONAL_CC_LD_FLAGS, LIBFT_PATH

Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)

CC := clang
CCLD := clang
AR := ar
CFLAGS := -Wall -Wextra -Werror $(ADDITIONAL_CC_LD_FLAGS)
LDFLAGS := $(ADDITIONAL_CC_LD_FLAGS)
SRC_DIR := ../..
OBJ_DIR := .
SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
DEPS := $(OBJS:.o=.d)
TEMPS := *.o *.d

all: test
clean:
	$Qrm -f $(TEMPS)
fclean: clean
	$Qrm -f tester
test: tester
	$Q./tester
.PHONY: all clean fclean test

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$Q$(CC) $(CFLAGS) -c $< -o $@ -MMD
tester: tester.a
	$Q$(CCLD) -o tester $(LDFLAGS) tester.a $(LIBFT_PATH)
tester.a: $(OBJS)
	$Q$(AR) cr $@ $^
