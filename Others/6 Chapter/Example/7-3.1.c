#include<stdio.h>
void swap (int *,int *);
int main(){
    int x=15,y=26;
    printf("X = %d, Y = %d",x,y);
    swap(&x,&y);
    printf("\nAfter swaping \n");
    printf("X = %d, Y = %d",x,y);
    return 0;
}
void swap (int *a, int *b){
    int x;
    x=*a;
    *a=*b;
    *b=x;
}