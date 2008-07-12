#include "ctxt.h"
#include "leapsecs.h"

struct tai *leapsecs_list = 0;
unsigned long leapsecs_size = 0;
const char *leapsecs_dir = ctxt_etcdir;
