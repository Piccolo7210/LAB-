#include<stdio.h>
int a;
int *point(int);
int main(){
    int *p;
    p=point(10);
    printf("a = %d\n*p = %d",a,*p);
    return 0;
}
int *point(int x){
    a = x;
    return &a;
}
