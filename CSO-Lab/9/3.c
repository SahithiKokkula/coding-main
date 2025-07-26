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
    int num;
    scanf("%d",&num);
    if(prime(num)) printf("Prime");
    else printf("Not Prime");
    return 0;
}