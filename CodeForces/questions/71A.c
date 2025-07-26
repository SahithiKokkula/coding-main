#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void intToStr(int num, char *str) {
    sprintf(str, "%d", num);
}
int main() {
    int n;
    scanf("%d",&n);
    char strings[n][101]; 
    char result[10];
    char lengthstr[10];
    int length;
    char result2[11];
    for(int i=0;i<n;i++){
        char text[101];
        scanf("%100s",text);
        length=strlen(text);
        if (length>10){
            intToStr(length-2, lengthstr);
            result[0]=text[0];
            result[1]='\0';
            strcat(result,lengthstr);
            strcpy(result2,result);
            result[0]=text[length-1];
            result[1]='\0';
            strcat(result2,result);
            strcpy(strings[i],result2);
        }
        else{
            strcpy(strings[i],text);
        }
        
    }

    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
    }

    return 0;
}