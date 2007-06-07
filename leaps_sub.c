#include <integer/int64.h>

#include "leapsecs.h"
#include "tai.h"

extern struct tai *leapsecs_list;
extern unsigned long leapsecs_size;

int leapsecs_sub(struct tai *t)
{
  unsigned long i;
  uint64 u;
  int64 s;

  if (leapsecs_init() == -1) return 0;

  u = tai_get(t);
  s = 0;

  for (i = 0;i < leapsecs_size;++i) {
    if (u < leapsecs_list[i].n) break;
    ++s;
    if (u == leapsecs_list[i].n) {
      tai_set(t, u - s);
      return 1;
    }
  }

  tai_set(t, u - s);
  return 0;
}
