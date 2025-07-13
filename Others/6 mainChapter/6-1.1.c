#include<stdio.h>
int main(){
	int *p,q;
	p=&q;
	q=100;
	printf("%d",*p);
	return 0;
}
