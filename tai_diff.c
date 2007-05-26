#include "tai.h"

int tai_diff(const struct tai *a, const struct tai *b)
{
  return a->n - b->n;
}
