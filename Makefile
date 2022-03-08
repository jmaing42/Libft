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
	rm -f $(TEMPS)
fclean: clean
	rm -f $(TARGET)
re: fclean all
test:
	norminette

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -MD $(LDFLAGS)

$(TARGET): $(OBJS)
	$(AR) cr $@ $^

-include $(DEPS)
