#include <stdio.h>
#include <stdlib.h>

int factorialOfN(int n){
    if(n==1) return 1;
    return n*factorialOfN(n-1);
}

int fibanocciOfN(int n){
    if(n==0) return 1;
    if(n==1) return 2;
    return fibanocciOfN(n-2)+fibanocciOfN(n-1);
}

int smallestOfArrayElements(int a[],int n){
    if(n==0) return a[n];
    int small = smallestOfArrayElements(a,n-1);
    if(a[n] < small) return a[n];
    return small;
}

int productOfArrayElements(int a[],int n){
    if(n<0) return 1;
    return a[n]*productOfArrayElements(a,n-1);
}

int count=0;
void towerOfHanoi(int n,char S[], char T[],char D[]){
    if(n==1){
        printf("%d.Move %d from %s to %s\n",++count,n,S,D);
        return;
    }
    towerOfHanoi(n-1,S,D,T);
    printf("%d.Move %d from %s to %s\n",++count,n,S,D);
    towerOfHanoi(n-1,T,S,D);
}

int main(){
    int choice;
    int i,n,a[20];

    while(1){
        printf("\n0.Exit\n1.Factorial of n\n2.Fibanocci of n\n3.Smallest element in array\n4.Product of array elements\n5.Tower of Hanoi\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 0: exit(0);
            case 1: printf("Enter n value: ");
                    scanf("%d",&n);
                    printf("Factorial: %d\n",factorialOfN(n));
                    break;
            case 2: printf("Enter n value: ");
                    scanf("%d",&n);
                    printf("Fibanocci: %d\n",fibanocciOfN(n));
                    break;
            case 3: printf("Enter the size: ");
                    scanf("%d",&n);
                    printf("Enter the array elements:\n");
                    for(i=0;i<n;i++) 
                        scanf("%d",&a[i]);
                    printf("Smallest element: %d\n",smallestOfArrayElements(a,n-1));
                    break;
            case 4: printf("Enter the size: ");
                    scanf("%d",&n);
                    printf("Enter the array elements:\n");
                    for(i=0;i<n;i++) 
                        scanf("%d",&a[i]);
                    printf("Product: %d\n",productOfArrayElements(a,n-1));
                    break;
            case 5: printf("Enter the disk size: ");
                    scanf("%d",&n);
                    count=0;
                    towerOfHanoi(n,"Source","Temp","Destination");
                    break;
            default: printf("Enter proper choice\n");
        }
    }
    return 0;
}