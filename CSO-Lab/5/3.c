#include<stdio.h>
int prime(int n){
    for(int i=2;i<n;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}
int main(){
    int l,h;
    scanf("%d %d",&l,&h);
    for(int i=l;i<=h;i++){
        if(prime(i)==1){
            printf("%d ",i);
        }
    }
    return 0;
}