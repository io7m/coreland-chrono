#include "leapsecs.h"
#include "tai.h"

extern struct tai *leapsecs_list;
extern unsigned long leapsecs_size;

void leapsecs_add(struct tai *t, int hit)
{
  unsigned long i;
  uint64 u;

  if (leapsecs_init() == -1) return;

  u = tai_get(t);
  for (i = 0; i < leapsecs_size; ++i) {
    if (u < leapsecs_list[i].n) break;
    if (!hit || (u > leapsecs_list[i].n)) ++u;
  }
  tai_set(t, u);
}
