Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)

all: test
clean:
	$(Q)rm -rf tmp tmp_*
fclean: clean
	$(Q)rm -rf tmp libft_*
re: fclean all
init:
deinit:
	$(Q)make -C part1 fclean
refresh: fclean
	$(Q)rm -rf libft
	$(Q)cp -r ../../src libft
	$(Q)make libft_normal.a
test: refresh
	$(Q)make -C libft re
	$(Q)make -C part1 test
	$(Q)make -C part2 test
	$(Q)make -C part3 test || printf "\033[93m(optional) Bonus failed\033[0m\n"
.PHONY: all clean fclean re init deinit refresh test

libft_normal.a:
	$(Q)make libft_asan.a || printf "\033[93m(optional) asan build failed - asan test will be skipped\033[0m\n"
	$(Q)make libft_msan.a || printf "\033[93m(optional) msan build failed - msan test will be skipped\033[0m\n"
	$(Q)make libft_ubsan.a || printf "\033[93m(optional) ubsan build failed - ubsan test will be skipped\033[0m\n"
	$(Q)command -v valgrind || printf "\033[93m(optional) valgrind is not available - valgrind test will be skipped\033[0m\n"
	$(Q)rm -rf tmp
	$(Q)mkdir tmp
	$(Q)ls -1 libft | grep -E "\\.c\$$" | xargs -L1 -I {} gcc -c -Wall -Wextra -Werror -g3 -o tmp/{}.o libft/{}
	$(Q)ar cr libft_normal.a tmp/*.o
	$(Q)rm -rf tmp
libft_asan.a:
	$(Q)echo "int main(){return 0;}" | gcc -x c - -fsanitize=address -o tmp_asan.exe || (printf "\033[93m(optional) asan not supported\033[0m\n" && false)
	$(Q)rm -rf tmp
	$(Q)mkdir tmp
	$(Q)ls -1 libft | grep -E "\\.c\$$" | xargs -L1 -I {} gcc -c -Wall -Wextra -Werror -g3 -fsanitize=address -o tmp/{}.o libft/{}
	$(Q)ar cr libft_asan.a tmp/*.o
	$(Q)rm -rf tmp
libft_msan.a:
	$(Q)echo "int main(){return 0;}" | gcc -x c - -fsanitize=memory -o tmp_msan.exe || (printf "\033[93m(optional) msan not supported\033[0m\n" && false)
	$(Q)rm -rf tmp
	$(Q)mkdir tmp
	$(Q)ls -1 libft | grep -E "\\.c\$$" | xargs -L1 -I {} gcc -c -Wall -Wextra -Werror -g3 -fsanitize=memory -o tmp/{}.o libft/{}
	$(Q)ar cr libft_msan.a tmp/*.o
	$(Q)rm -rf tmp
libft_ubsan.a:
	$(Q)echo "int main(){return 0;}" | gcc -x c - -fsanitize=undefined -fsanitize=nullability -fsanitize=float-divide-by-zero -fsanitize=unsigned-integer-overflow -fsanitize=implicit-conversion -fsanitize=local-bounds -o tmp_ubsan.exe || (printf "\033[93m(optional) ubsan not supported\033[0m\n" && false)
	$(Q)rm -rf tmp
	$(Q)mkdir tmp
	$(Q)ls -1 libft | grep -E "\\.c\$$" | xargs -L1 -I {} gcc -c -Wall -Wextra -Werror -g3 -fsanitize=undefined -fsanitize=nullability -fsanitize=float-divide-by-zero -fsanitize=unsigned-integer-overflow -fsanitize=implicit-conversion -fsanitize=local-bounds -o tmp/{}.o libft/{}
	$(Q)ar cr libft_ubsan.a tmp/*.o
	$(Q)rm -rf tmp
