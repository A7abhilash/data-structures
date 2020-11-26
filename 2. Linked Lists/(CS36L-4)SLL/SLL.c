#include<stdio.h>
#include<stdlib.h>

struct NODE
{
  int data;
  struct NODE *link;
};
typedef struct NODE *node;

int NE=0;

node InsertFront(node F){
    node n;
    n=(node)malloc(sizeof(struct NODE));
    printf("Enter the data:\n");
    scanf("%d",&n->data);
    n->link=F;
    NE++;
    return n;
}

node InsertRear(node F){
    node n,temp=F;
    n=(node)malloc(sizeof(struct NODE));
    printf("Enter the data:\n");
    scanf("%d",&n->data);
    n->link=NULL;
    NE++;
    if(F==NULL){
        return n;
    }
    while(temp->link!=NULL){
        temp=temp->link;
    }
    temp->link=n;
    return F;
}

node DeleteFront(node F){
    if(F==NULL){
        printf("List is empty\n");
        return NULL;
    }
    node ptr=F;
    printf("Front node deleted with data: %d\n",ptr->data);
    F=F->link;
    free(ptr);
    NE--;
    return F;
}

node DeleteRear(node F){
    if(F==NULL){
        printf("List is empty\n");
        return NULL;
    }
    NE--;
    if(F->link==NULL){ //If only one node exists
        printf("Front node deleted with data: %d\n",F->data);
        free(F);
        return NULL;
    }
    node ptr=NULL,temp=F;
    while(temp->link!=NULL){
        ptr=temp;
        temp=temp->link;
    }
    printf("Rear node deleted with data: %d\n",temp->data);
    ptr->link=NULL;
    free(temp);
    return F;
}

node InsertPos(node F){
    int position;
    printf("Enter the position:\n");
    scanf("%d",&position);
    if(position>=1 && position<=NE+1){
        int count=1;
        node n,temp=F,ptr=NULL;
        n=(node)malloc(sizeof(struct NODE));
        printf("Enter the new data:\n");
        scanf("%d",&n->data);
        n->link=NULL;
        NE++;
        if(position==1){
            n->link=F;
            return n;
        }
        while(count<position){
            ptr=temp;
            temp=temp->link;
            count++;
        }
        ptr->link=n;
        n->link=temp;
    }else printf("Invalid position\n");
    return F;
}

node DeletePos(node F){
    if(F==NULL){
        printf("List is empty\n");
        return NULL;
    }
    int count=1,position;
    printf("Enter the position of data to be deleted:\n");
    scanf("%d",&position);
    if(position>=1 && position<=NE){
        NE--;
        node temp=F,ptr=NULL;
        if(position==1){
            F=F->link;
            printf("Front node deleted with data: %d\n",temp->data);
            free(temp);
            return F;
        }
        while(count<position){
            ptr=temp;
            temp=temp->link;
            count++;
        }
        ptr->link=temp->link;
        printf("Node deleted with data: %d\n",temp->data);
        free(temp);
    }else printf("Invalid position\n");
    return F;
}

node InsertByOrder(node F){
    node n,temp=F,ptr=NULL;
    n=(node)malloc(sizeof(struct NODE));
    printf("Enter the new data:\n");
    scanf("%d",&n->data);
    n->link=NULL;
    NE++;
    if(F==NULL){
        return n;
    }
    if(n->data <= F->data){
        n->link=F;
        return n;
    }
    while(temp!=NULL && temp->data < n->data){
        ptr=temp;
        temp=temp->link;
    }
    ptr->link=n;
    n->link=temp;
    return F;
}

node DeleteKey(node F){
    if(F==NULL){
        printf("Empty list");
        return NULL;
    }
    node temp=F,ptr=NULL;
    int data;
    printf("Enter the data to be deleted:\n");
    scanf("%d",&data);
    if(F->data==data){
        NE--;
        F=F->link;
        printf("Node deleted with data: %d",temp->data);
        free(temp);
        return F;
    }
    while(temp!=NULL && temp->data!=data){
        ptr=temp;
        temp=temp->link;
    }
    if(temp==NULL){
        printf("Node with data: %d doesn't exist\n",data);
        return F;
    }
    ptr->link=temp->link;
    printf("Node deleted with data: %d",temp->data);
    free(temp);
    NE--;
    return F;
}

void Search(node F){
    if(F==NULL){
        printf("Empty list");
        return ;
    }
    node temp=F;
    int data,position=1;
    printf("Enter the data to be searched:\n");
    scanf("%d",&data);
    while(temp!=NULL && temp->data!=data){
        temp=temp->link;
        position++;
    }
    if(temp==NULL){
        printf("Node with data %d doesn't exist\n",data);
    }else{
        printf("Node with data %d exists at position: %d\n",data,position);
    }
}

node CreateCopy(node F){
    if(F==NULL) return NULL;

    node ptr=NULL,temp,n;
    while(F!=NULL){
        n=(node)malloc(sizeof(struct NODE));
        n->data=F->data;
        n->link=NULL;
        if(ptr==NULL){
            ptr=n;
            temp=ptr;
        }else{
            temp->link=n;
            temp=n;
        }
        F=F->link;
    }
    return ptr;
}

node Reverse(node F){
    if(F==NULL) return NULL;
    node next,prev=NULL;
    while(F!=NULL){
        next=F;
        F=F->link;
        next->link=prev;
        prev=next;
    }
    return next;
}

void Disp(node F){
    printf("No. of nodes: %d\n",NE);
    if(F==NULL){
        printf("List is empty\n");
        return;
    }
    while(F!=NULL){
        printf("%d-->",F->data);
        F=F->link;
    }
    printf("");
}

void main()
{
   int choice;
   node first= NULL, L2=NULL;
   while(1)
   {
      printf("\n1:InsertFront\n2:Display\n3:InsertRear\n4:DeleteFront\n5:DeleteRear\n6:InsertByposition\n7:DeleteByposition\n8:InsertByOrder\n9:DeleteByKey\n10:Search Key\n11:Create Copy\n12:Reverse\nenter choice:\n");
      scanf("%d",&choice);
      switch(choice)
      {
	case 1: first =InsertFront(first);
            Disp(first);
            break;
	case 2: Disp(first);
            break;
	case 3: first=InsertRear(first); 
            Disp(first); 
            break;
	case 4: first = DeleteFront(first); 
            Disp(first); 
            break;
	case 5: first = DeleteRear(first);
            Disp(first);
            break;
	case 6: first = InsertPos(first);
            Disp(first);
            break;
	case 7: first = DeletePos(first);
            Disp(first);
            break;
	case 8: first = InsertByOrder(first);
            Disp(first);
            break;
	case 9: first = DeleteKey(first);
            Disp(first);
            break;
	case 10: Search(first);
             break;
    case 11: L2=CreateCopy(first);
            printf("\ncopy of the list is:");
            Disp(L2);
            break;
	case 12: first = Reverse(first);
             printf("\nReversed list is:\n");
             Disp(first);
             break;
    default:exit(0);
     }
 }
 }
