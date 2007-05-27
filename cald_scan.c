#include <corelib/scan.h>
#include "caldate.h"

unsigned int caldate_scan(const char *str, struct caldate *cd)
{
  unsigned int len = 0;
  unsigned int pos = 0;

  pos = scan_long(str, &cd->year);
  len += pos; str += pos;
  pos = scan_charset(str, "-");
  len += pos; str += pos;
  pos = scan_uint(str, &cd->month);
  len += pos; str += pos;
  pos = scan_charset(str, "-");
  len += pos; str += pos;
  pos = scan_uint(str, &cd->day);
  len += pos;

  return len;
}
