#include "taia.h"
#include "tai.h"

void taia_sub(struct taia *t, const struct taia *a, const struct taia *b)
{
  unsigned long bnano = b->nano;
  unsigned long batto = b->atto;

  tai_sub(&t->sec, &a->sec, &b->sec);
  t->nano = a->nano - b->nano;
  t->atto = a->atto - b->atto;
  if (t->atto > batto) {
    t->atto += 1000000000UL;
    --t->nano;
  }
  if (t->nano > bnano) {
    t->nano += 1000000000UL;
    --t->sec.n;
  }
}
