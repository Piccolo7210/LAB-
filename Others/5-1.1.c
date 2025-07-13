#include<stdio.h>
#define n 5
int main(){
  int temp[n];
  int i,max,min;
	printf("Enter temparature :\n");
	for(i=0;i<n;i++){
		scanf("%d",&temp[i]);	
	}
	min=200;
	max=0;
	for(i=0;i<n;i++){
		if(min>temp[i]){
			min=temp[i];		
		}	
		if(max<temp[i]){
			max=temp[i];	
		}
	}
	printf("Max Temp : %d\n",max);
	printf("Min Temp : %d\n",min);
	return 0;

}
