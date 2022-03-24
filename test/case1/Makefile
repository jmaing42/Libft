CC := gcc
CCLD := gcc
CFLAGS := -Wall -Wextra -Werror -I../../src
LDFLAGS :=
SRC_DIR := .
OBJ_DIR := .
TARGET := main.exe
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
test: all
	./$(TARGET) < data/ft_isalpha.csv

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -MD

$(TARGET): $(OBJS)
	$(CCLD) $(LDFLAGS) $^ ../../src/libft.a -o $@ -MD

-include $(DEPS)
