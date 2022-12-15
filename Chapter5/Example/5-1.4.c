#include<stdio.h>
#define n 5
int main(){
	int i,c,j;
	int a[n];
	printf("Enter numbers :\n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);	
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(a[j]>a[j+1])
			{
				c=a[j+1];
				a[j+1]=a[j];
				a[j]=c;			
			}		
		}	
	}
	for(i=0;i<n;i++){
		printf("%d\n",a[i]);		
	}
	return 0;
}
