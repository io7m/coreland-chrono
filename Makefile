# auto generated - do not edit

default: all

all: sysdeps.out UNIT_TESTS/t_cald_fmjd UNIT_TESTS/t_cald_fmt \
	UNIT_TESTS/t_cald_mjd UNIT_TESTS/t_cald_scan UNIT_TESTS/t_calt_fmt \
	UNIT_TESTS/t_calt_scan caldate.a caltime.a chrono-conf ctxt/ctxt.a \
	deinstaller inst-check inst-copy inst-dir inst-link installer \
	instchk leapsecs leapsecs.a tai.a tai64 tai64n tai64na taia.a 

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
UNIT_TESTS/t_calt_fmt:\
	cc-link UNIT_TESTS/t_calt_fmt.ld UNIT_TESTS/t_calt_fmt.o \
	UNIT_TESTS/t_assert.o UNIT_TESTS/t_util.o caltime.a caldate.a 
	./cc-link UNIT_TESTS/t_calt_fmt UNIT_TESTS/t_calt_fmt.o \
	UNIT_TESTS/t_assert.o UNIT_TESTS/t_util.o caltime.a caldate.a 
UNIT_TESTS/t_calt_fmt.o:\
	cc-compile UNIT_TESTS/t_calt_fmt.c UNIT_TESTS/t_assert.h \
	UNIT_TESTS/t_util.h caltime.h 
	./cc-compile UNIT_TESTS/t_calt_fmt.c
UNIT_TESTS/t_calt_scan:\
	cc-link UNIT_TESTS/t_calt_scan.ld UNIT_TESTS/t_calt_scan.o \
	UNIT_TESTS/t_assert.o UNIT_TESTS/t_util.o caltime.a caldate.a 
	./cc-link UNIT_TESTS/t_calt_scan UNIT_TESTS/t_calt_scan.o \
	UNIT_TESTS/t_assert.o UNIT_TESTS/t_util.o caltime.a caldate.a 
UNIT_TESTS/t_calt_scan.o:\
	cc-compile UNIT_TESTS/t_calt_scan.c UNIT_TESTS/t_assert.h \
	UNIT_TESTS/t_util.h caltime.h 
	./cc-compile UNIT_TESTS/t_calt_scan.c
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
cald_norm.o:\
	cc-compile cald_norm.c caldate.h 
	./cc-compile cald_norm.c
cald_scan.o:\
	cc-compile cald_scan.c caldate.h 
	./cc-compile cald_scan.c
caldate.a:\
	cc-slib caldate.sld cald_fmt.o cald_frommjd.o cald_mjd.o \
	cald_norm.o cald_scan.o 
	./cc-slib caldate cald_fmt.o cald_frommjd.o cald_mjd.o cald_norm.o \
	cald_scan.o 
calt_fmt.o:\
	cc-compile calt_fmt.c caldate.h caltime.h 
	./cc-compile calt_fmt.c
calt_scan.o:\
	cc-compile calt_scan.c caldate.h caltime.h 
	./cc-compile calt_scan.c
caltime.a:\
	cc-slib caltime.sld calt_fmt.o calt_scan.o 
	./cc-slib caltime calt_fmt.o calt_scan.o 
cc-compile: conf-cc conf-cctype conf-cflags sysdeps.out \
	flags-integer flags-corelib 
cc-link: conf-ld conf-ldflags sysdeps.out libs-integer \
	libs-integer-C libs-corelib libs-corelib-C 
cc-slib: conf-systype 
chrono-conf:\
	cc-link chrono-conf.ld chrono-conf.o ctxt/ctxt.a 
	./cc-link chrono-conf chrono-conf.o ctxt/ctxt.a 
chrono-conf.o:\
	cc-compile chrono-conf.c ctxt.h 
	./cc-compile chrono-conf.c
conf-cctype:\
	conf-systype conf-cc mk-cctype 
	./mk-cctype > conf-cctype
conf-sosuffix:\
	mk-sosuffix 
	./mk-sosuffix > conf-sosuffix
conf-systype:\
	mk-systype 
	./mk-systype > conf-systype
