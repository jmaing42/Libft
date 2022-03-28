Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)

all: test
clean:
	$(Q)rm -rf ./tmp
fclean: clean
	$(Q)make -C src fclean
	$(Q)make -C test fclean
re: fclean all
test:
	$(Q)cd src && norminette
	$(Q)make -C src
	$(Q)make -C test test
	@echo "OK!"
publish: clean
ifndef GIT_REMOTE_URL
	$(error GIT_REMOTE_URL is undefined)
endif
	$(Q)cp -r ./src ./tmp
	$(Q)make -C tmp fclean
	$(Q)cd tmp && git init && git push $(GIT_REMOTE_URL) master
.PHONY: all clean fclean re test publish
