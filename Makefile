test:
	norminette
	make -C src
	make -C test/case1 test
fclean:
	make -C src fclean
	make -C test/case1 fclean
.PHONY: test fclean
