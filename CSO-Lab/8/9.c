#include<stdio.h>
#include<string.h>
int main(){
    char str1[100];
    gets(str1);
    char str2[100];
    gets(str2);
    char str3[100];
    gets(str3);
    strcat(str1,str2);
    strcat(str1,str3);
    printf("concatenated string is : ");
    puts(str1);
    return 0;
}