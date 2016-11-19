#include <stdlib.h>
#include <math.h>

double uniform(double lo, double hi) {
  return lo + (((double) rand() / (double) RAND_MAX) * (hi - lo));
}

// Marsaglia Polar Method
double normalMPM() {
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
  return u * r;
}

double normal(double m,double s) {
  return m + (s*normalMPM());
}

// Marsaglia and Tsang, A Simple Method for Generating Gamma Variables
double gammaMT(double a, double b) {
  double d,c,x,v,u;
  d = a - (1.0 / 3.0);
  c = 1.0 / sqrt(9.0 * d);
  while(1) {
    do {
      x = normalMPM();
      v = 1.0 + (c * x);
    } while (v <= 0.0);
    v = v*v*v;
    u = uniform(0,1);
    if ((u < 1.0 - 0.331*(x*x)*(x*x)) ||
	(log(u)<0.5*(x*x)+d*(1.0-v+log(v))))
      return (d*v*b);
  }
}

double beta(double a, double b) {
  double x,y;
  x = gammaMT(a,1);
  y = gammaMT(b,1);
  return x / (x + y);
}
