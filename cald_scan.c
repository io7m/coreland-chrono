#include <corelib/scan.h>
#include "caldate.h"

unsigned int caldate_scan(const char *str, struct caldate *cd)
{
  unsigned int len = 0;
  unsigned int pos = 0;

  if (*str == '+') {
    ++str;
    ++len;
  }

  pos = scan_long(str, &cd->year);
  len += pos; str += pos;

  if (*str == '-') {
    ++str;
    ++len;
  }

  pos = scan_int(str, &cd->month);
  len += pos; str += pos;

  if (*str == '-') {
    ++str;
    ++len;
  }

  pos = scan_int(str, &cd->day);
  len += pos;

  return len;
}
