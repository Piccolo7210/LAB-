#include<stdio.h>
void f1(int);
void f2(int);
int main(){
    f1(30);
    return 0;
}
void f1(int x){
    if(x){
        f2(x-1);
    }
    printf("%d ",x);
}
void f2(int y){
    printf("*");
    if (y) f1(y-1);
}
