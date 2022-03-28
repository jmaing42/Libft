all: test
clean: init
	rm -rf tmp libft
	make -C libft_unit_test clean
fclean: init
	rm -rf tmp libft
	make -C libft_unit_test fclean
re: fclean all
init: | libft_unit_test
deinit:
	rm -rf tmp
	rm -rf libft_unit_test
refresh:
	cp -r ../../src libft
test: init refresh
ifeq ($(OS),Windows_NT)
	echo "Windows detected, no libft_unit_test"
else
ifeq ($(shell uname -s),Darwin)
	make -C libft_unit_test f
else
	echo "Non-mac OS detected, no libft_unit_test"
endif
endif
.PHONY: all clean fclean re init deinit refresh test

libft_unit_test:
	rm -rf tmp
	git clone --depth=1 https://github.com/alelievr/libft-unit-test.git tmp
	mv tmp libft_unit_test
