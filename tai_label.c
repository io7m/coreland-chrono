#include "tai.h"

static const char hex[16] = "0123456789abcdef";

void tai_tai64(char s[TAI_TAI64], const struct tai *ta)
{
  unsigned char buf[TAI_PACK];
  unsigned int i;

  tai_pack(buf, ta);
  for (i = 0; i < 8; ++i) {
    s[i * 2 + 0] = hex[(buf[i] >> 4) & 15];
    s[i * 2 + 1] = hex[buf[i] & 15];
  }
}
