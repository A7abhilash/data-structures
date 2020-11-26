/* Define a structure called Time containing 3 integer members(hour,minute,second).
Develop a menu driven program to perform the following by writing separate function for each operation.
a) To read time b) To display time c)To Update time d) Add two times by writing Add(T1,T2) which returns the new Time.
Update function increments the time by one second and returns the new time(if the increment results in 60 seconds,
then the second member is set to zero and minute member is incremented by one. Then , if the result is 60
minutes, the minute member is set to zero and the hour member is incremented by one.
Finally when the hour becomes 24, it is set to zero) */

#include<stdio.h>
#include<stdlib.h>

struct Time{
    int hr,min,sec;
};
typedef struct Time time;

void read(time *);
void display(time *);
void update(time *);
time add(time *,time *);
void format(time *);

void main(){
    int choice;
    time T1,T2,T3;
    while(1){
        printf("\n1.Read two times\n2.Update two times by 1 second\n3.Add two times\n4.exit\nEnter your choice:\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: read(&T1);
                    read(&T2);
                    printf("Time 1: "); display(&T1);
                    printf("Time 2: "); display(&T2);
                    break;
            case 2: update(&T1);
                    update(&T2);
                    printf("Updated Time 1: "); display(&T1);
                    printf("Updated Time 2: "); display(&T2);
                    break;
            case 3: T3=add(&T1,&T2);
                    printf("Sum of Time 1 & Time 2: "); display(&T3);
                    break;
            case 4: exit(0);
            default: printf("Enter proper choice\n");
        }
    }
}

void read(time *T){
    printf("Enter the hours, minutes and seconds:\n");
    scanf("%d%d%d",&T->hr,&T->min,&T->sec);
    format(T);
}

void display(time *T){
    printf("%dhrs %dmins %dsecs\n",T->hr,T->min,T->sec);
}

void update(time *T){
    T->sec++;
    format(T);
}

time add(time* T1,time *T2){
    time t3;
    t3.hr=T1->hr+T2->hr;
    t3.min=T1->min+T2->min;
    t3.sec=T1->sec+T2->sec;
    format(&t3);
    return t3;
}

void format(time *T){
    if(T->sec>=60){
        T->min += T->sec/60;
        T->sec = T->sec%60;
    }
    if(T->min>=60){
        T->hr += T->min/60;
        T->min = T->min%60;
    }
    if(T->hr>=24){
        T->hr=T->min=T->sec=0;
    }
}