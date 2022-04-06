Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)
MAKE := make $(if $(filter 1,$(V) $(VERBOSE)),,--no-print-directory)

TESTS += $(wildcard ft_*)
RULES := all clean fclean re Makefile

.PHONY: $(RULES)
define build_common_rule
$1:
	$Q$(foreach t,$(TESTS),$(MAKE) -C $t -f ../common.mk $1 && )true
endef
$(foreach r, \
	$(RULES), \
	$(eval $(call \
		build_common_rule, \
		$r \
	)) \
)

.PHONY: clean_makefiles
clean: clean_makefiles
clean_makefiles:
	ls | grep -E "ft_.*\$$" | xargs -L1 -I {} rm {}/Makefile
