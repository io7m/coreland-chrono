#include <time.h>
#include <stdio.h>

int
main (void)
{
  const time_t t = timezone;

  printf ("%u\n", t);
  return 0;
}
