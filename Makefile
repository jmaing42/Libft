test:
	norminette
	make -C src
	make -C test test
	echo "OK!"
fclean:
	make -C src fclean
	make -C test fclean
.PHONY: test fclean
