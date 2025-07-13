#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    int n,i,j;
    double avg=0,sd=0;
    printf("Enter the value of N :");
    scanf("%d",&n);
    int data[n];
    printf("ENTER INPUTS : \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&data[i]);
    }
    for(i=0;i<n;i++)
    {
        avg=avg+data[i];
    }
    avg=avg/n;
    for(i=0;i<n;i++)
    {
        sd=sd+pow((data[i]-avg),2);
    }
    sd=sd/(n-1);
    sd=sqrt(sd);
    printf("Standard Daviation = %.3lf",sd);


}
