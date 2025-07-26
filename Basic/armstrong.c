#include<stdio.h>
int power(int a,int b){
    int ans=1;
    for(int i=1;i<=b;i++){
        ans*=a;
    }
    return ans;
}
int is_armstrong(int a){
    int tmp=a;
    int dgt=0;
    while(tmp>0){
        dgt+=1;
        tmp/=10;
    }
    tmp=a;
    int sum=0;
    
    while(tmp>0){
        sum+=power((tmp%10),dgt);
        tmp/=10;
    }
    if(sum==a) return 1;
    return 0;
}
int main(){
    for(int i=1;i<=500;i++){
        if(is_armstrong(i)==1) printf("%d ",i);
    }
    return 0;
}