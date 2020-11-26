#include<stdio.h>
#include<stdlib.h>

struct NODE{
    int data;
    struct NODE *prev,*next;
};
typedef struct NODE * node;

void insertFront(node H){
    node n;
    n=(node)malloc(sizeof(struct NODE));
    printf("Enter the data:\n");
    scanf("%d",&n->data);
    n->prev=H;
    n->next=H->next;
    n->next->prev=n;
    H->next=n;
    H->data++;
}

void insertRear(node H){
    node n;
    n=(node)malloc(sizeof(struct NODE));
    printf("Enter the data:\n");
    scanf("%d",&n->data);
    n->prev=H->prev;
    n->next=H;
    H->prev->next=n;
    H->prev=n;
    H->data++;
}

void deleteFront(node H){
    if(H->data==0){
        printf("Empty List\n");
        return;
    }
    node ptr=H->next;
    printf("Node deleted at front with data:%d\n",ptr->data);
    H->next=ptr->next;
    ptr->next->prev=H;
    H->data--;
    free(ptr);
}

void deleteRear(node H){
    if(H->data==0){
        printf("Empty List\n");
        return;
    }
    node ptr=H->prev;
    printf("Node deleted at rear with data:%d\n",ptr->data);
    ptr->prev->next=H;
    H->prev=ptr->prev;
    H->data--;
    free(ptr);
}

void insertByPosition(node H){
    int position,count=1;
    printf("Enter the position for new node to be inserted:\n");
    scanf("%d",&position);
    if(position>=1 && position<=H->data+1){
    if(position==1) return insertFront(H);
    if(position==H->data+1) return insertRear(H);

    node n,temp=H;
    n=(node)malloc(sizeof(struct NODE));
    printf("Enter the data:\n");
    scanf("%d",&n->data);
        while(count<position){
            temp=temp->next;
            count++;
        }
        n->next=temp->next;
        n->prev=temp;
        temp->next=n;
        n->next->prev=n;
        H->data++;
    }else{
        printf("Invalid Position\n");
    }
}

void deleteByPosition(node H){
    if(H->data==0){
        printf("Empty List\n");
        return;
    }
    int position,count=1;
    printf("Enter the position of the node to be deleted:\n");
    scanf("%d",&position);
    if(position>=1 && position<=H->data){
    if(position==1) return deleteFront(H);
    if(position==H->data) return deleteRear(H);

    node temp=H->next;
    while(count!=position){
        temp=temp->next;
        count++;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    printf("Node deleted with data:%d\n",temp->data);
    H->data--;
    free(temp);
    }else{
        printf("Invalid Position\n");
    }
}

void deleteByValue(node H){
    if(H->data==0){
        printf("Empty List\n");
        return;
    }
    node temp=H->next;
    int data,position=1;
    printf("Enter the data of the node to be deleted:\n");
    scanf("%d",&data);
    while(temp!=H && temp->data!=data){
        temp=temp->next;
        position++;
    }
    if(temp==H){
        printf("Node with data %d doesnt exist\n",data);
    }else{
        if(position==1) return deleteFront(H);
        if(position==H->data+1) return deleteRear(H);

        printf("Node deleted with data:%d from position: %d\n",temp->data,position);
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
        H->data--;
    }
}

void findNode(node H){
    if(H->data==0){
        printf("Empty List\n");
        return;
    }
    int position=1,data;
    printf("Enter the data of the node to be searched:\n");
    scanf("%d",&data);
    node temp=H->next;
    while(temp!=H && temp->data!=data){
        temp=temp->next;
        position++;
    }
    if(temp==H){
        printf("Node with data %d doesnt exist\n",data);
    }else{
        printf("Node with data %d exists at position: %d\n",data,position);
    }
}

void display(node H){
    if(H->data==0){
        printf("Empty List\n");
        return;
    }
    node temp;
    temp=H->next;
    printf("Total no. of nodes:%d\n",H->data);
    printf("CDLL:\t");
    while(temp!=H){
        printf("(%d)<->",temp->data);
        temp=temp->next;
    }
}

int main(){
    int choice;
    node head;
    head=(node)malloc(sizeof(struct NODE));
    head->data=0;//*keeps the count of total no. of nodes
    head->prev=head->next=head;
    while(1){
        printf("\n1:Insert Front\n2:Display\n3:Insert Rear\n4:Delete Front\n5:Delete Rear\n6:Insert By Position\n7:Delete By Position\n8:Delete By Value\n9:Search Node\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1: insertFront(head);
                    display(head);
                    break;
            case 2: display(head);break;
            case 3: insertRear(head);    
                    display(head);
                    break;
            case 4: deleteFront(head);    
                    display(head);
                    break;
            case 5: deleteRear(head);    
                    display(head);
                    break;
            case 6: insertByPosition(head);    
                    display(head);
                    break;
            case 7: deleteByPosition(head);    
                    display(head);
                    break;
            case 8: deleteByValue(head);    
                    display(head);
                    break;
            case 9: findNode(head);
                    break;
            default:exit(0);
        }
    }
    return 0;
}