#include<stdio.h>
int main(){
    char filename[50];
    char str[100];
    gets(filename);
    gets(str);
    FILE*ptr=fopen(filename,"a");
    fprintf(ptr,"\n%s",str);
    fclose(ptr);
    return 0;
}