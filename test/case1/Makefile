all: test
clean:
	rm -f $(TEMPS)
fclean: clean
	rm -f $(TARGET)
re: fclean all
init:
deinit:
refresh:
	rm -rf libft
	cp -r ../../src libft
test: refresh $(TARGET)
	make -C libft re
	make -C part1 test
	make -C part2 test
	make -C part3 test || true
.PHONY: all clean fclean re init deinit refresh test
