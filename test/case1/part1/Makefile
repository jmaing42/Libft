Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)
TESTS := $(wildcard ft_*)
RULES := all tester clean fclean test

.PHONY: $(RULES)
define build_common_rule
$1:
	$(Q)$(foreach t,$(TESTS),make -C $t $1 && )true
endef
$(foreach r, \
	$(RULES), \
	$(eval $(call \
		build_common_rule, \
		$r \
	)) \
)
