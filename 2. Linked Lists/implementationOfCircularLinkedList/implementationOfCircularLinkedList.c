#include<stdio.h>
#include<stdlib.h>

/*  Create a node.
    Create a Circular Linked List:
        1.Check whether node exist or not
        2.Appending a Node
        3.Prepending a Node
        4.Inserting a Node after a particular KEY
        5.Deleting a node of a particular KEY
        6.Updating a node of a particular KEY
        7.Displaying our Doubly Linked Lists' Nodes
*/

struct Node{
    int key;
    int data;
    struct Node* link;
};

typedef struct Node *node;
node head=NULL;

//1. To check if the node exists using key value.
node findNode(int k){
    node temp=NULL;
    node ptr=head;

    if(ptr==NULL){
        return temp;
    }
    else{
        do{
            if(ptr->key==k){
                temp=ptr;
                break;
            }
            ptr=ptr->link;
        }while(ptr!=head);
    }
    return temp;
}

//2.Append a node to the list.
void appendNode(node n){
    if(findNode(n->key)!=NULL){
        printf("Node already exists with same key: %d. Append the node with another key \n",n->key);
    }else{
        if(head==NULL){
            head=n;
            n->link=head;
        }else{
            node ptr=head;
            while(ptr->link!=head){
                ptr=ptr->link;
            }
            ptr->link=n;
            n->link=head;
        }
        printf("Node Appened\n");
    }
}

//3.Prepend a Node to the list.
void prependNode(node n){
    if(findNode(n->key)!=NULL){
        printf("Node already exists with same key: %d. Append the node with another key \n",n->key);
    }else{
        if(head==NULL){
            head=n;
            n->link=head;
            printf("Node Appended\n");
        }else{
            node ptr=head;
            while(ptr->link!=head){
                ptr=ptr->link;
            }
            ptr->link=n;
            n->link=head;
            head=n;
            printf("Node Prepended\n");
        }
    }
}

//4.Insert a Node after a particular Key.
void insertNodeAfterKey(int k,node n){
    node ptr=findNode(k);
    if(ptr==NULL){
        printf("No node exists with key value: %d\n",k);
    }else{
        if(findNode(n->key)!=NULL){
            printf("Node already exists with same key: %d. Append the node with another key \n",n->key);
        }else{
            if(ptr->link==head){
                n->link=head;
                ptr->link=n;
            }else{
                n->link=ptr->link;
                ptr->link=n;
            }
            printf("Node INSERTED after the the node with key: %d",k);
        }
    }
}

//5.Delete a node of a particular Key.
void deleteNodeByKey(int k){
    node ptr=findNode(k);
    if(ptr==NULL){
        printf("No node exists with key value: %d\n",k);
    }else{
        //deleting first node
        if(ptr==head){
            if(head->link==head){
                head=NULL;
                printf("Node Unlinked... List is empty. \n");
            }else{
                node temp =head;
                while(temp->link!=head){
                    temp=temp->link;
                }
                temp->link=head->link;
                head=head->link;
            }
        }
        //deleting any node other than first node;
        else{
            node temp=NULL;
            node prevPtr=head;
            node currPtr=head->link;
            while(currPtr!=NULL){
                if(currPtr->key==k){
                    temp=currPtr;
                    currPtr=NULL;
                }else{
                    prevPtr=prevPtr->link;
                    currPtr=currPtr->link;
                }
            }
            prevPtr->link=temp->link;
        }
        printf("Node UNLINKED with key: %d\n",k);
    }
}

//6.Update a Node of a particular Node.
void updateNodeByKey(int k,int d){
    node ptr=findNode(k);
    if(ptr==NULL){
        printf("No node exists with key value: %d\n",k);
    }else{
        ptr->data=d;
        printf("Node data with key value: %d UPDATED!\n",k);
    }
}

//7.Display our Double Linked Lists' Nodes.
void displayList(){
    if(head==NULL){
        printf("List is empty\n");
    }else{
        printf("Head: %u\n",head);
        printf("CLL:\t");
        node temp=head;
        do{
            printf("(%d,%d,%u)-->",temp->key,temp->data,temp->link);
            temp=temp->link;
        }while(temp!=head);
    }
}

void main(){
    int choice,key1,k1,data1;
    while(1){
        printf("\n1.Append Node \n");
        printf("2.Prepend Node \n");
        printf("3.Insert Node after a particular KEY \n");
        printf("4.Delete Node of a particular KEY \n");
        printf("5.Update node of a particular KEY \n");
        printf("6.Display all Nodes \n");
        printf("7.Create a copy \n");
        printf("8.Reverse the list \n");
        printf("Select the operation to perform. Enter 0 to exit \n");
        scanf("%d",&choice);

        node n1 = (node)malloc(sizeof(node));
        n1->key=0;
        n1->data=0;
        n1->link=NULL;
        switch(choice){
            case 0: exit(0);
            case 1:
                printf("\n Append Node Operation \nEnter key & data of the Node to be Appended \n");
                scanf("%d%d",&key1,&data1);
                n1->key=key1;
                n1->data=data1;
                appendNode(n1);
                break;
            case 2:
                printf("\n Prepend Node Operation \nEnter key & data of the Node to be Prepended \n");
                scanf("%d%d",&key1,&data1);
                n1->key=key1;
                n1->data=data1;
                prependNode(n1);
                break;
            case 3:
                printf("\n Insert Node Operation \nEnter the key value of the existing node after which you want to insert new node:\n");
                scanf("%d",&k1);
                printf("Enter key & data of the new Node to be Inserted \n");
                scanf("%d%d",&key1,&data1);
                n1->key=key1;
                n1->data=data1;
                insertNodeAfterKey(k1,n1);
                break;
            case 4:
                printf("\n Delete Node Operation \n Enter the key of node to be deleted: \n");
                scanf("%d",&k1);
                deleteNodeByKey(k1);
                break;
            case 5:
                printf("\n Update Node Operation \n Enter the key and new data to be updated: \n");
                scanf("%d%d",&key1,&data1);
                updateNodeByKey(key1,data1);
                break;
            case 6:
                displayList();
                break;
            // case 7:
            //     printf("\n Create a Copy Operation \n");
            //     createACopy();
            //     break;
            // case 8:
            //     printf("\n Reverse Linked List Operation \n");
            //     reverseLinkedList();
            //     break;
            default: printf("\n Enter proper option \n");
        }
    }
}