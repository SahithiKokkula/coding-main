#include<stdio.h>
#include<string.h>
int main(){
    char str[100];
    gets(str);
    int size=0;
    while(str[size]!='\0'){
        size++;
    }
    char rev_str[100];
    for(int i=size-1,j=0;i>=0;i--,j++){
        rev_str[j]=str[i];
    }
    printf("Size of String = %d\nReversed String = ",size);
    int i=0;
    while(str[i]!='\0'){
        printf("%c",rev_str[i]);
        i++;
    }
    return 0;
}