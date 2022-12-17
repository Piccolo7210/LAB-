#include<stdio.h>
void copy(char *a, char *b);
int main(){
    char name[100];
    copy(name,"Mustakim Bin Mohsin");
    printf(name);
    return 0;
}
void copy(char *a, char *b){
    if(*b){
        *a++=*b++;
        copy(a,b);
    }
    else{
        *a='\0';
    }
}
