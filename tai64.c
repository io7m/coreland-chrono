#include <corelib/buffer.h>
#include <corelib/exit.h>
#include <corelib/syserr.h>

#include "tai.h"

void done(void)
{
  if (buffer_flush(buffer1) == -1)
    syserr_die1sys(112, "tai64: write: ");
}

int main(void)
{
  struct tai tai;
  char stamp[TAI_TAI64 + 1];
  char ch;

  stamp[0] = '@';
  for (;;) {
    if (buffer_get(buffer0, &ch, 1) != 1) { done(); goto FINISH; }
    tai_now(&tai);
    tai_tai64(stamp + 1, &tai);

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
