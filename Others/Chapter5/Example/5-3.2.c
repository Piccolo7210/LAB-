#include<stdio.h>
int main(){
	int ball[4][5],i,j;
	for(i=0;i<4;i++){
		for(j=0;j<5;j++){
			printf("%d Quarter Player %d's Score : ",i+1,j+1);
			scanf("%d",&ball[i][j]);
		}	
	}
	for(i=0;i<4;i++){
		for(j=0;j<5;j++){
			printf("%d Quarter Player %d's Score : %d\n",i+1,j+1,ball[i][j]);
		}	
	}
	return 0;
}
