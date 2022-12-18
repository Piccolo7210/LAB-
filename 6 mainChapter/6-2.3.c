#include<stdio.h>
int main(){
	int *p,q;
	p=&q;
	printf("At first p = %p\n",p);
	*p=10;
	(*p)++;
	printf("q = %d\np = %p\n",q,p);
	return 0;
}
