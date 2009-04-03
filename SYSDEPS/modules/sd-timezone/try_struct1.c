#include <time.h>
#include <stdio.h>

int
main (void)
{
  struct tm t;

  t.tm_gmtoff = 1000;

  printf ("%ld\n", t.tm_gmtoff);
  return 0;
}
