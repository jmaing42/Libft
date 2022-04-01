# Assuming modifying the libft's source files only.
# If tester's source files were modified, run make in appropriate directory

Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)
MAKE := make --no-print-directory

NAME := libft.a
OTHER_USEFUL_FILES := .tmp_others .editorconfig .gitignore

all: $(NAME)
clean:
	$Qrm -rf builddir tmp $(OTHER_USEFUL_FILES)
fclean: clean
	$Qrm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re

$(NAME): builddir/basic_tested.a $(OTHER_USEFUL_FILES)
	$Qcp $< $(NAME)
bonus: builddir/bonus_tested.a $(OTHER_USEFUL_FILES)
	$Qcp $< $(NAME)
.PHONY: $(NAME) bonus

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
	$Qrm -f tmp/makegen
	$Qmv tmp builddir
.PHONY: try_make_builddir builddir/basic_tested.a builddir/bonus_tested.a

.tmp_others: $(filter-out $(wildcard ft_src_*.c), $(wildcard *.c))
	$Q[ ! -f $@ ] || printf "\033[93m[WARN] Other files not managed in this directory have been changed.\033[0m\n"
	$Q[ ! -f $@ ] && echo "This file is for track other files." > .tmp_others || true
.editorconfig:
	$Qprintf "root = true\n\n[*]\ncharset = utf-8\nend_of_line = lf\nindent_size = 4\nindent_style = tab\ninsert_final_newline = true\ntrim_trailing_whitespace = true\n" > .editorconfig
.gitignore:
	$Qprintf ".*\ntmp\nbuilddir\n" > .gitignore
