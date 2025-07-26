#include<stdio.h>
int main(){
    printf("start");
    FILE * ptr=fopen("text1.txt","r");
    char str1[50];
    gets(str1);
    char c;
    while((c=fgetc(ptr))!=EOF){
        char str2[50];int i=0;
        if(c!=' '){
            str2[i]=
        }
    }
    return 0;
}