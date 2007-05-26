#include "taia.h"
#include "tai.h"

void taia_add(struct taia *t, const struct taia *a, const struct taia *b)
{
  tai_add(&t->sec, &a->sec, &b->sec);
  t->nano = a->nano + b->nano;
  t->atto = a->atto + b->atto;
  if (t->atto > 999999999UL) {
    t->atto -= 1000000000UL;
    ++t->nano;
  }
  if (t->nano > 999999999UL) {
    t->nano -= 1000000000UL;
    ++t->sec.n;
  }
}
