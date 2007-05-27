#include <time.h>
#include "tai.h"

void tai_now(struct tai *t)
{
  t->n = TAI_1970 + (uint64) time((time_t *) 0);
}
