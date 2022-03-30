all: test
clean:
	rm -rf tmp libft
fclean: clean
re: fclean all
init: | libft_war_machine
deinit: fclean
	rm -rf libft_war_machine
refresh:
	rm -rf libft
	cp -r ../../src libft
test: init refresh
ifeq ($(OS),Windows_NT)
	echo "Windows detected, no libft_unit_test"
else
ifeq ($(shell uname -s),Darwin)
	PATH_LIBFT="$(abspath libft)" sh libft_war_machine/grademe.sh
else
	echo "Non-mac OS detected, no libft_unit_test"
endif
endif
.PHONY: all clean fclean re init deinit refresh test

libft_war_machine:
	rm -rf tmp
	git clone --depth=1 https://github.com/y3ll0w42/libft-war-machine tmp
	cp libft_war_machine.env tmp/my_config.sh
	mv tmp libft_war_machine
