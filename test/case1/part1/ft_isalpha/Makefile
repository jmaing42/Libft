NAME := ft_isalpha

Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)

all: test
clean:
	$(Q)make -C normal clean
	$(Q)make -C asan clean
	$(Q)make -C msan clean
	$(Q)make -C ubsan clean
fclean: clean
	$(Q)make -C normal fclean
	$(Q)make -C asan fclean
	$(Q)make -C msan fclean
	$(Q)make -C ubsan fclean
test:
	$(Q)make -C normal test
	$(Q)make -C asan tester && (make -C asan test || (printf "\033[91m$(NAME) - asan - failed\033[0m\n" && false)) || printf "\033[93m$(NAME) - asan - failed to build (optional test)\033[0m\n"
	$(Q)make -C msan tester && (make -C msan test || (printf "\033[91m$(NAME) - msan - failed\033[0m\n" && false)) || printf "\033[93m$(NAME) - msan - failed to build (optional test)\033[0m\n"
	$(Q)make -C ubsan tester && (make -C ubsan test || (printf "\033[91m$(NAME) - ubsan - failed\033[0m\n" && false)) || printf "\033[93m$(NAME) - ubsan - failed to build (optional test)\033[0m\n"
.PHONY: all clean fclean test
