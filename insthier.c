#include "ctxt.h"
#include "install.h"

struct install_item insthier[] = {
  {INST_MKDIR, 0, 0, ctxt_bindir, 0, 0, 0755},
  {INST_MKDIR, 0, 0, ctxt_incdir, 0, 0, 0755},
  {INST_MKDIR, 0, 0, ctxt_dlibdir, 0, 0, 0755},
  {INST_MKDIR, 0, 0, ctxt_slibdir, 0, 0, 0755},
  {INST_MKDIR, 0, 0, ctxt_repos, 0, 0, 0755},
  {INST_COPY, "cald_fmt.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "cald_frommjd.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "cald_mjd.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "cald_norm.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "cald_scan.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "calt_fmt.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "calt_loc.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "calt_scan.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "calt_tai.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "calt_utc.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "chrono-conf.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "leaps_add.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "leaps_data.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "leaps_free.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "leaps_init.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "leaps_read.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "leaps_sub.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "leapsecs.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "tai64.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "tai64n.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "tai64na.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "tai_add.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "tai_approx.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "tai_diff.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "tai_get.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "tai_label.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "tai_now.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "tai_pack.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "tai_set.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "tai_sub.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "tai_unix.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "tai_unpack.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "taia_add.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "taia_approx.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "taia_diff.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "taia_fmtfrac.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "taia_frac.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "taia_half.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "taia_label.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "taia_now.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "taia_pack.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "taia_sub.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "taia_tai.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "taia_unpack.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "caldate.h", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "caldate.h", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "caltime.h", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "caltime.h", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "leapsecs.h", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "leapsecs.h", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "tai.h", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "tai.h", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "taia.h", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "taia.h", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "caldate.sld", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "caldate.a", "libcaldate.a", ctxt_slibdir, 0, 0, 0644},
  {INST_COPY, "caltime.sld", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "caltime.a", "libcaltime.a", ctxt_slibdir, 0, 0, 0644},
  {INST_COPY, "leapsecs.sld", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "leapsecs.a", "libleapsecs.a", ctxt_slibdir, 0, 0, 0644},
  {INST_COPY, "tai.sld", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "tai.a", "libtai.a", ctxt_slibdir, 0, 0, 0644},
  {INST_COPY, "taia.sld", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "taia.a", "libtaia.a", ctxt_slibdir, 0, 0, 0644},
  {INST_COPY, "chrono-conf.ld", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY_EXEC, "chrono-conf", 0, ctxt_bindir, 0, 0, 0755},
  {INST_COPY, "leapsecs.ld", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY_EXEC, "leapsecs", 0, ctxt_bindir, 0, 0, 0755},
  {INST_COPY, "tai64.ld", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY_EXEC, "tai64", 0, ctxt_bindir, 0, 0, 0755},
  {INST_COPY, "tai64n.ld", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY_EXEC, "tai64n", 0, ctxt_bindir, 0, 0, 0755},
  {INST_COPY, "tai64na.ld", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY_EXEC, "tai64na", 0, ctxt_bindir, 0, 0, 0755},
};
unsigned long insthier_len = sizeof(insthier) / sizeof(struct install_item);
