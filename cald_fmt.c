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
  pos = fmt_pad_int(str, cd->month, (cd->month < 0) ? 3 : 2, '0', fmt_int, FMT_PAD_SIGN_PRE);
  len += pos; if (str) str += pos;
  pos = fmt_str(str, "-");
  len += pos; if (str) str += pos;
  pos = fmt_pad_int(str, cd->day, (cd->day < 0) ? 3 : 2, '0', fmt_int, FMT_PAD_SIGN_PRE);
  len += pos;

  return len;
}
