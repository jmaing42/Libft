all: test
clean:
	rm -rf tmp libft
fclean: clean
re: fclean all
init: | libft_tester
deinit: fclean
	rm -rf libft_tester
refresh:
	rm -rf libft
	cp -r ../../src libft
test: init refresh
	make -C libft_tester a
.PHONY: all clean fclean re init deinit refresh test

libft_tester:
	rm -rf tmp
	git clone --depth=1 https://github.com/Tripouille/libftTester.git tmp
	echo "LIBFT_PATH := ../libft" >> tmp/Makefile
	mv tmp libft_tester
