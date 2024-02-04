#include<stdio.h>
//a=source,b=temp,c=destination
void tower(int num,char a,char b,char c){
    if (num==1){
        printf("move disk 1 from peg %c to peg %C \n",a,c);
        return;
    }
    tower(num-1,a,b,c);
    printf("move disk %d from peg %c to peg %C \n",num,b,a,c);
    tower(num-1,b,a,c);
}
int main(){
    int num;
    printf("enter number of disks\n");
    scanf("%d",&num);
    tower(num,'c','b','c');
    
}