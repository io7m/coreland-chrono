#include <corelib/fmt.h>
#include "caldate.h"
#include "caltime.h"

unsigned int caltime_fmt(char *str, const struct caltime *ct)
{
  unsigned int len = 0;
  unsigned int pos = 0;

  pos = caldate_fmt(str, &ct->date);
  len += pos;
  if (str) str += pos;

  pos = fmt_str(str, " ");
  len += pos;
  if (str) str += pos;

  pos = fmt_pad_int(str, ct->hour, 2, '0', fmt_int, FMT_PAD_SIGN_PRE);
  len += pos;
  if (str) str += pos;

  pos = fmt_str(str, ":");
  len += pos;
  if (str) str += pos;

  pos = fmt_pad_int(str, ct->minute, 2, '0', fmt_int, FMT_PAD_SIGN_PRE);
  len += pos;
  if (str) str += pos;

  pos = fmt_str(str, ":");
  len += pos;
  if (str) str += pos;

  pos = fmt_pad_int(str, ct->second, 2, '0', fmt_int, FMT_PAD_SIGN_PRE);
  len += pos;
  if (str) str += pos;

  pos = fmt_str(str, " ");
  len += pos;
  if (str) str += pos;

  if (ct->offset > 0) {
    pos = fmt_str(str, "+");
    len += pos;
    if (str) str += pos;
  }

  pos = fmt_pad_long(str, ct->offset, (ct->offset < 0) ? 5 : 4, '0', fmt_long, FMT_PAD_SIGN_PRE);
  len += pos;
  if (str) str += pos;

  return len;
}
