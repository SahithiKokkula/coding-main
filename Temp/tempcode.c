#include<stdio.h>
int main(){
    FILE * ptr =fopen("newfile.txt","r");
    if(ptr==NULL){
        printf("ERROR Occoured");
    }
    int string[100];
    fgets(&string,100,ptr);


    // char c;
    // while((c=fgetc(ptr))!=EOF){
    //     printf("%c",c);
    // }

    // char str[100];
    // gets(str);
    // fprintf(ptr,"\n%s",str);
    fclose(ptr);
    return 0;
}