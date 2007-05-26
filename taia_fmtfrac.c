#include "taia.h"

unsigned int taia_fmtfrac(char *buf, const struct taia *t)
{
  unsigned long x;

  if (buf) {
    x = t->atto;
    buf[17] = '0' + (x % 10); x /= 10;
    buf[16] = '0' + (x % 10); x /= 10;
    buf[15] = '0' + (x % 10); x /= 10;
    buf[14] = '0' + (x % 10); x /= 10;
    buf[13] = '0' + (x % 10); x /= 10;
    buf[12] = '0' + (x % 10); x /= 10;
    buf[11] = '0' + (x % 10); x /= 10;
    buf[10] = '0' + (x % 10); x /= 10;
    buf[9] = '0' + (x % 10);
    x = t->nano;
    buf[8] = '0' + (x % 10); x /= 10;
    buf[7] = '0' + (x % 10); x /= 10;
    buf[6] = '0' + (x % 10); x /= 10;
    buf[5] = '0' + (x % 10); x /= 10;
    buf[4] = '0' + (x % 10); x /= 10;
    buf[3] = '0' + (x % 10); x /= 10;
    buf[2] = '0' + (x % 10); x /= 10;
    buf[1] = '0' + (x % 10); x /= 10;
    buf[0] = '0' + (x % 10);
  }
  return 18;
}
