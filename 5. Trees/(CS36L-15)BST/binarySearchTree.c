#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct NODE{
    int data;
    struct NODE* left;
    struct NODE* right;
};
typedef struct NODE* node;

node insertNewNode(node R){
    int i;
    char direction[10];
    node newNode=(node)malloc(sizeof(struct NODE));
    printf("Enter the data:");
    scanf("%d",&newNode->data);
    newNode->left=newNode->right=NULL;
    
    if(R==NULL){
        printf("New node inserted as the root\n");
        return newNode;
    }
    
    node previousNode=NULL, childNode=R;

    while(childNode!=NULL){
        previousNode=childNode;
        if(childNode->data>=newNode->data) childNode=childNode->left;
        else childNode=childNode->right;
    }

    if(previousNode->data>newNode->data) previousNode->left=newNode;
    else previousNode->right=newNode;
    
    printf("New node inserted\n");
    return R;
}

void inOrder(node R){
    if(R==NULL) return;
    inOrder(R->left);
    printf("%d ",R->data);
    inOrder(R->right);
}
void postOrder(node R){
    if(R==NULL) return;
    postOrder(R->left);
    postOrder(R->right);
    printf("%d ",R->data);
}
void preOrder(node R){
    if(R==NULL) return;
    printf("%d ",R->data);
    preOrder(R->left);
    preOrder(R->right);
}

void displayTree(node R){
    if(R==NULL){
        printf("Tree is empty\n");
        return;
    }
    printf("\nInOrder Traversal: "); inOrder(R);
    printf("\nPostOrder Traversal: "); postOrder(R);
    printf("\nPreOrder Traversal: "); preOrder(R);
    printf("\n");
}

node searchNode(node R, int data,node* parentNode){
    if(R==NULL) return NULL;
    if(R->data==data){
        return R;
    }
    node nodeToBeSearched=NULL;
    if(R->data > data){
        *parentNode=R;
        return nodeToBeSearched=searchNode(R->left,data,parentNode);
    }
    if(R->data < data){
        *parentNode=R;
        return nodeToBeSearched=searchNode(R->right,data,parentNode);
    }
}
node deleteNode(node R){
    if(R==NULL){
        printf("Tree is empty\n");
        return NULL;
    }
    int data;
    printf("Enter the data of the node to be deleted:");
    scanf("%d",&data);
    
    //* If the node to be deleted is the root and has children.
    if(R->data==data && (R->left!=NULL || R->right!=NULL)){
        printf("Root node can't be deleted unless it has no child.\n");
        return R;
    }
    //*CASE 1: If the node to be deleted is the root and has no children.
    if(R->data==data && R->left==NULL && R->right==NULL){
        printf("Deleted root node with data = %d\n",R->data);
        free(R);
        return NULL;
    }
    
    //*Search the node
    node parentNode;
    node nodeToBeDeleted=searchNode(R,data,&parentNode);
    if(nodeToBeDeleted==NULL){
        printf("Node with data = %d doesn't exist in the tree\n",data);
        return R;
    }else{
        printf("Deleting node data = %d and it's parent node data = %d\n",nodeToBeDeleted->data,parentNode->data);
    }

    //*CASE 2: If the node to be deleted is a leaf node.
    if(nodeToBeDeleted->left==NULL && nodeToBeDeleted->right==NULL){
        if(nodeToBeDeleted==parentNode->left) parentNode->left=NULL;
        else parentNode->right=NULL;
        free(nodeToBeDeleted);
    }

    //*CASE 3: If the node to be deleted has only one child
    else if((nodeToBeDeleted->left!=NULL && nodeToBeDeleted->right==NULL)
            ||(nodeToBeDeleted->left==NULL && nodeToBeDeleted->right!=NULL)){
                //* If the node has left child node
                if(nodeToBeDeleted->right==NULL){
                    if(nodeToBeDeleted==parentNode->left) parentNode->left=nodeToBeDeleted->left;
                    else parentNode->right=nodeToBeDeleted->left;
                }
                //* If the node has right child node
                else{
                    if(nodeToBeDeleted==parentNode->left) parentNode->left=nodeToBeDeleted->right;
                    else parentNode->right=nodeToBeDeleted->right;
                }
            free(nodeToBeDeleted);
        }
    
    //*CASE 4: If node to be deleted has 2 children
    else{
        node IS=nodeToBeDeleted->right, ISP = nodeToBeDeleted;
        //? IS= inorder successor, ISP= inorder successor's parent.
        while(IS->left!=NULL){
            ISP=IS;
            IS=IS->left;
        }
        nodeToBeDeleted->data=IS->data;
        if(IS->left==NULL && IS->right==NULL){
            if(IS==ISP->left) ISP->left=NULL;
            else ISP->right=NULL;
        }else{
            if(IS==ISP->left) ISP->left=IS->right;
            else ISP->right=IS->right;
        }
        free(IS);
    }
    printf("Node deleted with data: %d\n",data);
    return R;
}

int heightOfTree(node R){
    if(R==NULL) return 0;
    
    int leftHeight=heightOfTree(R->left);
    int rightHeight=heightOfTree(R->right);

    if(leftHeight>rightHeight) return leftHeight+1;
    return rightHeight+1;
}


int main(){
    int choice,data;
    node root=NULL;

    while(1){
        printf("\n0.Exit\n1.Insert\n2.Display\n3.Search\n4.Delete\n5.Find height\nEnter your choice:");
        scanf("%d",&choice);

        switch(choice){
            case 0: exit(0);
            case 1: root=insertNewNode(root); break;
            case 2: displayTree(root); break;
            case 3: printf("Enter the data of the node to be searched:");
                    scanf("%d",&data);
                    if(root==NULL){
                        printf("Tree is empty\n");
                    }else if(root->data==data){
                        printf("Searching node data = %d and it is the root of the tree\n",root->data);
                    }else{
                        node nodeToBeSearched=NULL, parentNode=NULL;
                        nodeToBeSearched=searchNode(root,data,&parentNode);
                        if(nodeToBeSearched==NULL){
                            printf("Node with data = %d doesn't exist in the tree\n",data);
                        }else{
                        printf("Searching node data = %d and it's parent node data = %d\n",nodeToBeSearched->data,parentNode->data);
                        }
                    }
                    break;
            case 4: root = deleteNode(root);
                    displayTree(root);
                    break;
            case 5: printf("Height of the tree: %d\n",heightOfTree(root));
                    break;
            default: printf("Enter proper choice");
        }
    }
}