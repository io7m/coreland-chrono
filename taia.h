#ifndef TAIA_H
#define TAIA_H

#include "tai.h"

#define TAIA_PACK 16
#define TAIA_FMTFRAC 19
#define TAIA_TAI64N 25
#define TAIA_TAI64NA 33

struct taia {
  struct tai sec;
  unsigned long nano; /* 0 ... 999999999 */
  unsigned long atto; /* 0 ... 999999999 */
};

void taia_tai(const struct taia *, struct tai *);
void taia_now(struct taia *);
void taia_add(struct taia *, const struct taia *, const struct taia *);
void taia_sub(struct taia *, const struct taia *, const struct taia *);
void taia_half(struct taia *, const struct taia *);

int taia_diff(const struct taia *, const struct taia *);
#define taia_less(t,u) (taia_diff((t),(u)) < 0)
#define taia_more(t,u) (taia_diff((t),(u)) > 0)
#define taia_equal(t,u) (taia_diff((t),(u)) == 0)

void taia_pack(unsigned char *, const struct taia *);
void taia_unpack(const unsigned char *, struct taia *);

double taia_approx(const struct taia *);
double taia_frac(const struct taia *);
unsigned int taia_fmtfrac(char *, const struct taia *);

void taia_tai64n(char *, const struct taia *);
void taia_tai64na(char *, const struct taia *);

#endif
