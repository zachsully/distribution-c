#include <stdio.h>
#include <math.h>
#include <distribution.h>
#include <time.h>

int main() {
  srand(time(NULL));
  while(1) printf("%.17f\n",beta(2,5));
  return 0;
}
