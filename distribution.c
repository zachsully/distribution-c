#include <stdlib.h>
#include <math.h>

double uniform(double lo, double hi) {
  return lo + (((double) rand() / (double) RAND_MAX) * (hi - lo));
}

double normal(double m, double s) {
  double u;
  double v;
  double q;
  double r;
  do {
    u = (double) rand() / (double) RAND_MAX * 2.0 - 1.0;
    v = (double) rand() / (double) RAND_MAX * 2.0 - 1.0;
    q = u*u + v*v;
  } while (q == 0 || q > 1);
  r = sqrt((-2) * (log(q)/q));
  return m + (u * r * s);
}
