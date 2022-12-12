#include<stdio.h>
void f1(int a[]);
void f2(int *b);
void f3(int c[5]);
int main(){
    int num[5]={1,2,3,4,5};
    f1(num);
    f2(num);
    f3(num);
return 0;
}
void f1(int a[]){
    int i;
    for(i=0;i<5;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
void f2(int *p){
        int i;
    for(i=0;i<5;i++){
        printf("%d ",*(p++));
    }
    printf("\n");
}
void f3(int c[5]){
    int i;
    for(i=0;i<5;i++){
        printf("%d ",c[i]);
    }
    printf("\n");
}