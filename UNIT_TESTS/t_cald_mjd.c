
#include <stdio.h>
#include "t_assert.h"
#include "t_util.h"
#include "../caldate.h"

static const struct {
  struct caldate cd;
  long mjd;
} tests[] = {
  { { 0, 0, 0 }, -678973 },
  { { 1, 1, 1 }, -678575 },
  { { -1, -1, -1 }, -679369 },
  { { 1858, 11, 17 }, 0 },
  { { 1859, 2, 25 }, 100 },
  { { 1861, 8, 13 }, 1000 },
  { { 1886, 4, 4 }, 10000 },
  { { 2132, 9, 1 }, 100000 },
  { { 4596, 10, 13 }, 1000000 },
};

int main(void)
{
  unsigned long ind;
  long mjd;

  for (ind = 0; ind < sizeof(tests) / sizeof(tests[0]); ++ind) {
    mjd = caldate_mjd(&tests[ind].cd);
    test_assert(mjd == tests[ind].mjd);
    printf("[%lu] %ld %d %d %ld\n",
             ind, tests[ind].cd.year, tests[ind].cd.month, tests[ind].cd.day, mjd);
  }

  return 0;
}
