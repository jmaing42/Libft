Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)
MAKE := make --no-print-directory
TESTS := $(wildcard ft_*)
RULES := all tester clean fclean test

.PHONY: $(RULES)
define build_common_rule
$1:
	$Q$(foreach t,$(TESTS),$(MAKE) -C $t $1 && )true
endef
$(foreach r, \
	$(RULES), \
	$(eval $(call \
		build_common_rule, \
		$r \
	)) \
)