ctxt/bindir.c: mk-ctxt conf-bindir
	rm -f ctxt/bindir.c
	./mk-ctxt ctxt_bindir < conf-bindir > ctxt/bindir.c

ctxt/bindir.o:\
	cc-compile ctxt/bindir.c 
	./cc-compile ctxt/bindir.c
ctxt/ctxt.a:\
	cc-slib ctxt/ctxt.sld ctxt/bindir.o ctxt/dlibdir.o ctxt/incdir.o \
	ctxt/leapsec.o ctxt/repos.o ctxt/slibdir.o ctxt/version.o 
	./cc-slib ctxt/ctxt ctxt/bindir.o ctxt/dlibdir.o ctxt/incdir.o \
	ctxt/leapsec.o ctxt/repos.o ctxt/slibdir.o ctxt/version.o 
ctxt/dlibdir.c: mk-ctxt conf-dlibdir
	rm -f ctxt/dlibdir.c
	./mk-ctxt ctxt_dlibdir < conf-dlibdir > ctxt/dlibdir.c

ctxt/dlibdir.o:\
	cc-compile ctxt/dlibdir.c 
	./cc-compile ctxt/dlibdir.c
ctxt/incdir.c: mk-ctxt conf-incdir
	rm -f ctxt/incdir.c
	./mk-ctxt ctxt_incdir < conf-incdir > ctxt/incdir.c

ctxt/incdir.o:\
	cc-compile ctxt/incdir.c 
	./cc-compile ctxt/incdir.c
ctxt/leapsec.c: mk-ctxt conf-leapsec
	rm -f ctxt/leapsec.c
	./mk-ctxt ctxt_leapsec < conf-leapsec > ctxt/leapsec.c

ctxt/leapsec.o:\
	cc-compile ctxt/leapsec.c 
	./cc-compile ctxt/leapsec.c
ctxt/repos.c: mk-ctxt conf-repos
	rm -f ctxt/repos.c
	./mk-ctxt ctxt_repos < conf-repos > ctxt/repos.c

ctxt/repos.o:\
	cc-compile ctxt/repos.c 
	./cc-compile ctxt/repos.c
ctxt/slibdir.c: mk-ctxt conf-slibdir
	rm -f ctxt/slibdir.c
	./mk-ctxt ctxt_slibdir < conf-slibdir > ctxt/slibdir.c

ctxt/slibdir.o:\
	cc-compile ctxt/slibdir.c 
	./cc-compile ctxt/slibdir.c
ctxt/version.c: mk-ctxt VERSION
	rm -f ctxt/version.c
	./mk-ctxt ctxt_version < VERSION > ctxt/version.c

ctxt/version.o:\
	cc-compile ctxt/version.c 
	./cc-compile ctxt/version.c
deinstaller:\
	cc-link deinstaller.ld deinstaller.o insthier.o install_core.o \
	install_error.o ctxt/ctxt.a 
	./cc-link deinstaller deinstaller.o insthier.o install_core.o \
	install_error.o ctxt/ctxt.a 
deinstaller.o:\
	cc-compile deinstaller.c install.h 
	./cc-compile deinstaller.c
inst-check:\
	cc-link inst-check.ld inst-check.o install_error.o 
	./cc-link inst-check inst-check.o install_error.o 
inst-check.o:\
	cc-compile inst-check.c install.h 
	./cc-compile inst-check.c
inst-copy:\
	cc-link inst-copy.ld inst-copy.o install_error.o 
	./cc-link inst-copy inst-copy.o install_error.o 
inst-copy.o:\
	cc-compile inst-copy.c install.h 
	./cc-compile inst-copy.c
inst-dir:\
	cc-link inst-dir.ld inst-dir.o install_error.o 
	./cc-link inst-dir inst-dir.o install_error.o 
inst-dir.o:\
	cc-compile inst-dir.c install.h 
	./cc-compile inst-dir.c
inst-link:\
	cc-link inst-link.ld inst-link.o install_error.o 
	./cc-link inst-link inst-link.o install_error.o 
inst-link.o:\
	cc-compile inst-link.c install.h 
	./cc-compile inst-link.c
