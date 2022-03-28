Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)
TESTS := $(wildcard case*)
RULES := clean fclean re test

all: test
.PHONY: all $(RULES)
define build_common_rule
$1:
	$(Q)$(foreach t,$(TESTS),make -C $t $1 && )echo "OK!"
endef
$(foreach r, \
	$(RULES), \
	$(eval $(call \
		build_common_rule, \
		$r \
	)) \
)
