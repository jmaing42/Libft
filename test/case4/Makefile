Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)

all: test
clean:
	$Qrm -rf tmp libft
fclean: clean
re:
	$Q$(MAKE) fclean
	$Q$(MAKE) all
init: | libft_war_machine
deinit: fclean
	$Qrm -rf libft_war_machine
reinit:
	$Q$(MAKE) deinit
	$Q$(MAKE) init
refresh:
	$Qrm -rf libft
	$Qcp -r ../../src libft
test: init refresh
ifeq ($(OS),Windows_NT)
	@echo "Windows detected, no libft_war_machine"
else
ifeq ($(shell uname -s),Darwin)
	$QPATH_LIBFT="$(abspath libft)" sh libft_war_machine/grademe.sh
else
	@echo "Non-mac OS detected, no libft_war_machine"
endif
endif
.PHONY: all clean fclean re init deinit reinit refresh test

libft_war_machine:
	$Qrm -rf tmp
	$Qgit clone --depth=1 https://github.com/y3ll0w42/libft-war-machine tmp
	$Qcp libft_war_machine.env tmp/my_config.sh
	$Qmv tmp libft_war_machine
