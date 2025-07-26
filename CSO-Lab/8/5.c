#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(){
    char str[100];
    gets(str);
    int i=0;
    int alphabets=0;
    int digits=0;
    int splcharacter=0;
    while (str[i]!='\0'){
        if(isdigit(str[i])){
            digits++;
        }
        else if(isalpha(str[i])){
            alphabets++;
        }
        else{
            splcharacter++;
        }
        i++;
    }
    printf("Number of Digits= %d\nNumber of Alphabets= %d\nNumber of Special Character= %d",digits,alphabets,splcharacter);
    return 0;
}