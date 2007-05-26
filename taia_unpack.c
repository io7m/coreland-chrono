#include "taia.h"
#include "tai.h"

void taia_unpack(const unsigned char *buf, struct taia *t)
{
  unsigned long x;
  
  tai_unpack(buf, &t->sec);
  buf += 8;

  x = (unsigned char) buf[4];
  x <<= 8; x += (unsigned char) buf[5];
  x <<= 8; x += (unsigned char) buf[6];
  x <<= 8; x += (unsigned char) buf[7];
  t->atto = x;

  x = (unsigned char) buf[0];
  x <<= 8; x += (unsigned char) buf[1];
  x <<= 8; x += (unsigned char) buf[2];
  x <<= 8; x += (unsigned char) buf[3];
  t->nano = x; 
}
