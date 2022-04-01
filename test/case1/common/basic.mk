include $(BASE_PATH)/common/variables.mk

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
	$Q[ ! -f $(BASE_PATH)/libft_asan.a ] || make -C builddir/asan
	$Q[ ! -f $(BASE_PATH)/libft_msan.a ] || make -C builddir/msan
	$Q[ ! -f $(BASE_PATH)/libft_ubsan.a ] || make -C builddir/ubsan
.PHONY: all clean fclean test

builddir:
	$Qrm -rf tmp
	$Qmkdir tmp
	$Qmkdir tmp/default && printf "BASE_PATH := ../../$(BASE_PATH)\ninclude \$$(BASE_PATH)/common/basic_default.mk\n" > tmp/default/Makefile
	$Qmkdir tmp/normal && printf "BASE_PATH := ../../$(BASE_PATH)\ninclude \$$(BASE_PATH)/common/basic_normal.mk\n" > tmp/normal/Makefile
	$Qmkdir tmp/asan && printf "BASE_PATH := ../../$(BASE_PATH)\ninclude \$$(BASE_PATH)/common/basic_asan.mk\n" > tmp/asan/Makefile
	$Qmkdir tmp/msan && printf "BASE_PATH := ../../$(BASE_PATH)\ninclude \$$(BASE_PATH)/common/basic_msan.mk\n" > tmp/msan/Makefile
	$Qmkdir tmp/ubsan && printf "BASE_PATH := ../../$(BASE_PATH)\ninclude \$$(BASE_PATH)/common/basic_ubsan.mk\n" > tmp/ubsan/Makefile
	$Qmv tmp builddir
