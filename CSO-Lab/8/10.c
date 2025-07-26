#include<stdio.h>
#include<string.h>
int main(){
    char str[100];
    gets(str);
    int i=0;
    int j=0;
    int k=0;
    char split[50][100];
    while (str[i-1]!='\0'){
        if(str[i]==' '||str[i]=='\0'){
            split[j][k]='\0';
            j++;
            k=0;
        }
        else{
            split[j][k++]=str[i];
        }
        i++;
    }
    for(int i=0;i<j;i++){
        printf("%s \n",split[i]);
    }
    return 0;
}