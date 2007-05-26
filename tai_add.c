#include "tai.h"

void tai_add(struct tai *t, const struct tai *a, const struct tai *b)
{
  t->n = a->n + b->n;
}
