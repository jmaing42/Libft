Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)
MAKE := make --no-print-directory

all: test
clean:
	$Qrm -rf tmp libft
fclean: clean
re: fclean all
init: | libft_tester
deinit: fclean
	$Qrm -rf libft_tester
refresh:
	$Qrm -rf libft
	$Qcp -r ../../src libft
test: init refresh
	$(MAKE) -C libft_tester a
.PHONY: all clean fclean re init deinit refresh test

libft_tester:
	$Qrm -rf tmp
	$Qgit clone --depth=1 https://github.com/Tripouille/libftTester.git tmp
	@echo "LIBFT_PATH := ../libft" >> tmp/Makefile
	$Qmv tmp libft_tester
