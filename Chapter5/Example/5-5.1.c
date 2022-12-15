#include<stdio.h>
int main(){
	char name[10][80];
	int i,s;
	for(i=0;i<10;i++){
	printf("%d",i+1);
	gets(name[i]);	
	}
	do{
		printf("Number of string (1-10)");
		scanf("%d",&i);
		i--;
		if(i>=0 && i<10){
		printf("%s \n",name[i]);		
		}	
	}while(i>=0)
	return 0;
}
