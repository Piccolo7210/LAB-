#include<stdio.h>
#include<string.h>
int main(){
	char a1[80],a2[80];
	printf("Enter the string : \n");
	gets(a1);
	printf("Enter the string : \n");
	gets(a2);
	printf("Length of the a1 string %d\n",strlen(a1));
	printf("Length of the a2 string %d\n",strlen(a2));
	int i;
	i=strcmp(a1,a2);
	if(i==0){
	printf("Equal strings");	
	}
	else if(i<0){
	printf("%s is less than %s\n",a1,a2);	
	}
	else {
	printf("%s is greater than %s\n",a1,a2);	
	}
	if(strlen(a1)+strlen(a2)<80){
	strcat(a1,a2);	
	printf("%s\n",a1);
	}
	strcpy(a1,a2);
	printf("%s %s\n",a1,a2);
	return 0;
}
