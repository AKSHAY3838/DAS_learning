#include<stdio.h>
#include<string.h>
#include<stdlib.h>
# define my_stack1 5
typedef struct
{   char *day;
    int date;
    char *activity;
}calender;
calender* create(){
    calender *week;
    week=(calender *)calloc(7, sizeof(calender));
    return week;
}
void read(calender *week){
    char day[20],activity[20];
    printf("enter the details if calender(week day,date,activity):\n");
    for (int i = 0; i <7; i++){
        printf("day %d",i+1);
        scanf("%s%d%s",day,&week[i].date,activity);
        week[i].date=strdup(day);
        week[i].activity=strdup(activity);
    } 
}
 void display(calender *week){
        printf("week details\n\t\tday,\t\tdate,\t\tactivity\n");
            for (int i = 0; i < 7; i++)
            {   
                printf("\t\t%s\t\t%d\t\t%s\n", week[i].day,week[i].date,week[i].activity);
            }
            
    }
int main(){
    int chioce;
    calender *week;
    while (1)
    {
        printf("enter your choice /n 1:for create 2: for read 3:display 4:exit\n");
        scanf("%d",&chioce);
        switch (chioce)
        {
        case 1: week=create();
                if (week==NULL)
                    printf("calender is not created\n");
                else
                    printf("calender is created successfully \n");
            break;
        case 2:read(week);
            break;
        case 3: display(week);
            break;
        case 4:return 0;

        default:printf("invalid choice \n");
            break;
        }
    }
    
}