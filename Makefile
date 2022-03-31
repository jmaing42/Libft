Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)

all: test
clean:
	$Qrm -rf ./tmp
	@printf "\033[0m"
fclean: clean
	$Qmake -C src fclean
	$Qmake -C test fclean
	@printf "\033[0m"
re:
	$Qmake -C src fclean
	$Qmake test
init:
	$Qmake -C test init
deinit:
	$Qmake -C test deinit
refresh:
	$Qmake -C test refresh
test:
	$Qcd src && norminette
	$Qmake -C src
	$Qmake -C test test
	@echo "Some test might need manual review"
publish: test fclean
ifndef GIT_REMOTE_URL
	$(error GIT_REMOTE_URL is undefined)
endif
	$Qcp -r ./src ./tmp
	$Qmake -C tmp fclean
	$Qcd tmp && git init && git push $(GIT_REMOTE_URL) master
.PHONY: all clean fclean re init deinit refresh test publish
