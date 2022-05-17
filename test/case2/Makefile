Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)
MAKE := $(MAKE) $(if $(filter 1,$(V) $(VERBOSE)),,--no-print-directory)

all: test
clean:
	$Qrm -rf tmp libft
ifeq ($(OS),Windows_NT)
	@echo "Windows detected, no libft_unit_test"
else
ifeq ($(shell uname -s),Darwin)
	$Q[ ! -d libft_unit_test ] || $(MAKE) -C libft_unit_test clean
else
	@echo "Non-mac OS detected, no libft_unit_test"
endif
endif
fclean:
	$Qrm -rf tmp libft
ifeq ($(OS),Windows_NT)
	@echo "Windows detected, no libft_unit_test"
else
ifeq ($(shell uname -s),Darwin)
	$Q[ ! -d libft_unit_test ] || $(MAKE) -C libft_unit_test fclean
else
	@echo "Non-mac OS detected, no libft_unit_test"
endif
endif
re:
	$Q$(MAKE) fclean
	$Q$(MAKE) all
init: | libft_unit_test
deinit:
	$Qrm -rf tmp libft libft_unit_test
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
	$Q$(MAKE) -C libft_unit_test clean
	$QCFLAGS= $(MAKE) -e -j 1 -C libft_unit_test f || printf "\033[93mError occurred...\033[0m\n"
else
	@echo "Non-mac OS detected, no libft_unit_test"
endif
endif
.PHONY: all clean fclean re init deinit reinit refresh test

libft_unit_test:
	$Qrm -rf tmp
	$Qgit clone --depth=1 https://github.com/alelievr/libft-unit-test.git tmp
	$Qmv tmp libft_unit_test
