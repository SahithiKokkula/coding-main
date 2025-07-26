#include<stdio.h>
int main(){
    char str[100];
    printf("Enter the string:"); 
    gets(str);
    FILE* ptr=fopen("myfile.txt","a");
    fgetc(ptr);
    
    fclose(ptr);
}