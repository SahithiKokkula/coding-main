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
    int n;
    int check=0;
    scanf("%d",&n);
    for(int i=2;i<=n/2+1;i++){
        if(prime(i)==1&&prime(n-i)==1){
            printf("Yes");
            check=1;
            break;
        }
    }
    if(check==0) printf("No");
    return 0;
}