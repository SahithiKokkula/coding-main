#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int digits=0;
    while(n>0){
        digits+=1;
        n/=10;
    }
    printf("%d",digits);
    return 0;
}