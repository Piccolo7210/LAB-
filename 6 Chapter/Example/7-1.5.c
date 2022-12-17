#include<stdio.h>
int get_c(void);
int main(){
    char ch;
    ch=get_c();
    printf("Ch is : %c",ch);
    return  0;
}
int get_c(void){
    return 'B';
}
