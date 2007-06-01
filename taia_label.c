#include "taia.h"
#include "tai.h"

static const char hex[16] = "0123456789abcdef";

void taia_tai64n(char s[TAIA_TAI64N], const struct taia *ta)
{
  unsigned char buf[TAIA_PACK];
  unsigned int i;

  taia_pack(buf, ta);
  for (i = 0; i < 12; ++i) {
    s[i * 2 + 0] = hex[(buf[i] >> 4) & 15];
    s[i * 2 + 1] = hex[buf[i] & 15];
  }
}

void taia_tai64na(char s[TAIA_TAI64NA], const struct taia *ta)
{
  unsigned char buf[4];
  unsigned long atto;
  unsigned int i;

  taia_tai64n(s, ta);
  s += TAIA_TAI64N - 1;

  atto = ta->atto;
  buf[3] = atto & 0xffu; atto >>= 8;
  buf[2] = atto & 0xffu; atto >>= 8;
  buf[1] = atto & 0xffu;
  buf[0] = atto >> 8;

  for (i = 0; i < 4; ++i) {
    s[i * 2 + 0] = hex[(buf[i] >> 4) & 15];
    s[i * 2 + 1] = hex[buf[i] & 15];
  }
}
