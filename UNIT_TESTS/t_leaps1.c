#include <integer/uint64.h>
#include "t_assert.h"
#include "../leapsecs.h"
#include "../tai.h"

/* Needs to be updated along with leap second table */

int main(void)
{
  struct tai t;
  uint64 tai_1970 = TAI_1970;

  leapsecs_path = "../leapsecs.dat";

  tai_set(&t, tai_1970 + 0);
  leapsecs_add(&t, 0);
  test_assert(tai_get(&t) == tai_1970 + 0);

  tai_set(&t, tai_1970 + 0);
  leapsecs_add(&t, 1);
  test_assert(tai_get(&t) == tai_1970 + 0);

  return 0;
}
