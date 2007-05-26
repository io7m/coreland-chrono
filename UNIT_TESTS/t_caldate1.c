#include <stdio.h>
#include "t_assert.h"
#include "t_util.h"
#include "../caldate.h"

static const struct {
  struct caldate cd;
  unsigned int len;
  const char *s;
} tests[] = {
  { { 0, 0, 0 }, 7, "0-00-00" },
  { { 0xffffffff, 0xffff, 0xffff }, 22, "4294967295-65535-65535" }, 
  { { 0, 1, 1 }, 7, "0-01-01" },
  { { 1, 1, 1 }, 7, "1-01-01" },
  { { 1000, 1, 1 }, 10, "1000-01-01" },
  { { 1799, 12, 31 }, 10, "1799-12-31" },
  { { 1899, 12, 31 }, 10, "1899-12-31" },
  { { 1900, 1, 1 }, 10, "1900-01-01" },
  { { 1969, 12, 31 }, 10, "1969-12-31" },
  { { 1969, 12, 31 }, 10, "1969-12-31" },
  { { 1969, 12, 31 }, 10, "1969-12-31" },
  { { 1970, 1, 1 }, 10, "1970-01-01" },
  { { 1970, 1, 1 }, 10, "1970-01-01" },
  { { 1972, 6, 30 }, 10, "1972-06-30" },
  { { 1972, 6, 30 }, 10, "1972-06-30" },
  { { 1972, 6, 30 }, 10, "1972-06-30" },
  { { 1972, 7, 1 }, 10, "1972-07-01" },
  { { 1972, 7, 1 }, 10, "1972-07-01" },
  { { 1995, 12, 31 }, 10, "1995-12-31" },
  { { 1995, 12, 31 }, 10, "1995-12-31" },
  { { 1995, 12, 31 }, 10, "1995-12-31" },
  { { 1996, 1, 1 }, 10, "1996-01-01" },
  { { 1996, 1, 1 }, 10, "1996-01-01" },
  { { 1996, 1, 1 }, 10, "1996-01-01" },
  { { 1997, 6, 30 }, 10, "1997-06-30" },
  { { 1997, 6, 30 }, 10, "1997-06-30" },
  { { 1997, 7, 1 }, 10, "1997-07-01" },
  { { 1997, 7, 30 }, 10, "1997-07-30" },
  { { 1997, 10, 3 }, 10, "1997-10-03" },
  { { 1999, 9, 9 }, 10, "1999-09-09" },
  { { 1999, 12, 31 }, 10, "1999-12-31" },
  { { 2000, 1, 1 }, 10, "2000-01-01" },
  { { 2000, 1, 1 }, 10, "2000-01-01" },
  { { 2000, 2, 28 }, 10, "2000-02-28" },
  { { 2000, 2, 29 }, 10, "2000-02-29" },
  { { 2000, 3, 1 }, 10, "2000-03-01" },
  { { 2000, 12, 31 }, 10, "2000-12-31" },
  { { 2100, 1, 1 }, 10, "2100-01-01" },
  { { 2200, 1, 1 }, 10, "2200-01-01" },
  { { 3000, 1, 1 }, 10, "3000-01-01" },
  { { 10000, 1, 1 }, 11, "10000-01-01" },
  { { 999999, 12, 31 }, 12, "999999-12-31" },
  { { 1000000, 1, 1 }, 13, "1000000-01-01" },
};

int main(void)
{
  char cdate[CALDATE_FMT];
  unsigned long ind;
  unsigned int len;

  for (ind = 0; ind < sizeof(tests) / sizeof(tests[0]); ++ind) {
    cdate[caldate_fmt(cdate, &tests[ind].cd)] = 0;
    test_assert(t_str_same(tests[ind].s, cdate));
    len = caldate_fmt(0, &tests[ind].cd);
    test_assert(len == tests[ind].len);
    printf("[t %lu] %s %u\n", ind, tests[ind].s, tests[ind].len);
  }

  return 0;
}