install_core.o:\
	cc-compile install_core.c install.h 
	./cc-compile install_core.c
install_error.o:\
	cc-compile install_error.c install.h 
	./cc-compile install_error.c
installer:\
	cc-link installer.ld installer.o insthier.o install_core.o \
	install_error.o ctxt/ctxt.a 
	./cc-link installer installer.o insthier.o install_core.o \
	install_error.o ctxt/ctxt.a 
installer.o:\
	cc-compile installer.c install.h 
	./cc-compile installer.c
instchk:\
	cc-link instchk.ld instchk.o insthier.o install_core.o \
	install_error.o ctxt/ctxt.a 
	./cc-link instchk instchk.o insthier.o install_core.o \
	install_error.o ctxt/ctxt.a 
instchk.o:\
	cc-compile instchk.c install.h 
	./cc-compile instchk.c
insthier.o:\
	cc-compile insthier.c ctxt.h install.h 
	./cc-compile insthier.c
leaps_data.o:\
	cc-compile leaps_data.c ctxt.h leapsecs.h 
	./cc-compile leaps_data.c
leaps_free.o:\
	cc-compile leaps_free.c leapsecs.h 
	./cc-compile leaps_free.c
leaps_init.o:\
	cc-compile leaps_init.c leapsecs.h tai.h 
	./cc-compile leaps_init.c
leaps_read.o:\
	cc-compile leaps_read.c leapsecs.h 
	./cc-compile leaps_read.c
leapsecs:\
	cc-link leapsecs.ld leapsecs.o caldate.a tai.a 
	./cc-link leapsecs leapsecs.o caldate.a tai.a 
leapsecs.a:\
	cc-slib leapsecs.sld leaps_data.o leaps_free.o leaps_init.o \
	leaps_read.o 
	./cc-slib leapsecs leaps_data.o leaps_free.o leaps_init.o \
	leaps_read.o 
leapsecs.o:\
	cc-compile leapsecs.c caldate.h tai.h 
	./cc-compile leapsecs.c
mk-cctype: conf-cc conf-systype 
mk-ctxt.o:\
	cc-compile mk-ctxt.c
	./cc-compile mk-ctxt.c
mk-ctxt:\
	cc-link mk-ctxt.o mk-ctxt.ld
	./cc-link mk-ctxt mk-ctxt.o
mk-sosuffix: conf-systype 
mk-systype: conf-cc 
tai.a:\
	cc-slib tai.sld tai_add.o tai_approx.o tai_diff.o tai_label.o \
	tai_now.o tai_pack.o tai_sub.o tai_unix.o tai_unpack.o 
	./cc-slib tai tai_add.o tai_approx.o tai_diff.o tai_label.o \
	tai_now.o tai_pack.o tai_sub.o tai_unix.o tai_unpack.o 
tai64:\
	cc-link tai64.ld tai64.o tai.a 
	./cc-link tai64 tai64.o tai.a 
tai64.o:\
	cc-compile tai64.c tai.h 
	./cc-compile tai64.c
tai64n:\
	cc-link tai64n.ld tai64n.o taia.a tai.a 
	./cc-link tai64n tai64n.o taia.a tai.a 
tai64n.o:\
	cc-compile tai64n.c taia.h 
	./cc-compile tai64n.c
tai64na:\
	cc-link tai64na.ld tai64na.o taia.a tai.a 
	./cc-link tai64na tai64na.o taia.a tai.a 
tai64na.o:\
	cc-compile tai64na.c taia.h 
	./cc-compile tai64na.c
tai_add.o:\
	cc-compile tai_add.c tai.h 
	./cc-compile tai_add.c
tai_approx.o:\
	cc-compile tai_approx.c tai.h 
	./cc-compile tai_approx.c
tai_diff.o:\
	cc-compile tai_diff.c tai.h 
	./cc-compile tai_diff.c
tai_label.o:\
	cc-compile tai_label.c tai.h 
	./cc-compile tai_label.c
tai_now.o:\
	cc-compile tai_now.c tai.h 
	./cc-compile tai_now.c
tai_pack.o:\
	cc-compile tai_pack.c tai.h 
	./cc-compile tai_pack.c
