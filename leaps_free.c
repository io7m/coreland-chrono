#include <corelib/alloc.h>
#include "leapsecs.h"

extern struct tai *leapsecs_list;
extern unsigned long leapsecs_size;

void leapsecs_free(void)
{
  dealloc(leapsecs_list);
  leapsecs_size = 0;
}
