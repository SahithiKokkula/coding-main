#include<stdio.h>
int main(){
    FILE*ptr=fopen("text1.txt","r");
    int c=0,w=1,l=1;
    char ch;
    while((ch=fgetc(ptr))!=EOF){
        c++;
        if(ch == ' ') w++;
        if(ch=='\n'){
            l++;
            w++;
        };
    }
    printf("%d %d %d",c,w,l);
    fclose(ptr);
    return 0;
}