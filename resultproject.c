#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define n 3
#define sub 4
struct student{
    char name[80];
    float cgpa;
    struct student *sp;
}bsse[n],variable;
float gp[n][sub];
int netmarks[n][sub],roll[n],credit[sub],netcredit=0;
void read_file(void);
void gradept(int,int,int);
void cgpa_calc(void);
void encrypt(char *s);
void decrypt(char *s);
void strct_sort(void);
void address(void);
//void my_cgpa(int netmarks[n][3],credit[3],int,int);
int main(){
        int i;
        char mail[]="mustakim.mohsin7210@gmail.com";
        char pass[]="26.November.2016";
        encrypt(pass);
        FILE *doc;
        doc=fopen("Teacher.txt","w");
        fprintf(doc,"%s\n",mail);
        fprintf(doc,"%s",pass);
        fclose(doc);
        char checkmail[100],checkp[100];
        doc=fopen("Teacher.txt","r+");
        fscanf(doc,"%s",checkmail);
        fscanf(doc,"%s",checkp);
        fclose(doc);
        decrypt(checkp);
        char inmail[100],inpass[100];
        int flag1=0,flag2=0;
        printf("mail\n");
        gets(inmail);
        printf("pass\n");
        gets(inpass);
        if(!strcmp(inmail,checkmail))flag1=1;
        if(!strcmp(inpass,checkp))flag2=1;
        if(flag1 && flag2){
            for(i=0;i<n;i++){
                bsse[i].sp=NULL;
            }
        read_file();
        cgpa_calc();
        strct_sort();
        address();
        printf("Name : %s\nCGPA : %.2f\n",bsse[0].name,bsse[0].cgpa);
        for(i=0;i<n-1;i++){
            printf("Name : %s\nCGPA : %.2f\n",bsse[i].sp->name,bsse[i].sp->cgpa);
        }
        }
        else{
            printf("Error");
        }
        return 0;
     /*for(i=0;i<n;i++){
        printf("Roll %d result :\n",i+1);
        for(j=0;j<3;j++){
            printf("%d ",netmarks[i][j]);
        }
        printf("\n");
    }*/
}
void cgpa_calc(void){
    int i,j;
    float sum;
    for(i=0;i<n;i++){
        sum=0;
        for(j=0;j<sub;j++){
            if(gp[i][j]==0){
                sum=0;
                break;
            }
            sum +=credit[j]*gp[i][j];
        }
        bsse[i].cgpa=sum/netcredit;
    }
}
void read_file(void){
       FILE *fp;
    int i,j,k;
    int marks[n][sub][3],sum;
    fp=fopen("marks.txt","r");
    for(i=0;i<n;i++){
    fscanf(fp,"%s",bsse[i].name);
        for(j=0;j<sub;j++){
            sum=0;
            for(k=0;k<3;k++)
            {
            fscanf(fp,"%d",&marks[i][j][k]);
            sum+=marks[i][j][k];
            }
        netmarks[i][j]=sum;
        gradept(sum,j,i);
        fscanf(fp,"%d",&credit[j]);
    }
    fgetc(fp);
    }
     for(i=0;i<sub;i++){
        netcredit+=credit[i];
    }
}
void gradept(int marks,int index,int roll){
   if(marks>=80 && marks<=100)
					{		
					  gp[roll][index]=4.00;
                      return;
					}
				else if(marks>=75 && marks<=79)
					{
					  gp[roll][index]=3.75;
                      return;
					}
				else if(marks>=70 && marks<=74)
					{		
					  gp[roll][index]=3.50;
                      return;
					}
				else if(marks>=65 && marks<=69)
					{		
					 gp[roll][index]=3.25;
                     return;
					}
				else if(marks>=60 && marks<=64)
					{		
					  gp[roll][index]=3.00;
                      return;
					}
				else if(marks>=55 && marks<=59)
					{		
					  gp[roll][index]=2.75;
                      return;
					}
				else if(marks>=50 && marks<=54)
					{		
					 gp[roll][index]=2.5;
                     return;
					}
				else if(marks>=45 && marks<=49)
					{		
					 gp[roll][index]=2.25;
                     return;
					}
				else if(marks>=40 && marks<=44)
					{		
					  gp[roll][index]=2.00;
                      return;
					}
				else if(marks>=0 && marks<40)
					{		
					 gp[roll][index]=0.00;
                     return;
					}
}
void decrypt(char *s){
    int i;
    for(i=0;s[i];i++){
        s[i] += 1;
    }
}
void encrypt(char *s){
    int i;
    for(i=0;s[i];i++){
        s[i] -= 1;
    }
}
void strct_sort(void){
    int i,j;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(bsse[j].cgpa>bsse[i].cgpa){
                variable=bsse[i];
                bsse[i]=bsse[j];
                bsse[j]=variable;
            }
        }
    }
}
void address(void){
    int i;
    for(i=0;i<n-1;i++){
        bsse[i].sp=&bsse[i+1];
    }
}
