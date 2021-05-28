#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void stringMatch(char T[],char P[]){
    int m=strlen(P);
    int n=strlen(T);
    int pos=-1,count=0,i,j;
    
    for(i=0;i<=n-m;i++){
        for(j=0;j<m;j++){
            count++;
            if(P[j]==T[i+j]) continue;
            else break;
        }
        if(j==m){
            pos= i;
            break;
        }
    }
    if(pos!=-1){
        printf("String pattern found from position: %d to %d\n",pos+1,pos+m);   
        printf("Count: %d\n",count);
    }else{
        printf("Pattern match not found!!!");   
    }
}

int main(){
    char text[100],pattern[100];
    
    printf("Enter the text: ");
    scanf(" %[^\n]s",text);

    printf("Enter the pattern to be matched: ");
    scanf(" %[^\n]s",pattern);


    stringMatch(text,pattern);

    return 0;
}
