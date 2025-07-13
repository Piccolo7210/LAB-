#include <stdio.h>
#define N 1000
#define PRIM    1
#define NOTPRIM 0

int main (void) {
  int x[N+1];
  int i, j;

  for (x[1] = NOTPRIM, i = 2; i <= N; i++) x[i] = PRIM;


  for (i = 2; i <= N/2; i++) 
    for (j = 2; j <= N/i; j++) 
      x[i*j] = NOTPRIM;

  for (i = 1; i <= N; i++)   
    if (x[i])
      printf("%5d",i);

  printf("\n");

  return 0;
}
