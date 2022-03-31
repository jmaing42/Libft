Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)

all: test
clean: | builddir
	$Qrm -rf tmp
	$Qmake -C builddir/default clean
	$Qmake -C builddir/normal clean
	$Qmake -C builddir/asan clean
	$Qmake -C builddir/msan clean
	$Qmake -C builddir/ubsan clean
fclean:
	$Qrm -rf tmp builddir
test: | builddir
	$Qmake -C builddir/default test
	$Qmake -C builddir/normal test
	$Q[ ! -f ../../libft_asan.a ] || make -C builddir/asan
	$Q[ ! -f ../../libft_msan.a ] || make -C builddir/msan
	$Q[ ! -f ../../libft_ubsan.a ] || make -C builddir/ubsan
.PHONY: all clean fclean test

builddir:
	$Qrm -rf tmp
	$Qmkdir tmp
	$Qmkdir tmp/default && echo "include ../../../../common/basic_default.mk" > tmp/default/Makefile
	$Qmkdir tmp/normal && echo "include ../../../../common/basic_normal.mk" > tmp/normal/Makefile
	$Qmkdir tmp/asan && echo "include ../../../../common/basic_asan.mk" > tmp/asan/Makefile
	$Qmkdir tmp/msan && echo "include ../../../../common/basic_msan.mk" > tmp/msan/Makefile
	$Qmkdir tmp/ubsan && echo "include ../../../../common/basic_ubsan.mk" > tmp/ubsan/Makefile
	$Qmv tmp builddir
