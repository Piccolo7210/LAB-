#include<stdio.h>
void f1(int);
int main(){
    f1(0);
    return 0;
}
void f1(int x){
    if(x<10){
        printf("%d ",x);
        x++; // x++; == f(x+1) 
        f1(x);
    }
}