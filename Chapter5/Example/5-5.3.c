#include<stdio.h>
#include<string.h>
int main(){
	int i,j;
	char s[][80]={
	"when","in","the","course","of","human",
	"events",""		
	};
	for(i=0;s[i][0];i++){
		for(j=0;s[i][j];j++){
			printf("%c ",s[i][j]);
		}
			printf("\n");
	}
		return 0;
}
