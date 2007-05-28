#include "caldate.h"

long caldate_mjd(const struct caldate *cd)
{
  long y = cd->year;
  long m = cd->month;
  long d = cd->day;
  long jd;

  y += 8000;
  if (m < 3) { --y; m += 12; }

  jd = (y * 365) + (y / 4) - (y / 100) + (y / 400);
  jd += (m * 153 + 3) / 5 - 92 + d - 1 - 1200820;

  return jd - 2400001;
}
