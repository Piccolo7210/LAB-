#include <stdio.h>
#define N 10

int main (void) {
  int x[N], n=N, i;
  double mean, b;

  for (i = 0; i < n; i++)
    scanf("%d",&x[i]);

  for (mean = 0, i = 0; i < n; i++)
    mean += x[i];
  mean /= n;

  for (b = 0, i = 0; i < n; i++)
    b += (x[i] - mean)*(x[i] - mean);
  
  printf("mean=%lf, b=%lf\n",mean,b);

  return 0;
}
