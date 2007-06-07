#include <integer/int64.h>

#include "tai.h"
#include "leapsecs.h"
#include "caldate.h"
#include "caltime.h"

void caltime_tai(const struct caltime *ct, struct tai *t)
{
  int64 day;
  int64 s;

  day = caldate_mjd(&cd->date);

  s = ct->hour * 60 + ct->minute;
  s = (s - ct->offset) * 60 + ct->second;

  t->n = day * 86400ULL + 4611686014920671114ULL + s;

  leapsecs_add(t, ct->second == 60);
}
