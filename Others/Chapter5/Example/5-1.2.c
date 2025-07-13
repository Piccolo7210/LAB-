#include<stdio.h>
int main(){
	int i,a1[10],a2[10];
	for(i=1;i<11;i++){
		a1[i-1]=i;
		a2[i-1]=a1[i-1];	
	}
	for(i=0;i<10;i++){
		printf("%d ",a2[i]);	
	}
	return 0;
}
