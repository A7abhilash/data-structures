#include<stdio.h>
#include<stdlib.h>

/*  Create a node.
    Create a Doubly Linked List:
        1.Check whether node exist or not
        2.Appending a Node
        3.Prepending a Node
        4.Inserting a Node after a particular KEY
        5.Deleting a node of a particular KEY
        6.Updating a node of a particular KEY
        7.Displaying our Doubly Linked Lists' Nodes
*/

struct Node{
    int key,data;
    struct Node* prev;
    struct Node* next;
};
typedef struct Node* node;

node head=NULL;

//1.Check whether the node exist using key value.
node findNode(int k){
    node temp=head,ptr=NULL;

    while(temp!=NULL){
        if(temp->key == k){
            ptr=temp;
            break;
        }
        temp=temp->next;
    }
    return ptr;
}

//2.Append a node to the list.
void appendNode(node n){
    if(findNode(n->key)!=NULL){
        printf("Node already exists with the key: %d. Append another Node with different key value. \n",n->key);        
    }else{
        if(head==NULL){
            head=n;
        }else{
            node temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=n;
            n->prev=temp;
        }
        printf("Node appended\n");
    }
}

//3.Prepend a node to the list.
void prependNode(node n){
    if(findNode(n->key)!=NULL){
        printf("Node already exists with the key: %d. Append another Node with different key value. \n",n->key);        
    }else{
        if(head==NULL){
            head=n;
            printf("Node appended\n");
        }else{
            head->prev=n;
            n->next=head;
            head=n;
            printf("Node prepended\n");
        }
    }    
}

//4.Insert a node after a particular key.
void insertNodeAfterKey(int k, node n){
    node ptr = findNode(k) ;
    if(ptr==NULL){
        printf("No node exists with the key: %d\n",k);
    }else{
        if(findNode(n->key)!=NULL){
            printf("Node already exists with the key: %d. Append another Node with different key value. \n",n->key);        
        }else{
            node nextNode=ptr->next;

            if(nextNode==NULL){
                //Appending
                ptr->next=n;
                n->prev=ptr;
                printf("Node appended\n");
            }else{
                //Inserting in between
                n->next=nextNode;
                nextNode->prev=n;
                n->prev=ptr;
                ptr->next=n;
                printf("Node inserted\n");
            }
        }
    }
}

//5.Delete a node of a particular key(unlink).
void deleteNodeByKey(int k){
    node ptr = findNode(k) ;
    if(ptr==NULL){
        printf("No node exists with the key: %d\n",k);
    }else{
        if(head->key==k){
            //deleting at the beginning
            head=head->next;
            printf("Node deleted at the start with key: %d\n",k);
        }else{
            node prevNode=ptr->prev;
            node nextNode=ptr->next;

            if(nextNode==NULL){
                //deleting at the end
                prevNode->next=NULL;
                printf("Node deleted at the end with key: %d\n",k);
            }else{
                //deleting in between
                prevNode->next=nextNode;
                nextNode->prev=prevNode;
                printf("Node deleted with key: %d\n",k);
            }
        }
    }
}

//6.Updating a Node of a particular key.
void updateNodeByKey(int k,int d){
    node ptr=findNode(k);
    if(ptr==NULL){
        printf("No node exists with the key: %d\n",k);
    }else{
        ptr->data=d;
        printf("Node's data updated\n");
    }
}

void displayList(){
    if(head==NULL){
        printf("List is empty\n");
    }else{
        printf("DLL:\t");

        node temp=head;
        while(temp!=NULL){
            printf("(%d,%d)-->",temp->key,temp->data);
            temp=temp->next;
        }
        printf("");
    }
}

void main(){
    int choice;
    int k1,d1;

    while(1){
        printf("\n1.Append Node \n");
        printf("2.Prepend Node \n");
        printf("3.Insert Node after a particular KEY \n");
        printf("4.Delete Node of a particular KEY \n");
        printf("5.Update node of a particular KEY \n");
        printf("6.Display all Nodes \n");
        printf("Select the operation to perform. Enter 0 to exit \n");
        scanf("%d",&choice);

        node n1 = (node)malloc(sizeof(struct Node));
        n1->next=NULL;
        n1->prev=NULL;
        switch(choice){
            case 0: exit(0);
            case 1: printf("Append Node Operation \nEnter key & data of the Node to be Appended \n");
                    scanf("%d%d",&n1->key,&n1->data);
                    appendNode(n1);
                    break;
            case 2: printf("Prepend Node Operation \nEnter key & data of the Node to be Prepended \n");
                    scanf("%d%d",&n1->key,&n1->data);
                    prependNode(n1);
                    break;
            case 3: printf("Insert Node Operation \n Enter the key value after which you want to insert new Node: \n");
                    scanf("%d",&k1);
                    printf("Enter the key and data:\n");
                    scanf("%d%d",&n1->key,&n1->data);
                    insertNodeAfterKey(k1,n1);
                    break;
            case 4: printf("Delete Node Operation \n Enter the key of node to be deleted: \n");
                    scanf("%d",&k1);
                    deleteNodeByKey(k1);
                    break;
            case 5: printf("Update Node Operation \n Enter the key and new data to be updated: \n");
                    scanf("%d%d",&k1,&d1);
                    updateNodeByKey(k1,d1);
                    break;
            case 6: displayList(); 
                    break;
            default: printf("Enter proper choide\n");
        }
    }
}