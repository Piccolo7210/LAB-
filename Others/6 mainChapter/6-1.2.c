#include<stdio.h>
int main(){
	int *p,q;
	p=&q;
	*p=100;
	printf("%d",q);
	return 0;
}
