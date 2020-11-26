#include<stdio.h>
#include<stdlib.h>

int size=0;

struct Student{
    char name[20];
    int regno;
    double avgMarks,marks[3];
};

typedef struct Student* student;
student read(student);
void display(student);
void calculateAvg(student);

void main(){
    student S=NULL;
    int choice;
    while(1){
        printf("\n1.Read\n2.Display\n3.Get avg of two best marks\n4.Exit\nEnter the choice:\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: S=read(S);break;
            case 2: display(S); break;
            case 3: calculateAvg(S); break;
            default:exit(0);
        }
    }
    if(S!=NULL){
        free(S);
    }
}

student read(student arr){
    int i,j;
    printf("Enter the no. of students:\n");
    scanf("%d",&size);
    if(arr!=NULL){
        free(arr);
    }
    arr = (student)malloc(size * sizeof(student));
    for(i=0;i<size;i++){
        double total=0.0;
        printf("Enter the student details:name & regno:\n");
        scanf("%s%d",(arr+i)->name,&(arr+i)->regno);
        printf("Enter three subject marks:\n");
        for(j=0;j<3;j++){
            scanf("%lf",&(arr+i)->marks[j]);
            total+=(arr+i)->marks[j];
        }
        (arr+i)->avgMarks=total/3.0;
        printf("\n");
    }
    return arr;
}

void display(student arr){
    if(size==0){
        printf("Data is empty\n");
        return;
    }
    int i;
    printf("Regno \t Name \t Marks \t\t\t Avg.\n_______________________________________________\n");
    for(i=0;i<size;i++){
        printf("%d \t %s \t %.2f\t%.2f\t%.2f\t %.2f\n",(arr+i)->regno,(arr+i)->name,(arr+i)->marks[0],(arr+i)->marks[1],(arr+i)->marks[2],(arr+i)->avgMarks);
    }
}

void calculateAvg(student arr){
    if(size==0){
        printf("Data is empty\n");
        return;
    }
    int i;
    printf("Regno \t Name \t Avg. of best two\n__________________________________\n");
    for(i=0;i<size;i++){
        double L,SL,S;
        int j;
        L=(arr+i)->marks[0];
        for(j=1;j<3;j++){
            if((arr+i)->marks[j]>L){
                L=(arr+i)->marks[j];
            }
        }
        S=(arr+i)->marks[0];
        for(j=1;j<3;j++){
            if((arr+i)->marks[j]<S){
                S=(arr+i)->marks[j];
            }
        }
        SL= ((arr+i)->marks[0]+(arr+i)->marks[1]+(arr+i)->marks[2]) -(L+S);
        double avg=(L+SL)/2.0;
        printf("%d \t %s \t %.2f\n",(arr+i)->regno,(arr+i)->name,avg);
    }
}