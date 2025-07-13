#include<stdio.h>
int main(){
	int r,c,i,j;
	printf("Enter the row number : ");
	scanf("%d",&r);
	printf("Enter the column number : ");
	scanf("%d",&c);
	int marr[r][c];
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			marr[i][j]=i*j;
		}
	}
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			printf("%d ",marr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
