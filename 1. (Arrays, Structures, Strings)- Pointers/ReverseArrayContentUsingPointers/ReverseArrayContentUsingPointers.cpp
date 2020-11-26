#include<iostream>
using namespace std;

void reverse(int *arr,int n){
    for(int *start=arr,*end=arr+n-1;start<arr+n/2;start++,end--){   
        int temp=*start;
        *start=*end;
        *end=temp;
    }
}

int main(){
    int a[10],*ptr,n;
    cout<<"Enter the size of the array: \n";
    cin>>n;

    cout<<"Enter the array elements: \n";
    for(ptr=a;ptr<a+n;ptr++){
        cin>>*ptr;
    }
    cout<<"\nArray elements: \n";
    for(ptr=a;ptr<a+n;ptr++){
        cout<<*ptr<<" ";
    }
    
    reverse(a,n);

    cout<<"\nReversed Array elements: \n";
    for(ptr=a;ptr<a+n;ptr++){
        cout<<*ptr<<" ";
    }

    cout<<endl;

    return 0;
}