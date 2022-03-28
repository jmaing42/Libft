all: test
clean:
	rm -rf tmp libft
fclean: clean
re: fclean all
init: | Libftest
deinit: fclean
	rm -rf Libftest
refresh:
	cp -r ../../src libft
test: init refresh
	PATH_LIBFT="$(abspath libft)" sh Libftest/grademe.sh
.PHONY: all clean fclean re init deinit refresh test

Libftest:
	rm -rf tmp
	git clone --depth=1 https://github.com/jtoty/Libftest tmp
	cp my_config.sh tmp
	mv tmp Libftest
