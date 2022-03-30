Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)

NAME := libft.a

AR := ar
CC := clang
CFLAGS := -Wall -Wextra -Werror
CFLAGS += $(if $(filter 1,$(TEST)), -Weverything -Wno-poison-system-directories -save-temps=obj,)
SRC_DIR := .
OBJ_DIR := .
NAME_BASIC := $(OBJ_DIR)/basic.a
NAME_BONUS := $(OBJ_DIR)/bonus.a
SRCS_BONUS := $(wildcard $(SRC_DIR)/*.c)
SRCS_BASIC := $(filter-out $(wildcard $(SRC_DIR)/*_bonus.c), $(SRCS_BONUS))
OBJS_BONUS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS_BONUS))
OBJS_BASIC := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS_BASIC))
DEPS := $(OBJS_BONUS:.o=.d)
TEMPS := *.o *.d *.bc *.i *.s

all: $(NAME)
clean:
	$(Q)rm -f $(TEMPS)
	$(Q)rm -f $(NAME_BASIC) $(NAME_BONUS)
fclean: clean
	$(Q)rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re

$(NAME): $(NAME_BASIC)
	$(Q)cp $< $(NAME)
bonus: $(NAME_BONUS)
	$(Q)cp $< $(NAME)
.PHONY: $(NAME) bonus

$(NAME_BASIC): $(OBJS_BASIC)
	$(Q)$(AR) cr $@ $^
$(NAME_BONUS): $(OBJS_BONUS)
	$(Q)$(AR) cr $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(Q)$(CC) $(CFLAGS) -c $< -o $@ -MMD

-include $(DEPS)
