#include <sys/types.h>
#include <sys/stat.h>
#include <corelib/alloc.h>
#include <corelib/close.h>
#include <corelib/error.h>
#include <corelib/open.h>
#include <corelib/read.h>
#include "leapsecs.h"

extern struct tai *leapsecs_list;
extern unsigned long leapsecs_size;
extern const char *leapsecs_path;

int leapsecs_read(void)
{
  struct stat sb;
  struct tai tai;
  struct tai *mem = 0;
  unsigned long size;
  unsigned long ind;
  int fd = -1;

  fd = open_ro(leapsecs_path);
  if (fd == -1) {
    if (errno != error_noent) return -1;
    leapsecs_free();
    return 0;
  }

  if (fstat(fd, &sb) == -1) goto FAIL;

  mem = alloc(sb.st_size);
  if (!mem) goto FAIL;

  size = read(fd, mem, sb.st_size);
  if (size != (unsigned long) sb.st_size) { dealloc(mem); goto FAIL; }

  size = sb.st_size / sizeof(struct tai);
  for (ind = 0; ind < size; ++ind) {
    tai_unpack((unsigned char *) &mem[ind], &tai);
    mem[ind] = tai;
  }

  leapsecs_free();
  leapsecs_list = (struct tai *) mem;
  leapsecs_size = size;

  if (fd != -1) close(fd);
  return 0;

  FAIL:
  if (fd != -1) close(fd);
  return -1;
}
