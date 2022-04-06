Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)
MAKE := make $(if $(filter 1,$(V) $(VERBOSE)),,--no-print-directory)

all: test
clean:
	$Qrm -rf tmp libft
	$Q[ -d libft_tester ] && mkdir -p libft && echo "clean:" > libft/Makefile && $(MAKE) -C libft_tester clean && rm -rf libft || true
fclean: clean
	$Q[ -d libft_tester ] && mkdir -p libft && echo "fclean:" > libft/Makefile && $(MAKE) -C libft_tester fclean && rm -rf libft || true
re: fclean all
init: | libft_tester
deinit: fclean
	$Qrm -rf libft_tester
reinit: deinit init
refresh:
	$Qrm -rf libft
	$Qcp -r ../../src libft
	$Q[ ! -d libft_tester ] || $(MAKE) -C libft_tester clean
test: init refresh
	$Q$(MAKE) -C libft_tester a
.PHONY: all clean fclean re init deinit reinit refresh test

libft_tester:
	$Qrm -rf tmp
	$Qgit clone --depth=1 https://github.com/Tripouille/libftTester.git tmp
	@echo "LIBFT_PATH := ../libft" >> tmp/Makefile
	$Qmv tmp libft_tester
