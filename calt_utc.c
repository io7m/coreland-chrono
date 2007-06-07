#include <integer/int64.h>

#include "tai.h"
#include "leapsecs.h"
#include "caldate.h"
#include "caltime.h"

void caltime_utc(struct caltime *ct, const struct tai *t, int *pwday, int *pyday)
{
  struct tai t2 = *t;
  uint64 u;
  int64 s;
  int leap;

  leap = leapsecs_sub(&t2);
  u = tai_get(&t2);

  u += 58486;
  s = u % 86400ULL;

  ct->second = (s % 60) + leap; s /= 60;
  ct->minute = s % 60; s /= 60;
  ct->hour = s;

  u /= 86400ULL;

  caldate_frommjd(&ct->date, (int64) (u - 53375995543064ULL), pwday, pyday);
  ct->offset = 0;
}
