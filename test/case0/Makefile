Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)

all: test
clean:
	$Qrm -rf libft tmp_*.txt
fclean: clean
re: fclean all
init: checker
deinit: fclean
	$Qrm -f checker
reinit: deinit init
refresh: clean
	$Qrm -rf libft
	$Qcp -r ../../src libft
test: init refresh
	@printf "\033[93mAssuming make fclean make initial state - must be manually checked.\033[0m\n"
# make fclean
	@echo "Testing make fclean"
	@@make --no-print-directory -C libft fclean
	$Qfind libft > tmp_fclean.txt
	@echo "0. All files must be in the project root directory"
	$Qgrep -E "^libft/.*/.*\$$" < tmp_fclean.txt | cmp result_empty.txt
	@echo "1. Only Makefile, libft.h, ft_*.c is allowed"
	$Qgrep -vE "^libft(/(Makefile|libft.h|ft_.*\\.c))?\$$" < tmp_fclean.txt | cmp result_empty.txt
	@printf "2. \033[93mUnused files must be checked manually!!\033[0m\n"
# make
	@echo "Testing make (default), all, libft.a"
	@echo "0. make must generate libft.a"
	@@make --no-print-directory -C libft all
	$Qfind libft > tmp_all.txt
	$Qgrep -E "^libft/libft\\.a\$$" < tmp_all.txt | cmp result_libft.txt
	@echo "1. make all must be same as make"
	@@make --no-print-directory -C libft fclean
	@@make --no-print-directory -C libft
	$Qfind libft | cmp tmp_all.txt
	@echo "2. make libft.a must be same as make"
	@@make --no-print-directory -C libft fclean
	@@make --no-print-directory -C libft libft.a
	$Qfind libft | cmp tmp_all.txt
# make clean
	@echo "Testing make clean"
	@echo "0. make clean must remove temporary files except for libft.a"
	@@make --no-print-directory -C libft clean
	$Qfind libft > tmp_clean.txt
	$Qgrep -vE "^libft/libft\\.a\$$" < tmp_clean.txt | cmp tmp_fclean.txt
	@echo "1. make works"
	@@make --no-print-directory -C libft
	$Qfind libft | cmp tmp_all.txt
	@printf "\033[90m2. Testing with additional files is useless. skip;\033[0m\n"
# make re
	@echo "Testing make re"
	@echo "0. make re works after clean, re, fclean"
	@@make --no-print-directory -C libft re
	$Qfind libft | cmp tmp_all.txt
	@@make --no-print-directory -C libft re
	$Qfind libft | cmp tmp_all.txt
	@@make --no-print-directory -C libft fclean
	@@make --no-print-directory -C libft re
	$Qfind libft | cmp tmp_all.txt
	@echo "1. make re works even if result file is modified"
	$Qprintf "" > libft/libft.a
	@@make --no-print-directory -C libft re
	$Qfind libft | cmp tmp_all.txt
	$Q[ ! "$(wc -c libft/libft.a)" = "0" ]
	@printf "2. \033[93mRelink(?) must be checked manually!!\033[0m\n"
	@echo "All Makefile test passed!"
# norm, compile, disallowed chars
	@echo "Testing norm, compile, disallowed chars"
	@@make --no-print-directory -C libft fclean
	@echo "0. Makefile"
	$Q./checker < libft/Makefile || ("File Makefile has disallowed characters" && exit 1)
	@echo "1. libft.h"
	$Q./checker < libft/libft.h || ("File libft.h has disallowed characters" && exit 1)
	$Qnorminette libft/libft.h > libft/libft.h.norm.txt || (echo "Norm error on libft.h" && cat libft/libft.h.norm.txt && exit 1)
	@echo "2. C files"
	$Qfind libft -name "*.c" | xargs -L1 sh checker.sh
	$Qmake --no-print-directory clean

.PHONY: all clean fclean re init deinit reinit refresh test

checker: checker.c
	gcc -Wall -Wextra -Werror -o $@ $^
