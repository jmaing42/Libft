Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)

all: test clean
clean:
	$Qrm -rf libft tmp_*.txt
fclean:
	$Qrm -rf tmp libft
	$Qmake -C libft_unit_test fclean
re: fclean all
init: | libft_unit_test
deinit:
	$Qrm -rf tmp
	$Qrm -rf libft_unit_test
refresh: clean
	$Qcp -r ../../src libft
test: refresh
# make fclean
	@echo "Testing make fclean"
	$Qmake -C libft fclean
	$Qfind libft > tmp_fclean.txt
	@echo "0. All files must be in the project root directory"
	$Qgrep -E "^libft/.*/.*\$$" < tmp_fclean.txt | cmp result_empty.txt
	@echo "1. Only Makefile, libft.h, ft_*.c is allowed"
	$Qgrep -vE "^libft(/(Makefile|libft.h|ft_.*\\.c))?\$$" < tmp_fclean.txt | cmp result_empty.txt
	@printf "2. \033[93mUnused files must be checked manually!!\033[0m\n"
# make
	@echo "Testing make (default), all, libft.a"
	@echo "0. make must generate libft.a"
	$Qmake -C libft all
	$Qfind libft > tmp_all.txt
	$Qgrep -E "^libft/libft\\.a\$$" < tmp_all.txt | cmp result_libft.txt
	@echo "1. make all must be same as make"
	$Qmake -C libft fclean
	$Qmake -C libft
	$Qfind libft | cmp tmp_all.txt
	@echo "2. make libft.a must be same as make"
	$Qmake -C libft fclean
	$Qmake -C libft libft.a
	$Qfind libft | cmp tmp_all.txt
# make clean
	@echo "Testing make clean"
	@echo "0. make clean must remove temporary files except for libft.a"
	$Qmake -C libft clean
	$Qfind libft > tmp_clean.txt
	$Qgrep -vE "^libft/libft\\.a\$$" < tmp_clean.txt | cmp tmp_fclean.txt
	@echo "1. make works"
	$Qmake -C libft
	$Qfind libft | cmp tmp_all.txt
	@printf "\033[90m2. Testing with additional files is useless. skip;\033[0m\n"
# make re
	@echo "Testing make re"
	@echo "0. make re works after clean, re, fclean"
	$Qmake -C libft re
	$Qfind libft | cmp tmp_all.txt
	$Qmake -C libft re
	$Qfind libft | cmp tmp_all.txt
	$Qmake -C libft fclean
	$Qmake -C libft re
	$Qfind libft | cmp tmp_all.txt
	@echo "1. make re works even if result file is modified"
	$Qecho "" > libft/libft.a
	$Qfind libft/libft.a -size 1 | cmp result_libft.txt
	$Qmake -C libft re
	$Qfind libft | cmp tmp_all.txt
	$Qfind libft/libft.a -size 1 | cmp result_empty.txt
	@printf "2. \033[93mRelink(?) must be checked manually!!\033[0m\n"
	@echo "All Makefile test passed!"
.PHONY: all clean fclean re init deinit refresh test
