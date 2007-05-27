#ifndef CALDATE_H
#define CALDATE_H

/* fmt_ulong + month + day + '-' + '-' */
#define CALDATE_FMT ((sizeof(unsigned long) * 8) + 2 + 2 + 2)

struct caldate {
  unsigned long year;
  unsigned int month;
  unsigned int day;
};

unsigned int caldate_fmt(char *, const struct caldate *);
unsigned int caldate_scan(const char *, struct caldate *);

#endif
