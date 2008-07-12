#ifndef LEAPSECS_H
#define LEAPSECS_H

#include "tai.h"

int leapsecs_init(void);
int leapsecs_read(void);
int leapsecs_sub(struct tai *);
void leapsecs_add(struct tai *, int);
void leapsecs_free(void);

extern const char *leapsecs_dir;

#endif
