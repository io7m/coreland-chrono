#include "tai.h"

void tai_unix(struct tai *t, uint64 n)
{
  t->n = TAI_EPOCH + n;
}
