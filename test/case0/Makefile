Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)

all: test clean
clean:
	$(Q)rm -rf libft tmp_*.txt
fclean:
	$(Q)rm -rf tmp libft
	$(Q)make -C libft_unit_test fclean
re: fclean all
init: | libft_unit_test
deinit:
	$(Q)rm -rf tmp
	$(Q)rm -rf libft_unit_test
refresh: clean
	$(Q)cp -r ../../src libft
test: refresh
# make fclean
	@echo "Testing make fclean"
	$(Q)make -C libft fclean
	$(Q)find libft > tmp_fclean.txt
	@echo "0. All files must be in the project root directory"
	$(Q)grep -E "^libft/.*/.*\$$" < tmp_fclean.txt | cmp result_empty.txt
	@echo "1. Only {Makefile,*.{c,h,mk}} is allowed"
	$(Q)grep -vE "^libft/.*\\.(c|h|mk)\$$" < tmp_fclean.txt | cmp result_makefile.txt
	@printf "2. \033[93mUnused files must be checked manually!!\033[0m\n"
# make
	@echo "Testing make (default), all, libft.a"
	@echo "0. make must generate libft.a"
	$(Q)make -C libft all
	$(Q)find libft > tmp_all.txt
	$(Q)grep -E "^libft/libft\\.a\$$" < tmp_all.txt | cmp result_libft.txt
	@echo "1. make all must be same as make"
	$(Q)make -C libft fclean
	$(Q)make -C libft
	$(Q)find libft | cmp tmp_all.txt
	@echo "2. make libft.a must be same as make"
	$(Q)make -C libft fclean
	$(Q)make -C libft libft.a
	$(Q)find libft | cmp tmp_all.txt
# make clean
	@echo "Testing make clean"
	@echo "0. make clean must remove temporary files except for libft.a"
	$(Q)make -C libft clean
	$(Q)find libft > tmp_clean.txt
	$(Q)grep -vE "^libft/libft\\.a\$$" < tmp_clean.txt | cmp tmp_fclean.txt
	@echo "1. make works"
	$(Q)make -C libft
	$(Q)find libft | cmp tmp_all.txt
	@printf "\033[90m2. Testing with additional files is useless. skip;\033[0m\n"
# make re
	@echo "Testing make re"
	@echo "0. make re works after clean, re, fclean"
	$(Q)make -C libft re
	$(Q)find libft | cmp tmp_all.txt
	$(Q)make -C libft re
	$(Q)find libft | cmp tmp_all.txt
	$(Q)make -C libft fclean
	$(Q)make -C libft re
	$(Q)find libft | cmp tmp_all.txt
	@echo "1. make re works even if result file is modified"
	$(Q)echo "" > libft/libft.a
	$(Q)find libft/libft.a -size 1 | cmp result_libft.txt
	$(Q)make -C libft re
	$(Q)find libft | cmp tmp_all.txt
	$(Q)find libft/libft.a -size 1 | cmp result_empty.txt
	@printf "2. \033[93mRelink(?) must be checked manually!!\033[0m\n"
	@echo "All Makefile test passed!"
.PHONY: all clean fclean re init deinit refresh test
