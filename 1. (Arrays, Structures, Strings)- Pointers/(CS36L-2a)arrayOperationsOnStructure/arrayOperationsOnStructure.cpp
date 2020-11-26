#include<iostream>
#include<string.h>
using namespace std;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      

struct Student{
    int regno;
    char name[20];
    int totalMarks;
};

void read(struct Student[]);
void display(struct Student[]);
void findMaxTotal(struct Student[]);
void insertByOrder(struct Student[]);
void deleteByOrder(struct Student[]);

int SIZE=10,NE=0;

int main(){
    int choice;
    struct Student S[SIZE];

    while(1){
        cout<<"\nEnter the choice:\n1.Read\n2.Display\n3.Find max total marks\n4.Insert\n5.Delete\n[Any other value].Exit\n";
        cin>>choice;

        switch (choice)
        {
        case 1: read(S);
            break;
        case 2: display(S);
            break;
        case 3: findMaxTotal(S);
            break;
        case 4: insertByOrder(S);
            break;
        case 5: deleteByOrder(S);
            break;
        default:exit(0);
        }
    }
    return 0;
}


void read(struct Student S[])
{
    int i,n;
    cout<<"Enter the no. of students: \n";
    cin>>n;
    cout<<"Enter the student details in order of thier regNo:\n";
    for (i = 0; i < n; i++)
    {
    cout<<"Enter the details(regno, name & total marks) of student:"<<i+1<<endl;
        cin>>S[i].regno>>S[i].name>>S[i].totalMarks;
    }
    NE=n;
    display(S);
}

void display(struct Student S[]){
    if(NE==0){
        cout<<"No record found.\n";return;
    }
    int i;
    cout<<"Regno \t Name \t Total marks\n_______________________________\n";
    for (int i = 0; i <NE; i++)
    {
        cout<<S[i].regno<<"\t"<<S[i].name<<"\t"<<S[i].totalMarks<<endl;
    }
}


void findMaxTotal(struct Student S[]){
    int large, si,i;
    large=S[0].totalMarks;
    si=0;

    for(i =1;i<NE;i++){
        if(S[i].totalMarks>large){
            large=S[i].totalMarks;
            si=i;
        }
    }
    cout<<"Highest total marks is: "<<large<<" by the student: "<<S[si].name<<endl;
}

void insertByOrder(struct Student S[]){
    if(NE==SIZE){
        cout<<"Record is full\n"; return;
    }
    int i,regno,totalMarks;
    char name[20];
    cout<<"Enter the details(regno, name & total marks) of the new student: \n";
    cin>>regno>>name>>totalMarks;
    
    for(i=NE-1;i>=0 && S[i].regno>regno;i--){
        S[i+1].regno=S[i].regno;
        strcpy(S[i+1].name,S[i].name);
        S[i+1].totalMarks=S[i].totalMarks;
    }
    S[i+1].regno=regno;
    strcpy(S[i+1].name,name);
    S[i+1].totalMarks=totalMarks;

    NE++;
    display(S);
}
void deleteByOrder(struct Student S[]){
    if(NE==0){
        cout<<"Record is empty\n";return;
    }

    int i,regno;
    cout<<"Enter the regno of the student to be deleted";
    cin>>regno;

    for(i=0;i<NE && S[i].regno!=regno;i++);
        if(i==NE){
            cout<<"Invalid regno\n";return;
        }
    //Now the index of the student to be deleted will be stored in "i";
    cout<<"Deleted Student name: "<<S[i].name<<endl;
    for(;i<NE-1;i++){
        S[i].regno=S[i+1].regno;
        strcpy(S[i].name,S[i+1].name);
        S[i].totalMarks=S[i+1].totalMarks;
    }
    NE--;
}