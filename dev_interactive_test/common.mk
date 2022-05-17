Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)
MAKE := $(MAKE) $(if $(filter 1,$(V) $(VERBOSE)),,--no-print-directory)

BASE_PATH := ../../src
SRCS := $(wildcard *.c)
NAME := main.exe

DEFAULT := Makefile

all: libft.a $(NAME) | $(DEFAULT)
clean:
	$Qrm -rf *.o *.d
fclean: clean
	$Qrm -f $(NAME)
re:
	$Q$(MAKE) fclean
	$Q$(MAKE) all
%.o: %.c
	$Qgcc -c -o $@ $< -Wall -Wextra -Werror -I$(BASE_PATH) -MMD
$(NAME): $(SRCS:.c=.o) $(BASE_PATH)/builddir/basic.a
	$Qgcc -o $@ $^
libft.a:
	$Q$(MAKE) -C $(BASE_PATH)
test: all
	$Q./$(NAME)
.PHONY: all libft.a clean fclean re test

Makefile:
	$Qcp ../common.mk $@
