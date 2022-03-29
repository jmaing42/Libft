Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)

all: test
clean: | builddir
	$(Q)rm -rf tmp
	$(Q)make -C builddir/default clean
	$(Q)make -C builddir/normal clean
	$(Q)make -C builddir/asan clean
	$(Q)make -C builddir/msan clean
	$(Q)make -C builddir/ubsan clean
fclean:
	$(Q)rm -rf tmp builddir
test: | builddir
	$(Q)make -C builddir/default test
	$(Q)make -C builddir/normal test
	$(Q)[ ! -f ../../libft_asan.a ] || make -C builddir/asan
	$(Q)[ ! -f ../../libft_msan.a ] || make -C builddir/msan
	$(Q)[ ! -f ../../libft_ubsan.a ] || make -C builddir/ubsan
.PHONY: all clean fclean test

builddir:
	$(Q)rm -rf tmp
	$(Q)mkdir tmp
	$(Q)mkdir tmp/default && echo "include ../../../../common/basic_default.mk" > tmp/default/Makefile
	$(Q)mkdir tmp/normal && echo "include ../../../../common/basic_normal.mk" > tmp/normal/Makefile
	$(Q)mkdir tmp/asan && echo "include ../../../../common/basic_asan.mk" > tmp/asan/Makefile
	$(Q)mkdir tmp/msan && echo "include ../../../../common/basic_msan.mk" > tmp/msan/Makefile
	$(Q)mkdir tmp/ubsan && echo "include ../../../../common/basic_ubsan.mk" > tmp/ubsan/Makefile
	$(Q)mv tmp builddir
