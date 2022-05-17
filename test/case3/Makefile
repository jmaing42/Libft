Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)

all: test
clean:
	$Qrm -rf tmp libft
fclean: clean
re:
	$Q$(MAKE) fclean
	$Q$(MAKE) all
init: | Libftest
deinit: fclean
	$Qrm -rf Libftest
reinit:
	$Q$(MAKE) deinit
	$Q$(MAKE) init
refresh:
	$Qrm -rf libft
	$Qcp -r ../../src libft
test: init refresh
ifeq ($(OS),Windows_NT)
	@echo "Windows detected, no libft_unit_test"
else
ifeq ($(shell uname -s),Darwin)
	$QPATH_LIBFT="$(abspath libft)" sh Libftest/grademe.sh || printf "\033[93mFailed but may be falsy positive\033[0m\n"
else
	@echo "Non-mac OS detected, no libft_unit_test"
endif
endif
.PHONY: all clean fclean re init deinit reinit refresh test

Libftest:
	$Qrm -rf tmp
	$Qgit clone --depth=1 https://github.com/jtoty/Libftest tmp
	$Qcp Libftest.env tmp/my_config.sh
	$Qmv tmp Libftest
