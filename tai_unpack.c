#include "tai.h"

void tai_unpack(const unsigned char *buf, struct tai *t)
{
  uint64_unpackb(buf, &t->n);
}
