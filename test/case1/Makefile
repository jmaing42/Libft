Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)
CC = clang

all: test
clean:
	$Qrm -rf tmp tmp_*
fclean: clean
	$Qrm -rf tmp libft_*
re: fclean all
init:
deinit:
	$Qmake -C part1 fclean
refresh: fclean
	$Qrm -rf libft
	$Qcp -r ../../src libft
	$Qmake libft_normal.a
test: refresh
	$Qmake -C libft re
	$Qmake -C part1 test
	$Qmake -C part2 test
	$Qmake -C part3 test || printf "\033[93m(optional) Bonus failed\033[0m\n"
.PHONY: all clean fclean re init deinit refresh test

libft_normal.a:
	$Qmake libft_asan.a || printf "\033[93m(optional) asan build failed - asan test will be skipped\033[0m\n"
	$Qmake libft_msan.a || printf "\033[93m(optional) msan build failed - msan test will be skipped\033[0m\n"
	$Qmake libft_ubsan.a || printf "\033[93m(optional) ubsan build failed - ubsan test will be skipped\033[0m\n"
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
