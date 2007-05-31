#include <corelib/buffer.h>
#include <corelib/sgetline.h>
#include <corelib/syserr.h>

#include "caldate.h"
#include "tai.h"

const char progname[] = "leapsecs";
char linebuf[BUFFER_INSIZE];
struct sgetline line;

int main(void)
{
  struct caldate cd;
  struct tai tai;
  unsigned char ctai[TAI_PACK];
  unsigned long len;
  unsigned long leapsecs = 0;
  const char *s;
  int done = 0;

  sgetline_initbuf(&line, linebuf, sizeof(linebuf), buffer0);

  for (;;) {
    switch (sgetline_get(&line)) {
      case 0:
        done = 1;
        break;
      case -1:
        syserr_die2sys(112, progname, ": fatal: read: ");
        break;
      case -2:
        syserr_die2sys(112, progname, ": fatal: line too long");
        break;
      default:
        break;
    }
    if (done) break;

    s = sgetline_data(&line);
    len = sgetline_size(&line);

    if (*s != '#')
      if (caldate_scan(s, &cd)) {
        tai.n = (caldate_mjd(&cd) + 1) * TAI_SECS_PER_DAY + 4611686014920671114ULL + leapsecs++;
        tai_pack(ctai, &tai);
        buffer_put(buffer1, ctai, TAI_PACK);
      }
  }
 
  if (buffer_flush(buffer1) == -1)
    syserr_die2sys(112, progname, ": fatal: write: ");

  return 0;
}
