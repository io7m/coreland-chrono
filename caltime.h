#ifndef CALTIME_H
#define CALTIME_H

#include "caldate.h"
#include "tai.h"

/* 1999-01-01 00:00:00 +0000 */
#define CALTIME_FMT (CALDATE_FMT + 16)

struct caltime {
  struct caldate date;
  int hour;
  int minute;
  int second;
  long offset;
};

void caltime_tai(const struct caltime *, struct tai *);
void caltime_utc(struct caltime *, const struct tai *, int *, int *);
void caltime_local(struct caltime *, const struct tai *);

unsigned int caltime_fmt(char *, const struct caltime *);
unsigned int caltime_scan(const char *, struct caltime *);

#endif
