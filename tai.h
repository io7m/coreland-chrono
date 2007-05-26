#ifndef TAI_H
#define TAI_H

#include <integer/uint64.h>

struct tai {
  uint64 n;
};

#define TAI_PACK 8

void tai_now(struct tai *);
void tai_add(struct tai *, const struct tai *, const struct tai *);
void tai_sub(struct tai *, const struct tai *, const struct tai *);
void tai_pack(unsigned char *, const struct tai *);
void tai_unpack(const unsigned char *, struct tai *);

double tai_approx(const struct tai *);

int tai_diff(const struct tai *, const struct tai *);
#define tai_less(t,u) (tai_diff((t),(u)) < 0)
#define tai_more(t,u) (tai_diff((t),(u)) > 0)
#define tai_equal(t,u) (tai_diff((t),(u)) == 0)

#endif
