#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main(){
    FILE* ptr=fopen("text2.txt","r"),*e=fopen("even.txt","w"),*o=fopen("odd.txt","w"),*p=fopen("prime.txt","w");
    char c;
    while((c=fgetc(ptr))!=EOF){
        int i=0;
        char arr[50];
        if(isdigit(c)){
            arr[i]=c;
            while((c=fgetc(ptr))!=EOF && isdigit(c)){
                arr[++i]=c;
            }
            int no=atoi(arr);
            fprintf(e,"%d\n",no);
        }

    }
}