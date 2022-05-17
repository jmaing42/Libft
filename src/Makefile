# Assuming modifying the libft's source files only.
# If tester's source files were modified, run make in appropriate directory

Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)
MAKE := $(MAKE) $(if $(filter 1,$(V) $(VERBOSE)),,--no-print-directory)

# This variable will be used only if source files are not hardcoded
SRCS ?= $(wildcard *.c)

NAME := libft.a
HEADER_NAME := ft.h
OTHER_USEFUL_FILES := .other_file_tracker .editorconfig .gitignore

AR := ar
CC := cc
CFLAGS := -Wall -Wextra -Werror
NAME_BONUS := bonus.a
NAME_BASIC := basic.a
SRCS_BASIC := $(filter-out $(filter ft_%_bonus.c,$(SRCS)), $(SRCS))
OBJS := $(patsubst %.c,%.o,$(SRCS))
OBJS_BASIC := $(patsubst %.c,%.o,$(SRCS_BASIC))
DEPS := $(OBJS_BONUS:.o=.d)

all: $(NAME)
clean:
	$Qrm -rf *.o *.d $(NAME_BASIC) $(NAME_BONUS) $(OTHER_USEFUL_FILES) $(HEADER_NAME)
fclean: clean
	$Qrm -f $(NAME)
re:
	$Q$(MAKE) fclean
	$Q$(MAKE) all
.PHONY: all clean fclean re

$(NAME): $(NAME_BASIC) $(OTHER_USEFUL_FILES) generate_header_basic
	$Qcp $< $(NAME)
bonus: $(NAME_BONUS) $(OTHER_USEFUL_FILES) generate_header_bonus
	$Qcp $< $(NAME)
generate_header_basic:
	$Q[ "$$(grep -c "^// \\[PREPROCESSOR\\] BONUS PART START\$$" libft.h)" = "1" ] && [ "$$(grep -c "^// \\[PREPROCESSOR\\] BONUS PART END\$$" libft.h)" = "1" ] && sed -e "1,12d;$$(grep -n "^// \\[PREPROCESSOR\\] BONUS PART START\$$" libft.h | cut -d : -f 1),$$(grep -n "^// \\[PREPROCESSOR\\] BONUS PART END\$$" libft.h | cut -d : -f 1)d" libft.h > $(HEADER_NAME) || (echo "FAILED TO PREPROCESS libft.h" && sed 1,12d libft.h > $(HEADER_NAME))
generate_header_bonus:
	$Qsed 1,12d libft.h | grep -v "^// \\[PREPROCESSOR\\]" > $(HEADER_NAME)
.PHONY: $(NAME) bonus generate_header_basic generate_header_bonus

.other_file_tracker: $(filter-out $(wildcard ft_src_*.c), $(wildcard *.c))
	$Q[ ! -f $@ ] || printf "\033[93m[WARN] Other files not managed in this directory have been changed.\033[0m\n"
	$Q[ ! -f $@ ] && echo "This file is for track other files." > .other_file_tracker || true
.editorconfig:
	$Qprintf "root = true\n\n[*]\ncharset = utf-8\nend_of_line = lf\nindent_size = 4\nindent_style = tab\ninsert_final_newline = true\ntrim_trailing_whitespace = true\n" > .editorconfig
.gitignore:
	$Qprintf ".*\n*.o\n*.d\n\nlibft.a\nft.h\n" > .gitignore

$(NAME_BASIC): $(OBJS_BASIC)
	$Qrm -f $@
	$Q$(AR) cr $@ $^
$(NAME_BONUS): $(OBJS)
	$Qrm -f $@
	$Q$(AR) cr $@ $^
%.o: %.c
	$Q$(CC) $(CFLAGS) -c $< -o $@ -MMD

-include $(DEPS)
