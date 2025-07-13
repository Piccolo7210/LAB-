#include<stdio.h>
int main(){
	int serveruser[5][2]={
	1,14,
	2,28,
	3,19,
	4,8,
	5,15
	};
	int server;
	printf("Enter the server no : ");
	scanf("%d",&server);
	if(server<=5){
		printf("User number in server %d is = %d",server,serveruser[server-1][1]);
	}
	else
	{
		printf("Invalid server.");	
	}

	return 0;
}
