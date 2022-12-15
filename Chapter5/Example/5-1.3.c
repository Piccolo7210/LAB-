#include<stdio.h>
int main (void)
{
	int i;
	char mess[80];
	for(i=0;i<80;i++){
	scanf("%c",&mess[i]);
	if(mess[i]=='\n')
	{
		break;	
	}	
	}
	printf("\n");
	for(i=0;mess[i]!='\n';i++){
		printf("%c",mess[i]);	
	}
	
	return 0;
}
