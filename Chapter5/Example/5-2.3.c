#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	char command[100],temp[80];
	int i,j;
	for(;;)
	{
		printf("Operation ? : Add, Subtract, Divide, Multiply, Quit.\n");
		gets(command);
		if(strcmp(command,"Quit")==0)break;
			printf("Enter first number :\n");
			gets(temp);
			i=atoi(temp);
			printf("Enter Second number :\n");
			gets(temp);
			j=atoi(temp);
		if(strcmp(command,"Add")==0)
			{
				printf("Result is = %d\n",i+j);
			}	
		else if(strcmp(command,"Subtract")==0)
			{
				printf("Result is = %d\n",i-j);										
			}
		else if(strcmp(command,"Divide")==0)
			{
				if(j)
				{
				printf("Result is = %d\n",i/j);										
				}
				else 
				{
					printf("Yout Can't divide by 0\n");				
				}										
			}
		else if(strcmp(command,"Multiply")==0)
			{
				printf("Result is = %d\n",i*j);										
			}	
		else 
		{
			printf("Invalid Command.\n");
		}

	}
	printf("Exit");
	
	return 0;
}
