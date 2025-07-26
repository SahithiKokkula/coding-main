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
    int i=0;
    int check=1;
    while (str[i]!='\0'){
        if(str[i]!=rev_str[i]){
            check=0;
            break;
        }
        i++;
    }
    
    if(check==1){
        printf("Palindrome");
    }
    else{
        printf("Not Palindrome");
    }
    return 0;
}