#include<stdio.h>
int check_palindrome(char str[100]){
    int size=0;
    while(str[size]!='\0'){
        size++;
    }
    
    int check=1;
    for(int i=0,j=size-1;i<j;i++,j--){
        if(str[i]!=str[j]){
            check=0;
            break;
        }
    }
    return check;
}
int main(){
    char str[100];
    gets(str);
    int check=check_palindrome(str);
    if(check==1){
        printf("Palindrome");
    }
    else{
        printf("Not Palindrome");
    }
    return 0;
}