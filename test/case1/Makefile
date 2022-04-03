BASE_PATH := .
include $(BASE_PATH)/common/variables.mk

all: test
clean:
	$Qrm -rf tmp tmp_* libft_*
fclean: clean
re: fclean all
init:
deinit:
	$Q$(MAKE) -C part1 fclean
reinit: deinit init
refresh: clean
	$Qrm -rf libft
	$Qcp -r $(LIBFT_PATH) libft
	$Q$(MAKE) libft_normal.a
test: refresh
	$Q$(MAKE) -C libft re
	$Q$(MAKE) -C part1 test
	$Q$(MAKE) -C part2 test
	$Q$(MAKE) -C part3 test || printf "\033[93m(optional) Bonus failed\033[0m\n"
help:
	$Qprintf "standalone usage:\n\tLIBFT_PATH=(path to libft) make -C (path to tester)\n\tmake -C (path to tester) # only if variable is set\nplace your variables.local.mk in (path to tester)/common\n"
.PHONY: all clean fclean re init deinit reinit refresh test help

libft_normal.a:
	$Q$(MAKE) libft_asan.a || printf "\033[93m(optional) asan build failed - asan test will be skipped\033[0m\n"
	$Q$(MAKE) libft_msan.a || printf "\033[93m(optional) msan build failed - msan test will be skipped\033[0m\n"
	$Q$(MAKE) libft_ubsan.a || printf "\033[93m(optional) ubsan build failed - ubsan test will be skipped\033[0m\n"
	$Qcommand -v valgrind || printf "\033[93m(optional) valgrind is not available - valgrind test will be skipped\033[0m\n"
	$Qrm -rf tmp
	$Qmkdir tmp
	$Qls -1 libft | grep -E "\\.c\$$" | xargs -L1 -I {} $(CC) -c -Wall -Wextra -Werror -g3 -o tmp/{}.o libft/{}
	$Qar cr libft_normal.a tmp/*.o
	$Qrm -rf tmp
libft_asan.a:
	$Qecho "int main(){return 0;}" | $(CC) -x c - -fsanitize=address -o tmp_asan.exe || (printf "\033[93m(optional) asan not supported\033[0m\n" && false)
	$Qrm -rf tmp
	$Qmkdir tmp
	$Qls -1 libft | grep -E "\\.c\$$" | xargs -L1 -I {} $(CC) -c -Wall -Wextra -Werror -g3 -fsanitize=address -o tmp/{}.o libft/{}
	$Qar cr libft_asan.a tmp/*.o
	$Qrm -rf tmp
libft_msan.a:
	$Qecho "int main(){return 0;}" | $(CC) -x c - -fsanitize=memory -o tmp_msan.exe || (printf "\033[93m(optional) msan not supported\033[0m\n" && false)
	$Qrm -rf tmp
	$Qmkdir tmp
	$Qls -1 libft | grep -E "\\.c\$$" | xargs -L1 -I {} $(CC) -c -Wall -Wextra -Werror -g3 -fsanitize=memory -o tmp/{}.o libft/{}
	$Qar cr libft_msan.a tmp/*.o
	$Qrm -rf tmp
libft_ubsan.a:
	$Qecho "int main(){return 0;}" | $(CC) -x c - -fsanitize=undefined -fsanitize=nullability -fsanitize=float-divide-by-zero -fsanitize=unsigned-integer-overflow -fsanitize=implicit-conversion -fsanitize=local-bounds -o tmp_ubsan.exe || (printf "\033[93m(optional) ubsan not supported\033[0m\n" && false)
	$Qrm -rf tmp
	$Qmkdir tmp
	$Qls -1 libft | grep -E "\\.c\$$" | xargs -L1 -I {} $(CC) -c -Wall -Wextra -Werror -g3 -fsanitize=undefined -fsanitize=nullability -fsanitize=float-divide-by-zero -fsanitize=unsigned-integer-overflow -fsanitize=implicit-conversion -fsanitize=local-bounds -o tmp/{}.o libft/{}
	$Qar cr libft_ubsan.a tmp/*.o
	$Qrm -rf tmp
