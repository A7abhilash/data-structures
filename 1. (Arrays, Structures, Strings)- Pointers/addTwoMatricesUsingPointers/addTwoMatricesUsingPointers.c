#include<stdio.h>

int addTwoMatricesUsingPointers(int [][],int [][],int,int);

void main(){
    int a[10][10],b[10][10],i,j,m,n;

    printf("Enter the size of matrix:\n");
    scanf("%d%d",&m,&n);
    printf("Enter the elements of first matrix:\n");
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);

    printf("Enter the elements of second matrix:\n");
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            scanf("%d",&b[i][j]);

    int c[10][10] = addTwoMatricesUsingPointers(a,b,m,n);

    printf("Sum of two matrices:\n");
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            scanf("%d",&c[i][j]);
}

int addTwoMatricesUsingPointers(int a[][],int b[][],int m,int n){
    int *ptr1=a,*ptr2=b,i,j,sum[10][10];
    int *ptr3=sum;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            // *(*(ptr3+i)+j) = *(*(ptr1+i)+j) + *(*(ptr2+i)+j);
    return a;
}