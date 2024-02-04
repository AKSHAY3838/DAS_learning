#include<stdio.h>
// #include<conio.h>
#include<ctype.h>

char stk[100];
int top = -1;

void push(char opr) {
    stk[++top] = opr;
}

char pop() {
    return stk[top--];
}

int preced(char opr) {
    if(opr == '^' || opr == '%') return 4;
    if(opr == '*' || opr == '/') return 3;
    if(opr == '+' || opr == '-') return 2;
    if(opr == '(' || opr == '#') return 1;
}

int main() {
    char infix[20], postfix[20];
    int i, j = 0;
    printf("Enter the infix expression:\n");
    scanf("%s", infix);
    push('#');

    for (i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(')
            push('(');
        else if (isalnum(infix[i]))
            postfix[j++] = infix[i];
        else if (infix[i] == ')') {
            while (stk[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); // Pop the '('
        } else {
            while (preced(stk[top]) >= preced(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
    }

    while (stk[top] != '#') {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("\nInfix expression: %s\n", infix);
    printf("Postfix expression: %s\n",postfix);

}
