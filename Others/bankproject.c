#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define n 10
struct bank{
    char name[80];
    long int balance;
}arr[n];
void operation(int);
void deposit(int);
void read_file(void);
void withdraw(int);
//void transfer(int);
void details(int);
int menu(void);
int main(){
    int index,i;
    read_file();
    for(;;){
        index=menu();
        if(index!=-1){
            break;
        }
    }
    operation(index);
    /*for(int i=0;i<n;i++){
        printf("Name:    %s\n",arr[i].name);
        printf("Balance: %ld\n",arr[i].balance);
    }*/
}
void read_file(void){
    FILE *fp;
    int i,j,m;
    long int bal2;
    char ch,first_name[20],last_name[20],bal[30],a[15];
    fp=fopen("bank_in.txt","r");
    if(fp==NULL){
        printf("Error.");
        exit(1);
    }
    for(j=0;j<n;j++){
        for(i=0;;i++){
        fscanf(fp,"%c",&ch);
        if(ch==','){break;}
        first_name[i]=ch;
    }
    first_name[i] ='\0';
    for(i=0;;i++){
        fscanf(fp,"%c",&ch);
        if(ch==','){break;}
        last_name[i]=ch;
    }
    last_name[i]='\0';
   for(i=0;;i++){
    fscanf(fp,"%c",&ch);
        if(ch==','){break;}
            bal[i]=ch;   
        }
    fscanf(fp,"%s",a);
    m=0;
    while(a[m]){
        bal[i]=a[m];
        m++;
        i++;
    }
    bal[i]='\0';
    bal2=atol(bal);
    fgetc(fp);
    strcpy(arr[j].name,first_name);
    strcat(arr[j].name," ");
    strcat(arr[j].name,last_name);
    arr[j].balance=bal2;
    } 
    fclose(fp);
}
int menu(void){
    char nam[80];
    int i,c=-1;
    printf("Enter your Name : ");
    gets(nam);
    for(i=0;i<10;i++){
        if(!strcmp(nam,arr[i].name)){
            c=i;
            printf("Your account balance : %ld\n",arr[i].balance);
            break;
        }
    }
    if(c==-1){
        printf("Wrong Name, try Again.\n");
    }
    return c;
}
void operation(int index){
    int choice;
    printf("Operation : \n");
    printf("1.Deposit\n2.Withdraw\n3.Transfer\n4.Account details.\n");
    printf("Choice(1-4)\n");
    scanf("%d",&choice);
    switch(choice){
        case 1 : deposit(index);
                break;  
        case 2 : withdraw(index);
                    break;
        case 3 :    printf("Not built yet\n");
                    break;
        case 4 : details(index);
                    break;
    }

}
void deposit(int y){
    long int amount;
    printf("How much? \n");
    scanf("%ld",&amount);
    arr[y].balance=arr[y].balance + amount;
    printf("New balance is %ld\n",arr[y].balance);
}
void withdraw(int index){
    long int amount;
    printf("How much? \n");
    scanf("%ld",&amount);
    arr[index].balance=arr[index].balance - amount;
    printf("New balance is %ld\n",arr[index].balance);
}
void details(int index){
    printf("Your Account balance is: %ld\n",arr[index].balance);
}
