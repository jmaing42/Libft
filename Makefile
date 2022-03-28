Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)

test:
	$(Q)cd src && norminette
	$(Q)make -C src
	$(Q)make -C test test
	@echo "OK!"
fclean:
	$(Q)rm -rf ./tmp
	$(Q)make -C src fclean
	$(Q)make -C test fclean
publish:
ifndef GIT_REMOTE_URL
	$(error GIT_REMOTE_URL is undefined)
	$(Q)rm -rf ./tmp
endif
	$(Q)cp -r ./src ./tmp
	$(Q)make -C tmp fclean
	$(Q)cd tmp && git init && git push $(GIT_REMOTE_URL) master
	$(Q)rm -rf ./tmp
.PHONY: test fclean publish
