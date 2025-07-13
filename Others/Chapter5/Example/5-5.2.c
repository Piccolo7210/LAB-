#include<stdio.h>
#include<string.h>
char word[][2][40]={
	"dog","Hund",
	"no","nein",
	"year","Jahr",
	"child","Kind",
	"I","Ich",
	"drive","farhen",
	"house","Haus",
	"to","zu",
	"",""
};
int main(){
	char eng[80];
	int i=0;
	printf("Enter an english word : ");
	gets(eng);
	while(strcmp(word[i][0],"")){
		if(!(strcmp(eng,word[i][0]))){
			printf("Grammer translation : %s\n",word[i][1]);
			break;	
		}
		i++;
	}
	if(!(strcmp(word[i][0],""))){
		printf("Not in Dictionary\n");	
	}
	return 0;
}
