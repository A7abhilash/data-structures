#include<stdio.h>
#include<stdlib.h>

struct NODE{
    int data;
    struct NODE *link;
};
typedef struct NODE *node;
int NE=0;

node InsertFront(node L){
    node n=(node)malloc(sizeof(struct NODE));
    printf("Enter the data:\n");
    scanf("%d",&n->data);
    n->link=n;
    NE++;
    if(L==NULL) {
        return n;
    }
    n->link=L->link;
    L->link=n;
    return L;
}

node InsertRear(node L){
    node n=(node)malloc(sizeof(struct NODE));
    printf("Enter the data:\n");
    scanf("%d",&n->data);
    n->link=n;
    NE++;
    if(L==NULL){
        return n;
    }
    n->link=L->link;
    L->link=n;
    return n;
}

node DeleteFront(node L){
    if(L==NULL){
        printf("List is empty\n");
        return NULL;
    }
    node temp=L->link;
    printf("Front node deleted with data %d\n",temp->data);
    if(L==L->link){
        L=NULL;
    }else{
        L->link=temp->link;
    }
    free(temp);
    NE--;
    return L;
}

node DeleteRear(node L){
    if(L==NULL){
        printf("List is empty\n");
        return NULL;
    }
    node ptr=L->link;
    printf("Rear node deleted with data: %d\n",L->data);
    NE--;
    if(L==L->link){
        L=ptr=NULL;
    }else{
        while(ptr->link!=L){
            ptr=ptr->link;
        }
        ptr->link=L->link;
    }
    free(L);
    return ptr;
}

node InsertPos(node L){
    int position,count=1;
    printf("Enter the position:\n");
    scanf("%d",&position);
    if(position>=1 && position <=NE+1){
        if(position==1) return InsertFront(L);
        if(position==NE+1) return InsertRear(L);
        NE++;
        node n,temp=L->link,ptr=NULL;
        n=(node)malloc(sizeof(struct NODE));
        printf("Enter the new data:\n");
        scanf("%d",&n->data);
        while(count<position){
            ptr=temp;
            temp=temp->link;
            count++;
        }
        ptr->link=n;
        n->link=temp;
    }else printf("Invalid position");
    return L;
}

node DeletePos(node L){
    if(L==NULL){
        printf("List is empty\n");
        return NULL;
    }
    int position,count=1;
    printf("Enter the position of the node to be deleted:\n");
    scanf("%d",&position);
    if(position>=1 && position<=NE){
        if(position==1) return DeleteFront(L);
        if(position==NE) return DeleteRear(L);

        node ptr=NULL,temp=L->link;
        while(count<position){
            ptr=temp;
            temp=temp->link;
            count++;
        }
        ptr->link=temp->link;
        NE--;
        printf("Node deleted with data: %d\n",temp->data);
        free(temp);
    }else printf("Inavlid position\n");
    return L;
}

node InsertByOrder(node L){
    node n=(node)malloc(sizeof(node));
    printf("Enter the data:\n");
    scanf("%d",&n->data);
    n->link=n;
    NE++;
    if(L==NULL){
        return n;
    }
    if(n->data <= L->link->data){
        n->link=L->link;
        L->link=n;
        return L;
    }
    if(n->data > L->data){
        n->link=L->link;
        L->link=n;
        return n;
    }
    node ptr=NULL,temp=L->link;
    do{
        ptr=temp;
        temp=temp->link;
    }while(temp->data < n->data);
    ptr->link=n;
    n->link=temp;
    return L;
}

node DeleteKey(node L){
    if(L==NULL){
        printf("List is empty\n");
        return NULL;
    }
    int data;
    printf("Enter the data to be deleted:\n");
    scanf("%d",&data);
    
    if(L->link->data==data) return DeleteFront(L);
    if(L->data==data) return DeleteRear(L);

    node temp=L->link,ptr=NULL;
    int position=1;
    do
    {
        ptr=temp;
        temp=temp->link;
        position++;
    } while (temp->data!=data);
    
    if(position==NE){
        printf("Node with data %d doesnt exist\n",data);
    }else{
        ptr->link = temp->link;
        printf("Node with data %d deleted from position: %d\n",temp->data,position);
        free(temp);
        NE--;
    }
    return L;
}

void Search(node L){
    if(L==NULL){
        printf("List is empty\n");
        return;
    }
    node ptr=NULL,temp=L->link;
    int data,position=1;
    printf("Enter the data to be searched:\n");
    scanf("%d",&data);
    do
    {
        if(temp->data==data){
            ptr=temp;
            break;
        }
        temp=temp->link;
        position++;
    } while (temp!=L->link);
    if(ptr==NULL){
        printf("Node with data %d doesnt exist\n",data);
    }else{
        printf("Node with data %d is at position: %d",ptr->data,position);
    }   
}

void Disp(node L){
    if(L==NULL){
        printf("List is empty\n");
        return;
    }
    node temp=L->link;
    printf("No. of nodes: %d\n",NE);
    do{
        printf("%d-->",temp->data);
        temp=temp->link;
    }while(temp!=L->link);
}

void main(){
    int choice;
    node last=NULL;
    while(1){
        printf("\nenter choice:\n1:InsertFront\n2:Disply\n3:InsertRear\n4:DeleteFront\n5:DeleteRear\n6:InsertByposition\n7:DeleteByposition\n8:InsertByOrder\n9:DeleteByKey\n10:Search Key\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: last =InsertFront(last);
                    Disp(last);
                    break;
            case 2: Disp(last); 
                    break;
	        case 3: last=InsertRear(last);
                    Disp(last);
                    break;
            case 4: last = DeleteFront(last); 
                    Disp(last);
                    break;
	        case 5: last = DeleteRear(last);
                    Disp(last);
                    break;
	        case 6: last = InsertPos(last);
                    Disp(last);
                    break;
	        case 7: last = DeletePos(last);
                    Disp(last);
                    break;
	        case 8: last = InsertByOrder(last);
                    Disp(last);
                    break;
            case 9: last = DeleteKey(last);
                    Disp(last);
                    break;
	        case 10:Search(last);
                    break;
            default:exit(0); 
        }
    }
}