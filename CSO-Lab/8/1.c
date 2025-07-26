#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(){
    char str[100];
    gets(str);
    int i=0;
    while (str[i]!='\0'){
        if(isupper(str[i])){
            str[i]=(int)str[i]+32;
        }
        else if(islower(str[i])){
            str[i]=(int)str[i]-32;
        }
        i++;
    }
    puts(str);
    return 0;
}