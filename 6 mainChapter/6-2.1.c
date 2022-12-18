#include<stdio.h>
int main(){
	char *cp,ch;
	int *ip,i;
	double *dp,d;
	float *fp,f;
	cp=&ch;
	dp=&d;
	ip=&i;
	fp=&f;
	printf("Address stored at cp = %p\n",cp);
	printf("Address stored at ip = %p\n",ip);
	printf("Address stored at dp = %p\n",dp);
	printf("Address stored at fp = %p\n",fp);
	cp++;
	ip++;
	dp++;
	fp++;
	printf("After increment :\n");
	printf("Address stored at cp = %p\n",cp);
	printf("Address stored at ip = %p\n",ip);
	printf("Address stored at dp = %p\n",dp);
	printf("Address stored at fp = %p\n",fp);
	return 0;
}
