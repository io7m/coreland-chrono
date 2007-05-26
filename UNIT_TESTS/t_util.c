#include "t_util.h"

int t_str_diff(register const char *s, 
               register const char *t)
{
  register char u;
  for (;;) {
    u = *s; if (u != *t) break; if (!u) break; ++s; ++t;
    u = *s; if (u != *t) break; if (!u) break; ++s; ++t;
    u = *s; if (u != *t) break; if (!u) break; ++s; ++t;
    u = *s; if (u != *t) break; if (!u) break; ++s; ++t;
  }
  return ((int)(unsigned int)(unsigned char) u) - 
         ((int)(unsigned int)(unsigned char) *t);
}

int t_str_same(register const char *s, 
               register const char *t)
{
  return t_str_diff(s, t) == 0;
}

