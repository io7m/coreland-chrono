# auto generated - do not edit

default: all

all: sysdeps.out UNIT_TESTS/t_cald_fmjd UNIT_TESTS/t_cald_fmt \
	UNIT_TESTS/t_cald_mjd UNIT_TESTS/t_cald_scan caldate.a ctxt/ctxt.a \
	tai.a taia.a 

sysdeps: sysdeps.out
sysdeps.out:
	SYSDEPS/sysdep-header sysdeps.out
	(cd SYSDEPS && make)
sysdeps_clean:
	(cd SYSDEPS && make clean)
	rm -f sysdeps.out

flags-corelib: sysdeps.out
libs-corelib: sysdeps.out
flags-integer: sysdeps.out
libs-integer: sysdeps.out

UNIT_TESTS/t_assert.o:\
	cc-compile UNIT_TESTS/t_assert.c UNIT_TESTS/t_assert.h 
	./cc-compile UNIT_TESTS/t_assert.c
UNIT_TESTS/t_cald_fmjd:\
	cc-link UNIT_TESTS/t_cald_fmjd.ld UNIT_TESTS/t_cald_fmjd.o \
	UNIT_TESTS/t_assert.o UNIT_TESTS/t_util.o caldate.a 
	./cc-link UNIT_TESTS/t_cald_fmjd UNIT_TESTS/t_cald_fmjd.o \
	UNIT_TESTS/t_assert.o UNIT_TESTS/t_util.o caldate.a 
UNIT_TESTS/t_cald_fmjd.o:\
	cc-compile UNIT_TESTS/t_cald_fmjd.c UNIT_TESTS/t_assert.h \
	UNIT_TESTS/t_util.h caldate.h 
	./cc-compile UNIT_TESTS/t_cald_fmjd.c
UNIT_TESTS/t_cald_fmt:\
	cc-link UNIT_TESTS/t_cald_fmt.ld UNIT_TESTS/t_cald_fmt.o \
	UNIT_TESTS/t_assert.o UNIT_TESTS/t_util.o caldate.a 
	./cc-link UNIT_TESTS/t_cald_fmt UNIT_TESTS/t_cald_fmt.o \
	UNIT_TESTS/t_assert.o UNIT_TESTS/t_util.o caldate.a 
UNIT_TESTS/t_cald_fmt.o:\
	cc-compile UNIT_TESTS/t_cald_fmt.c UNIT_TESTS/t_assert.h \
	UNIT_TESTS/t_util.h caldate.h 
	./cc-compile UNIT_TESTS/t_cald_fmt.c
UNIT_TESTS/t_cald_mjd:\
	cc-link UNIT_TESTS/t_cald_mjd.ld UNIT_TESTS/t_cald_mjd.o \
	UNIT_TESTS/t_assert.o UNIT_TESTS/t_util.o caldate.a 
	./cc-link UNIT_TESTS/t_cald_mjd UNIT_TESTS/t_cald_mjd.o \
	UNIT_TESTS/t_assert.o UNIT_TESTS/t_util.o caldate.a 
UNIT_TESTS/t_cald_mjd.o:\
	cc-compile UNIT_TESTS/t_cald_mjd.c UNIT_TESTS/t_assert.h \
	UNIT_TESTS/t_util.h caldate.h 
	./cc-compile UNIT_TESTS/t_cald_mjd.c
UNIT_TESTS/t_cald_scan:\
	cc-link UNIT_TESTS/t_cald_scan.ld UNIT_TESTS/t_cald_scan.o \
	UNIT_TESTS/t_assert.o UNIT_TESTS/t_util.o caldate.a 
	./cc-link UNIT_TESTS/t_cald_scan UNIT_TESTS/t_cald_scan.o \
	UNIT_TESTS/t_assert.o UNIT_TESTS/t_util.o caldate.a 
UNIT_TESTS/t_cald_scan.o:\
	cc-compile UNIT_TESTS/t_cald_scan.c UNIT_TESTS/t_assert.h \
	UNIT_TESTS/t_util.h caldate.h 
	./cc-compile UNIT_TESTS/t_cald_scan.c
UNIT_TESTS/t_util.o:\
	cc-compile UNIT_TESTS/t_util.c UNIT_TESTS/t_util.h 
	./cc-compile UNIT_TESTS/t_util.c
cald_fmt.o:\
	cc-compile cald_fmt.c caldate.h 
	./cc-compile cald_fmt.c
cald_frommjd.o:\
	cc-compile cald_frommjd.c caldate.h 
	./cc-compile cald_frommjd.c
cald_mjd.o:\
	cc-compile cald_mjd.c caldate.h 
	./cc-compile cald_mjd.c
cald_scan.o:\
	cc-compile cald_scan.c caldate.h 
	./cc-compile cald_scan.c
caldate.a:\
	cc-slib caldate.sld cald_fmt.o cald_frommjd.o cald_mjd.o \
	cald_scan.o 
	./cc-slib caldate cald_fmt.o cald_frommjd.o cald_mjd.o cald_scan.o 
cc-compile: conf-cc conf-cctype conf-cflags sysdeps.out \
	flags-integer flags-corelib 
cc-link: conf-ld conf-ldflags sysdeps.out libs-integer \
	libs-integer-C libs-corelib libs-corelib-C 
