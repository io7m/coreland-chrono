#include "taia.h"
#include "tai.h"

void taia_tai(const struct taia *t, struct tai *u)
{
  *u = t->sec;
}
