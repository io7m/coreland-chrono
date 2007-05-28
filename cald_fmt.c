#include <corelib/fmt.h>
#include "caldate.h"

unsigned int caldate_fmt(char *str, const struct caldate *cd)
{
  unsigned int len = 0;
  unsigned int pos = 0;

  pos = fmt_long(str, cd->year);
  len += pos; if (str) str += pos;
  pos = fmt_str(str, "-");
  len += pos; if (str) str += pos;
  pos = fmt_pad_int(str, cd->month, 2, '0', fmt_int);
  len += pos; if (str) str += pos;
  pos = fmt_str(str, "-");
  len += pos; if (str) str += pos;
  pos = fmt_pad_int(str, cd->day, 2, '0', fmt_int);
  len += pos;

  return len;
}
