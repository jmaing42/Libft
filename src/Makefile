# Assuming modifying the source files.
# If source files modified after make, make it again in the builddir or make re

NAME := libft.a

all: $(NAME)
clean:
	rm -rf builddir tmp
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re

$(NAME): builddir/basic_tested.a
	cp $< $(NAME)
bonus: builddir/bonus_tested.a
	cp $< $(NAME)
.PHONY: $(NAME) bonus

builddir/basic_tested.a: | builddir
	make -C builddir basic_tested.a
builddir/bonus_tested.a: | builddir
	make -C builddir bonus_tested.a
builddir:
	make try_make_builddir || (make clean && false)
try_make_builddir:
	rm -rf tmp
	mkdir -p tmp/tmp
	gcc -Wall -Wextra -Werror -o tmp/makegen ft_make_builddir.c
	tmp/makegen > tmp/Makefile
	rm -f tmp/makegen
	mv tmp builddir
.PHONY: try_make_builddir
