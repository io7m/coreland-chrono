#include "taia.h"
#include "tai.h"

void taia_half(struct taia *t, const struct taia *u)
{
  t->atto = u->atto >> 1;
  if (u->nano & 1) t->atto += 500000000UL;
  t->nano = u->nano >> 1;
  if (u->sec.n & 1) t->nano += 500000000UL;
  t->sec.n = u->sec.n >> 1;
}
