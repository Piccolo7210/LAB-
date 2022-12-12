#include<stdio.h>
int sum();
int main(){
    int s;
    s=sum(1,2,3);
    printf("%d",s);
    return 0;
}
int sum(int a,int b, int c){
    int s;
    s=a+b+c;
    return s;
}