tai_sub.o:\
	cc-compile tai_sub.c tai.h 
	./cc-compile tai_sub.c
tai_unix.o:\
	cc-compile tai_unix.c tai.h 
	./cc-compile tai_unix.c
tai_unpack.o:\
	cc-compile tai_unpack.c tai.h 
	./cc-compile tai_unpack.c
taia.a:\
	cc-slib taia.sld taia_add.o taia_approx.o taia_diff.o \
	taia_fmtfrac.o taia_frac.o taia_half.o taia_label.o taia_now.o \
	taia_pack.o taia_sub.o taia_tai.o taia_unpack.o 
	./cc-slib taia taia_add.o taia_approx.o taia_diff.o taia_fmtfrac.o \
	taia_frac.o taia_half.o taia_label.o taia_now.o taia_pack.o \
	taia_sub.o taia_tai.o taia_unpack.o 
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
taia_label.o:\
	cc-compile taia_label.c taia.h tai.h 
	./cc-compile taia_label.c
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
clean-all: sysdeps_clean tests_clean obj_clean 
clean: obj_clean
obj_clean: 
	rm -f UNIT_TESTS/t_assert.o UNIT_TESTS/t_cald_fmjd \
	UNIT_TESTS/t_cald_fmjd.o UNIT_TESTS/t_cald_fmt \
	UNIT_TESTS/t_cald_fmt.o UNIT_TESTS/t_cald_mjd \
	UNIT_TESTS/t_cald_mjd.o UNIT_TESTS/t_cald_scan \
	UNIT_TESTS/t_cald_scan.o UNIT_TESTS/t_calt_fmt \
	UNIT_TESTS/t_calt_fmt.o UNIT_TESTS/t_calt_scan \
	UNIT_TESTS/t_calt_scan.o UNIT_TESTS/t_util.o cald_fmt.o \
	cald_frommjd.o cald_mjd.o cald_norm.o cald_scan.o caldate.a \
	calt_fmt.o calt_scan.o caltime.a chrono-conf chrono-conf.o \
	conf-cctype conf-systype ctxt/bindir.c ctxt/bindir.o ctxt/ctxt.a \
	ctxt/dlibdir.c ctxt/dlibdir.o ctxt/incdir.c ctxt/incdir.o \
	ctxt/leapsec.c ctxt/leapsec.o ctxt/repos.c ctxt/repos.o \
	ctxt/slibdir.c ctxt/slibdir.o ctxt/version.c ctxt/version.o \
	deinstaller deinstaller.o inst-check inst-check.o inst-copy \
	inst-copy.o inst-dir inst-dir.o inst-link inst-link.o install_core.o \
	install_error.o installer installer.o instchk instchk.o insthier.o \
	leaps_data.o leaps_free.o leaps_init.o leaps_read.o leapsecs 
	rm -f leapsecs.a leapsecs.o mk-ctxt mk-ctxt.o tai.a tai64 tai64.o \
	tai64n tai64n.o tai64na tai64na.o tai_add.o tai_approx.o tai_diff.o \
	tai_label.o tai_now.o tai_pack.o tai_sub.o tai_unix.o tai_unpack.o \
	taia.a taia_add.o taia_approx.o taia_diff.o taia_fmtfrac.o \
	taia_frac.o taia_half.o taia_label.o taia_now.o taia_pack.o \
	taia_sub.o taia_tai.o taia_unpack.o 

deinstall: deinstaller inst-check inst-copy inst-dir inst-link
	./deinstaller
deinstall-dryrun: deinstaller inst-check inst-copy inst-dir inst-link
	./deinstaller dryrun
install: installer inst-check inst-copy inst-dir inst-link postinstall
	./installer
	./postinstall

install-dryrun: installer inst-check inst-copy inst-dir inst-link
	./installer dryrun
install-check: instchk inst-check
	./instchk
tests:
	(cd UNIT_TESTS && make tests)
tests_clean:
	(cd UNIT_TESTS && make clean)
regen:
	cpj-genmk > Makefile.tmp && mv Makefile.tmp Makefile

