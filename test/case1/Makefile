CC := gcc
CCLD := gcc
CFLAGS := -Wall -Wextra -Werror -I../libft
LDFLAGS :=
SRC_DIR := .
OBJ_DIR := .
TARGET := main.exe
SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
DEPS := $(OBJS:.o=.d)
TEMPS := *.o *.d
TEMPS += *.bc *.i *.s

all: test
clean:
	rm -f $(TEMPS)
fclean: clean
	rm -f $(TARGET)
re: fclean all
init:
deinit:
refresh:
	rm -rf libft
	cp -r ../../src libft
test: refresh $(TARGET)
	make -C libft
	./$(TARGET) < data/ft_isalpha.csv
.PHONY: all clean fclean re

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -MD

$(TARGET): $(OBJS)
	$(CCLD) $(LDFLAGS) $^ libft/libft.a -o $@ -MD

-include $(DEPS)
