#include<stdio.h>
int power(int n,int r){
    int ans=1;
    for(int i=0;i<r;i++){
        ans*=n;
    }
    return ans;
}
int main(){
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    printf("Sum of 9+99+999+....till n terms: %d",(power(10,n)-1)*10/9-n);
    return 0;
}