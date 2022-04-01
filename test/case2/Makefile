Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)
MAKE := make --no-print-directory

all: test
clean:
	$Qrm -rf tmp libft
	$Q[ -d libft_unit_test ] && $(MAKE) -C libft_unit_test clean
fclean:
	$Qrm -rf tmp libft
	$Q[ -d libft_unit_test ] && $(MAKE) -C libft_unit_test fclean
re: fclean all
init: | libft_unit_test
deinit:
	$Qrm -rf tmp
	$Qrm -rf libft_unit_test
refresh:
	$Qrm -rf libft
	$Qcp -r ../../src libft
test: init refresh
ifeq ($(OS),Windows_NT)
	@echo "Windows detected, no libft_unit_test"
else
ifeq ($(shell uname -s),Darwin)
	$Q$(MAKE) -C libft_unit_test f
else
	@echo "Non-mac OS detected, no libft_unit_test"
endif
endif
.PHONY: all clean fclean re init deinit refresh test

libft_unit_test:
	$Qrm -rf tmp
	$Qgit clone --depth=1 https://github.com/alelievr/libft-unit-test.git tmp
	$Qmv tmp libft_unit_test
