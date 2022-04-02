Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)
MAKE := make --no-print-directory

all: test
clean:
	$Qrm -rf ./tmp
	$Q$(MAKE) -C src clean
	$Q$(MAKE) -C test clean
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
reinit:
	$Q$(MAKE) -C test reinit
refresh:
	$Q$(MAKE) -C test refresh
test:
	$Q$(MAKE) -C test test
	@echo "Some test might need manual review"
publish_without_test: fclean
ifndef GIT_REMOTE_URL
	$(error GIT_REMOTE_URL is undefined)
endif
	$Qcp -r ./src ./tmp
	$Q$(MAKE) -C tmp fclean
	$Qprintf "SRCS := %s\n" "$$(cd src && find . -name "*.c" | cut -c 3- | xargs)" >> tmp/Makefile
	$Q(cd tmp && git init && git push $(GIT_REMOTE_URL) master) || (echo "Failed to publish" && rm -rf tmp && false)
	$Qrm -rf tmp
publish: test publish_without_test
.PHONY: all clean fclean re init deinit reinit refresh test publish publish_without_test
