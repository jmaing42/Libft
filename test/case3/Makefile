all: test
clean:
	rm -rf tmp libft
fclean: clean
re: fclean all
init: | Libftest
deinit: fclean
	rm -rf Libftest
refresh:
	rm -rf libft
	cp -r ../../src libft
test: init refresh
ifeq ($(OS),Windows_NT)
	echo "Windows detected, no libft_unit_test"
else
ifeq ($(shell uname -s),Darwin)
	PATH_LIBFT="$(abspath libft)" sh Libftest/grademe.sh
else
	echo "Non-mac OS detected, no libft_unit_test"
endif
endif
.PHONY: all clean fclean re init deinit refresh test

Libftest:
	rm -rf tmp
	git clone --depth=1 https://github.com/jtoty/Libftest tmp
	cp Libftest.env tmp/my_config.sh
	mv tmp Libftest
