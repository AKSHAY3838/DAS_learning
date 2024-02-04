#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define max 5
int my_stack[5];
int top=-1;

void push(int m){
     {  top++;
         my_stack[top] = m;
     }
     }
int pop(){
    if(top==-1)
               {
                printf("stack is underflow\n");       
        return -1;}
    else
        return my_stack[top--];
    }
void display(){
     if(top==-1)
     {
     printf("stack is empty\n");
     }
     else{
          printf("stack elements are\n");
          for(int i=0; i<=top; i++)
                  printf("stack values are %d %d \n",i,my_stack[i]);
     }
}
void palindrome(){
     int num,number,rem,i;
     printf("enter number n \n");
     scanf("%d",&num);
     number=num;
     top=-1;
     while(num!=0)  {
     rem=num%10;
     push(rem);
     num=num/10;
     }
     
     num=0;
     for(i=0;top!=-1; i++)
       num=pop()*pow(10,i)+num;
       if(num==number)
           printf("given number is palindrome\n");
       else
           printf("given number is not palindrome\n");
     }
int main(){
     int choice,m;
     while(1){
              printf("enter your choice\n 1:for push 2:for pop 3: for display 4:palindrome 5:exit\n");
              scanf("%d",&choice);
              switch(choice){
                             case 1:if(top==max-1)
                                      printf("stack overflow\n");
                                      else{
                             printf("enter the value\n");
                                    scanf("%d",&m);                            
                                    push(m);
                                      }
                                    break;
                             case 2:m=pop();
                                    if(m==-1)
                                    printf("stack is empty\n");      
                                    else
                                    printf("%d",m);
                                    break;
                             case 3:display();
                                    break;
                             case 4:palindrome();
                                    break;
                             case 5:exit(0);
                                    break;
                             default: 
                                    printf("invalid choice\n");
                }              
              }
}