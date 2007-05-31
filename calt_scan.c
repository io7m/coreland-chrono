#include "caldate.h"
#include "caltime.h"

unsigned int caltime_scan(const char *str, struct caltime *ct)
{
  unsigned int pos = 0;
  unsigned int len = 0;

  pos = caldate_scan(str, &ct->date);
  len += pos;
  if (str) str += pos;

  return len;
}
