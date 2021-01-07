#include<stdio.h>
#include<stdlib.h>

void read(int []);
void display(int []);
void insertByPosition(int []);
void deleteByPosition(int []);

int SIZE=10,NE=0;

int main() {
    int a[SIZE],choice;

    while(1){
        printf("\nEnter the choice:\n1.Read\n2.Display\n3.Insert\n4.Delete\n5.Exit\n");
        scanf("%d",&choice);
        
        switch (choice){
            case 1: read(a);
                break;
            case 2: display(a);
                break;
            case 3: insertByPosition(a);
                break;
            case 4:deleteByPosition(a);
                break;
            default:exit(0);
        }
    }
    return 0;
}


void read(int a[]){
    int i,n;
    printf("Enter the no. of elements:\n");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    NE=n;
}

void display(int a[]){
    int i;
    if(NE==0){
        printf("Array is empty\n");
        return;
    }
    printf("Array elements are:\n");
    for(i=0;i<NE;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

void insertByPosition(int a[]){
    int i,pos,element;
    if(NE==SIZE){
        printf("Array is full\n");
        return;
    }
    printf("Enter the position of new element to be inserted:\n");
    scanf("%d",&pos);

    if(pos>=1 && pos<=NE+1){
        printf("Enter the value of new element to be inserted:\n");
        scanf("%d",&element);

        for(i=NE;i>=pos;i--){
            a[i]=a[i-1];
        }
        a[i]=element;
        NE++;
        printf("Array elements after insertion operation:\n");
        display(a);
    }else printf("Invalid position\n");
}

void deleteByPosition(int a[]){
    int pos,i;
    if(NE==0){
        printf("Array is empty\n");
        return;
    }
    printf("Enter the position of element to be deleted:\n");
    scanf("%d",&pos);

    if(pos>=1 && pos<=NE ){
        for(i=pos-1;i<NE-1;i++){
            a[i]=a[i+1];
        }
        NE--;
        printf("Array elements after deletion operation:\n");
        display(a);
    }else printf("Invalid position\n");
}