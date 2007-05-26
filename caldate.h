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

void caldate_frommjd(struct caldate *, unsigned long, unsigned int, unsigned int);
unsigned long caldate_mjd(const struct caldate *);

void caldate_normalize(struct caldate *);
void caldate_easter(struct caldate *);

#endif
