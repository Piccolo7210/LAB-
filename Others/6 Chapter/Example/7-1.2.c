#include<stdio.h>
double volume(double , double , double);
int main(){
    double vol;
    vol=volume(1,2,3);
    printf("%f",vol);
    return 0;
}
double volume(double a,double b, double c){
    return a*b*c;
}
