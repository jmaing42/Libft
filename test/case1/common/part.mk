include $(BASE_PATH)/common/variables.mk
TESTS += $(wildcard ft_*)
RULES := all tester clean fclean test

.PHONY: $(RULES)
define build_common_rule
$1:
	$Q$(foreach t,$(TESTS),$(MAKE) -C $t $1 && )true
	$Q$(foreach t,$(OPTIONAL_TESTS),$(MAKE) -C $t $1 || (echo "Optional test $t failed." && false) ; )true
endef
$(foreach r, \
	$(RULES), \
	$(eval $(call \
		build_common_rule, \
		$r \
	)) \
)