cc-slib: conf-systype 
conf-cctype:\
	conf-systype conf-cc mk-cctype 
	./mk-cctype > conf-cctype
conf-systype:\
	mk-systype 
	./mk-systype > conf-systype
ctxt/ctxt.a:\
	cc-slib ctxt/ctxt.sld ctxt/leapsec.o 
	./cc-slib ctxt/ctxt ctxt/leapsec.o 
ctxt/leapsec.c: mk-ctxt conf-leapsec
	rm -f ctxt/leapsec.c
	./mk-ctxt ctxt_leapsec < conf-leapsec > ctxt/leapsec.c

ctxt/leapsec.o:\
	cc-compile ctxt/leapsec.c 
	./cc-compile ctxt/leapsec.c
mk-cctype: conf-cc conf-systype 
mk-ctxt.o:\
	cc-compile mk-ctxt.c
	./cc-compile mk-ctxt.c
mk-ctxt:\
	cc-link mk-ctxt.o mk-ctxt.ld
	./cc-link mk-ctxt mk-ctxt.o
mk-systype: conf-cc 
tai.a:\
	cc-slib tai.sld tai_add.o tai_approx.o tai_diff.o tai_now.o \
	tai_pack.o tai_sub.o tai_unpack.o 
	./cc-slib tai tai_add.o tai_approx.o tai_diff.o tai_now.o \
	tai_pack.o tai_sub.o tai_unpack.o 
tai_add.o:\
	cc-compile tai_add.c tai.h 
	./cc-compile tai_add.c
tai_approx.o:\
	cc-compile tai_approx.c tai.h 
	./cc-compile tai_approx.c
tai_diff.o:\
	cc-compile tai_diff.c tai.h 
	./cc-compile tai_diff.c
tai_now.o:\
	cc-compile tai_now.c tai.h 
	./cc-compile tai_now.c
tai_pack.o:\
	cc-compile tai_pack.c tai.h 
	./cc-compile tai_pack.c
tai_sub.o:\
	cc-compile tai_sub.c tai.h 
	./cc-compile tai_sub.c
tai_unpack.o:\
	cc-compile tai_unpack.c tai.h 
	./cc-compile tai_unpack.c
taia.a:\
	cc-slib taia.sld taia_add.o taia_approx.o taia_diff.o \
	taia_fmtfrac.o taia_frac.o taia_half.o taia_now.o taia_pack.o \
	taia_sub.o taia_tai.o taia_unpack.o 
	./cc-slib taia taia_add.o taia_approx.o taia_diff.o taia_fmtfrac.o \
	taia_frac.o taia_half.o taia_now.o taia_pack.o taia_sub.o taia_tai.o \
	taia_unpack.o 
taia_add.o:\
	cc-compile taia_add.c taia.h tai.h 
	./cc-compile taia_add.c
taia_approx.o:\
	cc-compile taia_approx.c taia.h tai.h 
	./cc-compile taia_approx.c
taia_diff.o:\
	cc-compile taia_diff.c taia.h 
	./cc-compile taia_diff.c
taia_fmtfrac.o:\
	cc-compile taia_fmtfrac.c taia.h 
	./cc-compile taia_fmtfrac.c
taia_frac.o:\
	cc-compile taia_frac.c taia.h 
	./cc-compile taia_frac.c
taia_half.o:\
	cc-compile taia_half.c taia.h tai.h 
	./cc-compile taia_half.c
taia_now.o:\
	cc-compile taia_now.c taia.h tai.h 
	./cc-compile taia_now.c
taia_pack.o:\
	cc-compile taia_pack.c taia.h tai.h 
	./cc-compile taia_pack.c
taia_sub.o:\
	cc-compile taia_sub.c taia.h tai.h 
	./cc-compile taia_sub.c
taia_tai.o:\
	cc-compile taia_tai.c taia.h tai.h 
	./cc-compile taia_tai.c
taia_unpack.o:\
	cc-compile taia_unpack.c taia.h tai.h 
	./cc-compile taia_unpack.c
clean-all: sysdeps_clean obj_clean 
clean: obj_clean
obj_clean: 
	rm -f UNIT_TESTS/t_assert.o UNIT_TESTS/t_cald_fmjd \
	UNIT_TESTS/t_cald_fmjd.o UNIT_TESTS/t_cald_fmt \
	UNIT_TESTS/t_cald_fmt.o UNIT_TESTS/t_cald_mjd \
	UNIT_TESTS/t_cald_mjd.o UNIT_TESTS/t_cald_scan \
	UNIT_TESTS/t_cald_scan.o UNIT_TESTS/t_util.o cald_fmt.o \
	cald_frommjd.o cald_mjd.o cald_scan.o caldate.a ctxt/ctxt.a \
	ctxt/leapsec.c ctxt/leapsec.o tai.a tai_add.o tai_approx.o \
	tai_diff.o tai_now.o tai_pack.o tai_sub.o tai_unpack.o taia.a \
	taia_add.o taia_approx.o taia_diff.o taia_fmtfrac.o taia_frac.o \
	taia_half.o taia_now.o taia_pack.o taia_sub.o taia_tai.o \
	taia_unpack.o 

regen:
	cpj-genmk > Makefile.tmp && mv Makefile.tmp Makefile

