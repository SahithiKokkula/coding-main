#include<stdio.h>
int main(){
    int a=0,b=1;
    int fibo[10];
    fibo[0]=0;
    fibo[1]=1;
    for(int i=2;i<10;i++){
        fibo[i]=fibo[i-1]+fibo[i-2];
    }
    for(int i=0;i<10;i++){
        printf("%d ",fibo[i]);
    }
    return 0;
}