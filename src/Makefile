# Assuming modifying the libft's source files only.
# If tester's source files were modified, run make in appropriate directory

Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)
MAKE := make --no-print-directory

NAME := libft.a
OTHERS := $(filter-out $(wildcard ft_src_*.c), $(wildcard *.c))

all: $(NAME)
clean:
	$Qrm -rf builddir tmp .tmp_others
fclean: clean
	$Qrm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re

$(NAME): builddir/basic_tested.a .tmp_others
	$Qcp $< $(NAME)
bonus: builddir/bonus_tested.a .tmp_others
	$Qcp $< $(NAME)
.PHONY: $(NAME) bonus
.tmp_others: $(OTHERS)
	$Q[ ! -f $@ ] || printf "\033[93m[WARN] Other files not managed in this directory have been changed.\033[0m\n"
	$Qecho "This file is for track other files." > .tmp_others

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
