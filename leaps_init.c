#include "leapsecs.h"
#include "tai.h"

extern struct tai *leapsecs_list;
extern unsigned long leapsecs_size;

int leapsecs_init(void)
{
  if (leapsecs_list) return 0;
  if (leapsecs_read() == -1) return -1;
  return 0;
}
