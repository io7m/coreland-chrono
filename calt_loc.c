#include <integer/int64.h>
#include "_sd_timezone.h"

#include "tai.h"
#include "leapsecs.h"
#include "caldate.h"
#include "caltime.h"

#include <time.h>

/* XXX: localtime() ... */

void caltime_local(struct caltime *ct, const struct tai *t, int *wday, int *yday)
{
  struct tm *tm;
  uint64 u = tai_get(t) - TAI_1970;
  time_t tt = (time_t) u;

  tm = localtime(&tt);

  /* local timezone offset */
#if SD_TIMEZONE == SD_TIMEZONE_STRUCT_TM
  ct->offset = tm->tm_gmtoff / 60;
#elif SD_TIMEZONE == SD_TIMEZONE_GLOBAL
  ct->offset = timezone / 60;
#elif SD_TIMEZONE == SD_TIMEZONE_NULL
  ct->offset = 0;
#endif

  ct->second = tm->tm_sec;
  ct->minute = tm->tm_min;
  ct->hour = tm->tm_hour;
  ct->date.year = tm->tm_year + 1900;
  ct->date.month = tm->tm_mon;
  ct->date.day = tm->tm_mday;

  if (wday) *wday = tm->tm_wday;
  if (yday) *yday = tm->tm_yday;
}
