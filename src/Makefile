# Assuming modifying the libft's source files only.
# If tester's source files were modified, run make in appropriate directory

Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)
MAKE := make --no-print-directory

# This variable will be overriden by script-generated file list
SRCS := $(wildcard *.c)

NAME := libft.a
HEADER_NAME := ft.h
OTHER_USEFUL_FILES := .other_file_tracker .editorconfig .gitignore

all: $(NAME)
clean:
	$Qrm -rf builddir tmp $(OTHER_USEFUL_FILES) $(HEADER_NAME)
fclean: clean
	$Qrm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re

$(NAME): builddir/basic_tested.a $(OTHER_USEFUL_FILES) generate_header_basic
	$Qcp $< $(NAME)
bonus: builddir/bonus_tested.a $(OTHER_USEFUL_FILES) generate_header_bonus
	$Qcp $< $(NAME)
generate_header_basic:
	$Q[ "$$(grep -c "^// \\[PREPROCESSOR\\] BONUS PART START\$$" libft.h)" = "1" ] && [ "$$(grep -c "^// \\[PREPROCESSOR\\] BONUS PART END\$$" libft.h)" = "1" ] && sed -e "1,12d;$$(grep -n "^// \\[PREPROCESSOR\\] BONUS PART START\$$" libft.h | cut -d : -f 1),$$(grep -n "^// \\[PREPROCESSOR\\] BONUS PART END\$$" libft.h | cut -d : -f 1)d" libft.h > $(HEADER_NAME) || (echo "FAILED TO PREPROCESS libft.h" && sed 1,12d libft.h > $(HEADER_NAME))
generate_header_bonus:
	$Qsed 1,12d libft.h | grep -v "^// \\[PREPROCESSOR\\]" > $(HEADER_NAME)
.PHONY: $(NAME) bonus generate_header_basic generate_header_bonus

builddir/basic_tested.a: | builddir
	$Q$(MAKE) -C builddir basic_tested.a
builddir/bonus_tested.a: | builddir
	$Q$(MAKE) -C builddir bonus_tested.a
builddir:
	$Q$(MAKE) try_make_builddir || (make clean && false)
try_make_builddir:
	$Qrm -rf tmp
	$Qmkdir -p tmp/tmp
	$Qgcc -Wall -Wextra -Werror -o tmp/makegen ft_make_builddir.c ft_make_common.c
	$Qtmp/makegen > tmp/Makefile
	$Qecho "SRCS := $(SRCS)" >> tmp/Makefile
	$Qrm -f tmp/makegen
	$Qmv tmp builddir
.PHONY: try_make_builddir builddir/basic_tested.a builddir/bonus_tested.a

.other_file_tracker: $(filter-out $(wildcard ft_src_*.c), $(wildcard *.c))
	$Q[ ! -f $@ ] || printf "\033[93m[WARN] Other files not managed in this directory have been changed.\033[0m\n"
	$Q[ ! -f $@ ] && echo "This file is for track other files." > .other_file_tracker || true
.editorconfig:
	$Qprintf "root = true\n\n[*]\ncharset = utf-8\nend_of_line = lf\nindent_size = 4\nindent_style = tab\ninsert_final_newline = true\ntrim_trailing_whitespace = true\n" > .editorconfig
.gitignore:
	$Qprintf ".*\ntmp\nbuilddir\n\nlibft.a\nft.h\n" > .gitignore
