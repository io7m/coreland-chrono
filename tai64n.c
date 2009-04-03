#include <corelib/buffer.h>
#include <corelib/exit.h>
#include <corelib/syserr.h>

#include "taia.h"

void done(void)
{
  if (buffer_flush(buffer1) == -1)
    syserr_die1sys(112, "tai64n: write: ");
}

int main(void)
{
  struct taia taia;
  char stamp[TAIA_TAI64N + 1];
  char ch;

  stamp[0] = '@';
  for (;;) {
    if (buffer_get(buffer0, &ch, 1) != 1) { done(); goto FINISH; }
    taia_now(&taia);
    taia_tai64n(stamp + 1, &taia);

    stamp[sizeof(stamp) - 1] = ' ';
    buffer_put(buffer1, stamp, sizeof(stamp));

    for (;;) {
      buffer_put(buffer1, &ch, 1);
      if (ch == '\n') break;
      if (buffer_get(buffer0, &ch, 1) != 1) { done(); goto FINISH; }
    }
  }

  FINISH:
  return 0;
}
