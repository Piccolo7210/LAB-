#include <stdio.h>
#include <math.h>
int Prob12 (void);

int main (void) {

  Prob12();

  return 0;
}


int Prob12 (void) { // Prob12
  double a,b,h;
  int i,n;
  double x[401],sinx[401], cosx[401];

  a=0;
  b=2*3.14159;
  n=200;
  h=(b-a)/n;

  x[0]=a;
  for (i=1; i<200; i++) x[i]=x[i-1]+h;
  x[n]=b;

  for (i=0; i<=200; i++){
    sinx[i]=sin(x[i]);
    cosx[i]=cos(x[i]);
  }

  printf("\"x\",\"Sin(x)\",\"Cos(x)\"\n");
  for (i=0; i<=200; i++)
    printf("%lf,%lf,%lf\n",x[i],sinx[i],cosx[i]);
  return 0;
} 

