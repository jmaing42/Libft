Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)
CASES := $(sort $(wildcard case*))
RULES := all clean fclean re init deinit refresh test

.PHONY: $(RULES)
define build_common_rule
$1:
	$(Q)$(foreach t,$(CASES),make -C $t $1 && )echo "OK!"
endef
$(foreach r, \
	$(RULES), \
	$(eval $(call \
		build_common_rule, \
		$r \
	)) \
)
