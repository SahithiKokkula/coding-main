#include<stdio.h>
int mod(int n){
    return (n>0)?n:-n;
}
int main(){
    int n;
    scanf("%d",&n);
    n=mod(n);
    while(n>=0){
        if(n==0){
            printf("Divisible by 11");
            break;
        }
        if(n<10){
            printf("Not divisibe by 11");
            break;
        }
        int a=0,b=0;
        int i=1;
        while(n>0){
            if(i%2==0) a+=n%10;
            else b+=n%10;
            n/=10;
            i++;
        }
        n=mod(a-b);
        
    }
    return 0;
}