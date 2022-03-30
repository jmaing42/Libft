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

$(NAME): builddir/basic.a
	cp $< $(NAME)
bonus: builddir/bonus.a
	cp $< $(NAME)
.PHONY: $(NAME) bonus

builddir/basic.a: | builddir
	make -C builddir basic.a
builddir/bonus.a: | builddir
	make -C builddir bonus.a
builddir:
	rm -rf tmp
	mkdir -p tmp
	gcc -Wall -Wextra -Werror -o tmp/make_builddir ft_make_builddir.c
	tmp/make_builddir > tmp/Makefile
	mv tmp builddir
	rm -rf tmp
