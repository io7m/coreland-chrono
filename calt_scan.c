#include <corelib/scan.h>
#include "caldate.h"
#include "caltime.h"

unsigned int caltime_scan(const char *str, struct caltime *ct)
{
  unsigned int pos = 0;
  unsigned int len = 0;

  pos = caldate_scan(str, &ct->date);
  len += pos;
  if (str) str += pos;

  pos = scan_charset(str, " ");
  len += pos;
  if (str) str += pos;

  pos = scan_int(str, &ct->hour);
  len += pos;
  if (str) str += pos;

  pos = scan_charset(str, ":");
  len += pos;
  if (str) str += pos;

  pos = scan_int(str, &ct->minute);
  len += pos;
  if (str) str += pos;

  pos = scan_charset(str, ":");
  len += pos;
  if (str) str += pos;

  pos = scan_int(str, &ct->second);
  len += pos;
  if (str) str += pos;

  pos = scan_charset(str, " ");
  len += pos;
  if (str) str += pos;

  pos = scan_charset(str, "+");
  if (pos) {
    len += pos;
    if (str) str += pos;
  }

  pos = scan_long(str, &ct->offset);
  len += pos;

  return len;
}
