#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
int stk[25],top=-1;
void push(int num){
    stk[++top]=num;
}
int pop(){
    return stk[top--];
}
int main(){
    char postfix[25],sym;
    int op1,op2;
    printf("enter the postfix expression");
    scanf("%s",&postfix);
    for (int  i = 0; i < strlen(postfix); i++){
        sym=postfix[i];
        switch (sym)
        {
        case '+' : op2=pop();
                    op1=pop();
                    push(op1+op2);
            break;
        case '-' : op2=pop();
                    op1=pop();
                    push(op1-op2);
            break;
        case '*' : op2=pop();
                    op1=pop();
                    push(op1*op2);
            break;
        case '/' : op2=pop();
                    op1=pop();
                    push(op1/op2);
            break;
        default:push(sym-'0');
            break;
        }
    }
    printf("The result is :%d",pop());

}