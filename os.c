// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <sys/wait.h>
// int main() {
 
//  pid_t child_pid; char ch[3];
 
//  child_pid = fork();
//  if (child_pid == -1) {

//  perror("fork");
//  exit(EXIT_FAILURE);
//  }
//  if (child_pid == 0) {
 
//  printf("Child process (PID: %d) is running.\n", getpid());

//  //abort();
// // return(-1); 
// execl("/bin/date","date", NULL);
// exit(0); 
//  } 
// else {

//  printf("Parent process (PID: %d) is waiting for the child to terminate.\n", getpid());

//  int status;
 
// wait(&status);
// printf("parent resumes\n");
//  if (WIFEXITED(status)) {
//  printf("\nChild process (PID: %d) terminated with status %d.\n", child_pid, 
// WEXITSTATUS(status));
//  } else if (WIFSIGNALED(status)) {
//  printf("\nChild process (PID: %d) terminated due to signal %d.\n", child_pid, 
// WTERMSIG(status));
//  } else {
//  printf("\nChild process (PID: %d) terminated abnormally.\n", child_pid);}
//  }
//  return 0;
// }



// __________________________________________________________________________________________________________________________
// __________________________________________________________________________________________________________________________
// __________________________________________________________________________________________________________________________
// __________________________________________________________________________________________________________________________



// #include<stdio.h>
// int main()
// {
// int bt[20], wt[20], tat[20], i, n;
// float wtavg, tatavg;
// printf("\nEnter the number of processes -- ");
// scanf("%d", &n);
// for(i=0;i<n;i++)
// {
// printf("\nEnter Burst Time for Process %d -- ", i);
// scanf("%d", &bt[i]);
// }
// wt[0] = wtavg = 0;
// tat[0] = tatavg = bt[0];
// for(i=1;i<n;i++)
// {
// wt[i] = wt[i-1] +bt[i-1];
// tat[i] = tat[i-1] +bt[i];
// wtavg = wtavg + wt[i];
// tatavg = tatavg + tat[i];

// }
// printf("\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n");
// for(i=0;i<n;i++)
// printf("\n\t P%d \t\t %d \t\t %d \t\t %d", i, bt[i], wt[i], tat[i]);
// printf("\nAverage Waiting Time -- %f", wtavg/n);
// printf("\nAverage Turnaround Time -- %f", tatavg/n);
// }



__________________________________________________________________________________________________________________________
__________________________________________________________________________________________________________________________
__________________________________________________________________________________________________________________________
__________________________________________________________________________________________________________________________







#include<stdio.h>
#include <stdlib.h>
int mutex = 1;
int full = 0;
int empty = 3, x = 0;
void producer(){
 --mutex;
 ++full;
 --empty;
 x++;
 printf("\nProducer produces item %d",x);
 ++mutex;
}
void consumer(){
 --mutex;
 --full;
 ++empty;
 printf("\nConsumer consumes item %d",x);
 x--;
 ++mutex;
}
int main(){
 int n, i;
 printf("\n1. Press 1 for Producer"
 "\n2. Press 2 for Consumer"
 "\n3. Press 3 for Exit");
#pragma omp critical
 for (i = 1; i > 0; i++) {
 printf("\nEnter your choice:");
 scanf("%d", &n);

 switch (n) {
 case 1:
 if ((mutex == 1) && (empty != 0))
 {
 producer();
 }
 else
 {
 printf("Buffer is full!");
 }
 break;
 case 2:   if ((mutex == 1)&& (full != 0))
                {
                    consumer();
                }
            else
                {
                    printf("Buffer is empty!");
                }
            break;
 case 3: exit(0);
        break;
 }
 }
}
