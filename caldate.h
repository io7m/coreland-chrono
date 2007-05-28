#ifndef CALDATE_H
#define CALDATE_H

/* '-' + fmt_ulong + '-' + month + '-' + day + '-' + '-' */
#define CALDATE_FMT ((sizeof(long) * 8) + 2 + 2 + 2)

struct caldate {
  signed long year;
  signed int month;
  signed int day;
};

unsigned int caldate_fmt(char *, const struct caldate *);
unsigned int caldate_scan(const char *, struct caldate *);

long caldate_mjd(const struct caldate *);
void caldate_frommjd(struct caldate *, long, int *, int *);

#endif
