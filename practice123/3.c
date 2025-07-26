#include<stdio.h>
int hcf(int a,int b){//a>b
    if(b==0) return a;
    return hcf(b,a%b);
}
int main(){
    int a=5;
    int b=10;
    printf("%d",hcf(b,a));
}
