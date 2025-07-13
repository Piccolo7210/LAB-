#include<stdio.h>
int main(){
	int *p;
	double q,temp;
	temp=1234.56;
	p=&temp;
	q=*p;
	printf("%lf",q);
	return 0;
}

