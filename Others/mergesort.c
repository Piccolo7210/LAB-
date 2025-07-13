#include<stdio.h>
void merge(int *arr,int first,int mid,int end){
	int n1 = mid -first +1;
	int n2 = end - mid;
	int L[n1+1];
	int R[n2+1];
	for(int i=0;i<n1;i++)
	{
		L[i]=arr[first+i];	
	}
	for(int i=0;i<n2;i++)
	{
		R[i]=arr[mid+1+i];	
	}
	L[n1]=20000;
	R[n2]=30000;
	int m=0;
	int n=0;
	int k=first;
		for(;m<n1 && n<n2;k++){
			if(L[m]<R[n]){
				arr[k]=L[m];
			 	m++;
			}	
		else{
			arr[k]=R[n];
			n++;		
		}
	}
	for(;m<n1;m++){
		arr[k]=L[m];
		k++;	
	}
	for(;n<n2;n++){
		arr[k]=R[n];
		k++;
	}

}
void mergesort(int *arr,int first,int end){
	if(first<end)
	{
		int mid = (first+end)/2;
		mergesort(arr,first,mid);
		mergesort(arr,mid+1,end);
		merge(arr,first,mid,end);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	int array[n];
		for(int i=0;i<n;i++){	
		scanf("%d",&array[i]);
	}	
	mergesort(array,0,n-1);
	for(int i=0;i<n;i++){	
		printf("%d ",array[i]);
	}
return 0;
}
