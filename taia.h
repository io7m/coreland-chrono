#ifndef TAIA_H
#define TAIA_H

#include "tai.h"

#define TAIA_PACK 16
#define TAIA_FMTFRAC 19

struct taia {
  struct tai sec;
  unsigned long nano;
  unsigned long atto;
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

#endif
