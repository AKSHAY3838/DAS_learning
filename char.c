#include<stdio.h>
#include<conio.h>
#include<string.h>
char str[50],pat[50],rep[50],ans[50];
void read();
void pat_match();

int main(){
    
    read();
    pat_match();
    getch();
    return 0;
}
void read(){
    printf("enter the string\n");
    gets(str);
    printf("enter the pattern string\n");
    flushall();
    gets(pat);
    printf("enter the replacement string\n");
    flushall();
    gets(rep);
}
void pat_match(){
    int i, j, m, k, c;
    int flag = 0;
    i = m = j = c=0;
    while (str[c]!='\0'){
        if (str[m]==pat[i]) {
        i++;
        m++;
        if (pat[i] =='\0') {
        printf("pat %s is found at position %d",pat,c);
        for ( k = 0; rep[k]!='\0'; k++,j++){
            ans[j]=rep[k];
            i=0;
            c=m;
            flag=1;
        }
    } else{
            ans[j]=str[c];
            j++;
            c++;
            m=c;
            i=0;
        }
         ans[i]='\0';
    }
    }if (flag==0)
        printf("\n pat: %s is not found in str: %S",pat,str);
    else
        printf("\n pat: %s is found in str: %s", pat,str);
   
}