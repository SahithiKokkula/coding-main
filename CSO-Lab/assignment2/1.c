#include<stdio.h>
int main(){
    FILE * ptr;
    ptr=fopen("text1.txt","r");
    char c;
    while((c=fgetc(ptr))!=EOF){
        printf("%c",c);
    }
    fclose(ptr);
    return 0;
}