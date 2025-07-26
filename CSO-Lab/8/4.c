#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(){
    char str[100];
    gets(str);
    int i=0;
    int consonent =0;
    int vovels=0;
    while (str[i]!='\0'){
        if(tolower(str[i])=='a'||tolower(str[i])=='e'||tolower(str[i])=='i'||tolower(str[i])=='o'||tolower(str[i])=='u'){
            vovels++;
        }
        else{
            consonent++;
        }
        i++;
    }
    printf("Number of Vovels= %d\nNumber of Consonents= %d",vovels,consonent);
    return 0;
}