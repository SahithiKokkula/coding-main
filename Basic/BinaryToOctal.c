#include<stdio.h>
#include<math.h>
int main(){
    unsigned int bin;
    scanf("%u",&bin);
    unsigned int decimal=0;
    int i=0;
    while(bin>0){
        decimal+=(bin%10)*pow(2,i++);
        bin/=10;
    }
    printf("%u",decimal);
    unsigned int oct=0;
    i=0;
    while(decimal>0){
        oct+=(decimal%8)*pow(10,i++);
        decimal/=8;
    }
    printf("\n%u",oct);
}