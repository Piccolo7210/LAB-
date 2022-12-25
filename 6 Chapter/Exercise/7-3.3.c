#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char *argv[]){
	int n = atoi(argv[2]),m = atoi(argv[3]);
	if(argc!=4){
	printf("Wrong number of arguement. Try Again.\n");
	exit(1);
	}
	if(!(strcmp(argv[1],"add"))){
		printf("ADD = %d\n",n+m);
	}
	else if(!(strcmp(argv[1],"subtract"))){
		printf("Sub = %d\n",n-m);
	}
	else if(!(strcmp(argv[1],"multiply"))){
		printf("Multiply = %d\n",n*m);
	}
	else if(!(strcmp(argv[1],"divide"))){
		printf("Divide = %d\n",n/m);
	}
	return 0;
}
