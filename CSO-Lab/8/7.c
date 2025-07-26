#include<stdio.h>
#include<string.h>
int main(){
    char str[100];
    gets(str);
    int freq[256];
    for(int i=0;i<256;i++){
        freq[i]=0;
    }
    int i=0;
    while (str[i]!='\0'){
        freq[(int)str[i]]++;
        i++;
    }
    int max=0;
    for(int i=0;i<256;i++){
        if(freq[i]>freq[max]){
            max =i;
        }
    }
    i=0;
    while (str[i]!='\0'){
        if((int)str[i]==max){
            str[i]='*';
        }
        i++;
    }
    printf("Newly formed string is: ");
    puts(str);
    return 0;
}