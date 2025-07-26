#include<stdio.h>
#include<string.h>
int main(){
    char str[100];
    gets(str);
    int freq[124];
    for(int i=0;i<124;i++){
        freq[i]=0;
    }
    int i=0;
    while (str[i]!='\0'){
        freq[(int)str[i]]++;
        i++;
    }
    for(int i=0;i<124;i++){
        if(freq[i]>1){
            printf("%c ",(char)i);
        }
    }
    return 0;
}