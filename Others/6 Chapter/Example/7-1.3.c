#include<stdio.h>
int getx(void){
    int x;
    printf("Enter an integer : ");
    scanf("%d",&x);
    return x;
}
int main(){
    int i;
    i=getx();
    printf("In main i is : %d",i);
    return 0;
}
