#include <time.h>
#include "tai.h"

void tai_now(struct tai *t)
{
  t->n = 0x400000000000000AULL + (uint64) time((time_t *) 0);
}
