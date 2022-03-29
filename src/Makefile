Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)

AR := ar
CC := gcc
CFLAGS := -Wall -Wextra -Werror
CFLAGS += $(if $(filter 1,$(TEST)), -Weverything -Wno-poison-system-directories -save-temps=obj,)
SRC_DIR := .
OBJ_DIR := .
TARGET := libft.a
SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
DEPS := $(OBJS:.o=.d)
TEMPS := *.o *.d
TEMPS += *.bc *.i *.s

all: $(TARGET)
.PHONY: all clean fclean re
clean:
	$(Q)rm -f $(TEMPS)
fclean: clean
	$(Q)rm -f $(TARGET)
re: fclean all

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(Q)$(CC) $(CFLAGS) -c $< -o $@ -MMD

$(TARGET): $(OBJS)
	$(Q)$(AR) cr $@ $^

-include $(DEPS)
