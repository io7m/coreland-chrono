#include "taia.h"
#include "tai.h"

void taia_pack(unsigned char *buf, const struct taia *t)
{
  unsigned long x;

  tai_pack(buf, &t->sec);
  buf += 8;

  x = t->atto;
  buf[7] = x & 0xffu; x >>= 8;
  buf[6] = x & 0xffu; x >>= 8;
  buf[5] = x & 0xffu; x >>= 8;
  buf[4] = x;

  x = t->nano;
  buf[3] = x & 0xffu; x >>= 8;
  buf[2] = x & 0xffu; x >>= 8;
  buf[1] = x & 0xffu; x >>= 8;
  buf[0] = x;
}
