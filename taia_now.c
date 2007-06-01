#include <sys/types.h>
#include <sys/time.h>
#include "taia.h"
#include "tai.h"

void taia_now(struct taia *t)
{
  struct timeval now = { 0, 0 };
  gettimeofday(&now, (struct timezone *) 0);

  tai_unix(&t->sec, now.tv_sec);
  t->nano = 100 * now.tv_usec + 500;
  t->atto = 0;
}
