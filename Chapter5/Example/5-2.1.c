#include<stdio.h>
int main(){
	char a[100];
	printf("Enter string (less than 80 characters) : \n");
	gets(a);
	for(int i=0;a[i]!='\0';i++){
		printf("%c",a[i]);	
	}
	return 0;
}
