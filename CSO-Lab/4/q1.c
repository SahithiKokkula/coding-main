#include<stdio.h>
int min(int a,int b){
    if (a>b) return b;
    else return a;
}
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    int gcd=1;
    for(int i=min(a,b);i>0;i--){
        if(a%i==0&&b%i==0){
            gcd=i;
            break;
        }
    }
    int lcm=(a*b)/gcd;
    printf("GCD: %d\n",gcd);
    printf("LCM: %d",lcm);
    return 0;
}