Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)
MAKE := make --no-print-directory

all: test
clean:
	$Qrm -rf ./tmp
	@printf "\033[0m"
fclean: clean
	$Q$(MAKE) -C src fclean
	$Q$(MAKE) -C test fclean
	@printf "\033[0m"
re:
	$Q$(MAKE) -C src fclean
	$Q$(MAKE) test
init:
	$Q$(MAKE) -C test init
deinit:
	$Q$(MAKE) -C test deinit
refresh:
	$Q$(MAKE) -C test refresh
test:
	$Q$(MAKE) -C test test
	@echo "Some test might need manual review"
publish: test fclean
ifndef GIT_REMOTE_URL
	$(error GIT_REMOTE_URL is undefined)
endif
	$Qcp -r ./src ./tmp
	$Q$(MAKE) -C tmp fclean
	$Qcd tmp && git init && git push $(GIT_REMOTE_URL) master
.PHONY: all clean fclean re init deinit refresh test publish
