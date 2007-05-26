#include "taia.h"

int taia_diff(const struct taia *t, const struct taia *u)
{
  if (t->sec.n < u->sec.n) return -1;
  if (t->sec.n > u->sec.n) return 1;
  if (t->nano < u->nano) return -1;
  if (t->nano > u->nano) return 1;
  return t->atto - u->atto;
}
