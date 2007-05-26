#include "tai.h"

void tai_pack(unsigned char *buf, const struct tai *t)
{
  uint64_packb(buf, t->n);
}
