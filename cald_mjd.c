#include "caldate.h"

long caldate_mjd(const struct caldate *cd)
{
  long y = cd->year;
  long m = cd->month - 1;
  long d = cd->day - 678882;

  d += 146097 * (y / 400);
  y %= 400;

  if (m >= 2) m -= 2; else { m += 10; --y; }

  y += (m / 12);
  m %= 12;

  if (m < 0) { m += 12; --y; }

  d += (306 * m + 5) / 10;
  d += 146097 * (y / 400);
  y %= 400;

  if (y < 0) { y += 400; d -= 146097; }

  d += (y & 3) * 365;
  y >>= 2;

  d += 1461 * (y % 25);
  y /= 25;
  d += (y & 3) * 36524;

  return d;
}
