default: sysdeps
clean: sysdeps_clean

sysdeps:  sd_integer-flags sd_integer-libs-S sd_corelib-flags sd_corelib-libs-S
sysdeps_clean:  sd_integer-flags_clean sd_integer-libs-S_clean sd_corelib-flags_clean sd_corelib-libs-S_clean

sd_integer-flags:
	@(cd modules/integer-flags && ./run)
sd_integer-flags_clean:
	@(cd modules/integer-flags && ./clean)

sd_integer-libs-S:
	@(cd modules/integer-libs-S && ./run)
sd_integer-libs-S_clean:
	@(cd modules/integer-libs-S && ./clean)

sd_corelib-flags:
	@(cd modules/corelib-flags && ./run)
sd_corelib-flags_clean:
	@(cd modules/corelib-flags && ./clean)

sd_corelib-libs-S:
	@(cd modules/corelib-libs-S && ./run)
sd_corelib-libs-S_clean:
	@(cd modules/corelib-libs-S && ./clean)

regen:
	./gen-makefile > Makefile.tmp && mv Makefile.tmp Makefile
