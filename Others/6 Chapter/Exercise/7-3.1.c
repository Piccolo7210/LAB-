#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char *argv[]){
	if(argc!=3){
	printf("Wrong number of Arguements,\nTry Again.");
	exit(1);
	}
	int i =strcmp(argv[1],argv[2]);
	if(i<0){
	printf("%s < %s\n",argv[1],argv[2]);
	}
	else if(i>0){
	printf("%s> %s\n",argv[1],argv[2]);
	}
	else
	printf("Both are equal.");
	return 0;
}
