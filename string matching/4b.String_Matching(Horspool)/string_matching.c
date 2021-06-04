#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void shiftTable(char pattern[],int table[]){
	int m = strlen(pattern), i;
	
	for (i = 0; i < 128; i++){
		table[i] = m;
	}
	
	for (i = 0; i < m-1; i++){
		table[pattern[i]] = m - i - 1;
	}
}

int stringMatching(char text[],char pattern[]){
	int n = strlen(text);
	int m = strlen(pattern);

    int table[128];
	shiftTable(pattern, table);

	int i = m - 1;
	while(i<n){
		int k = 0;
		while(k<m && pattern[m-1-k]==text[i-k]){
			k++;
		}

		if(k==m){
			return i - m + 1;
		}
		i += table[text[i]];
	}
	return -1;
}

int main(){
    char text[100],pattern[100];
    
    printf("Enter the text: ");
    scanf(" %[^\n]s",text);

    printf("Enter the pattern to be matched: ");
    scanf(" %[^\n]s",pattern);

	int pos=stringMatching(text, pattern);

	if(pos!=-1){
		printf("Pattern matched at position: %d\n", (pos+1));
	}else{
		printf("Pattern not matched\n");
	}

	return 0;
}
