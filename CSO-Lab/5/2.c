#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int rev=0;
    while(n>0){
        rev=rev*10+n%10;
        n/=10;
    }
    printf("%d",rev);
    return 0;
}